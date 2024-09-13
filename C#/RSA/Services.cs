using System.Numerics;

namespace Services;

// 9_223_372_036_854_775_783 is the largest prime number that fits in a long (9223372036854775783)
// to test the performance of the IsPrime method

public static class Factorization
{
    public static bool IsPrime(BigInteger number)
    {
        if (number < 2)
        {
            return false;
        }

        if (number == 2 || number == 3)
        {
            return true;
        }

        if (number % 2 == 0 || number % 3 == 0)
        {
            return false;
        }

        BigInteger sqrtN = (BigInteger)Math.Sqrt((double)number);
        object lockObject = new();
        bool result = true;
        BigInteger count = sqrtN / 6 + 1; // +1 due to integer truncation

        Parallel.For(
            fromInclusive: 1, // 1 since the first candidate is 5
            toExclusive: (long)count + 1, // +1 due to exclusive upper bound
            parallelOptions: new ParallelOptions { MaxDegreeOfParallelism = Environment.ProcessorCount },
            body: (i, state) =>
            {
                BigInteger k1 = 6 * i - 1;
                BigInteger k2 = 6 * i + 1;

                if (result
                    && (number % k1 == 0 || number % k2 == 0)
                    && number != k1
                    && number != k2)
                {
                    lock (lockObject)
                    {
                        result = false;
                        state.Stop();
                    }
                }
            }
        );

        return result;
    }

    static BigInteger GetRandomPrime()
    {
        Random random = new();
        BigInteger number = random.Next(1, int.MaxValue);

        while (!IsPrime(number))
        {
            number = random.Next(1, int.MaxValue);
        }

        return number;
    }

    static BigInteger GCD(BigInteger a, BigInteger b)
    {
        while (b != 0)
        {
            BigInteger temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    static BigInteger ModularExponentiation(BigInteger number, BigInteger exponent, BigInteger modulus)
    {
        BigInteger result = 1;

        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * number) % modulus;
            }

            number = (number * number) % modulus;
            exponent /= 2;
        }

        return result;
    }

    static BigInteger ModularInverse(BigInteger a, BigInteger m)
    {
        BigInteger m0 = m;
        BigInteger y = 0, x = 1;

        if (m == 1)
            return 0;

        while (a > 1)
        {
            // q is quotient
            BigInteger q = a / m;
            BigInteger t = m;

            // m is remainder now, process same as Euclid's algorithm
            m = a % m;
            a = t;
            t = y;

            // Update x and y
            y = x - q * y;
            x = t;
        }

        // Make x positive
        if (x < 0)
            x += m0;

        return x;
    }

    public static (BigInteger product, BigInteger exponent1, BigInteger exponent2) GenerateKeys(){
        BigInteger prime1 = GetRandomPrime();
        BigInteger prime2 = GetRandomPrime();
        BigInteger product = prime1 * prime2;
        BigInteger phi = (prime1 - 1) * (prime2 - 1);

        // exponent1 must be coprime with phi
        BigInteger exponent1 = GetRandomPrime();
        while (GCD(exponent1, phi) != 1)
        {
            exponent1 = GetRandomPrime();
        }

        BigInteger exponent2 = ModularInverse(exponent1, phi);

        return (product, exponent1, exponent2);
    }

    public static BigInteger Encrypt(BigInteger message, BigInteger product, BigInteger exponent)
    {
        return ModularExponentiation(message, exponent, product);
    }

    public static BigInteger Decrypt(BigInteger encryptedMessage, BigInteger product, BigInteger exponent)
    {
        return ModularExponentiation(encryptedMessage, exponent, product);
    }
}
