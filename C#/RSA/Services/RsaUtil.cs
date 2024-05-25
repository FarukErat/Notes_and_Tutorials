using static Configurations.Config;

namespace Services;

public static class RsaUtil
{
    private static long GCD(long a, long b)
    {
        while (b != 0)
        {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    private static long ModExp(long baseValue, long exponent, long modulus)
    {
        long result = 1;
        baseValue %= modulus;
        while (exponent > 0)
        {
            if ((exponent & 1) == 1)
            {
                result = (result * baseValue) % modulus;
            }
            exponent >>= 1;
            baseValue = (baseValue * baseValue) % modulus;
        }
        return result;
    }

    private static long ModInverse(long a, long m)
    {
        long m0 = m, t, q;
        long x0 = 0, x1 = 1;
        if (m == 1)
        {
            return 0;
        }
        while (a > 1)
        {
            q = a / m;
            t = m;
            m = a % m;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0)
        {
            x1 += m0;
        }
        return x1;
    }

    private static bool IsPrime(long n)
    {
        if (n <= 1)
        {
            return false;
        }
        if (n <= 3)
        {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0)
        {
            return false;
        }

        double sqrtN = Math.Sqrt(n);
        for (long i = 5; i <= sqrtN; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }

        return true;
    }

    private static long GeneratePrime()
    {
        Random rnd = new();
        while (true)
        {
            long num = rnd.Next((int)MinValue, (int)MaxValue);
            if (IsPrime(num))
            {
                return num;
            }
        }
    }

    public static (long exponent1, long exponent2, long product) GenerateKeys()
    {
        // Generate two large prime numbers p and q
        long prime1 = GeneratePrime();
        long prime2 = GeneratePrime();
        while (prime2 == prime1)
        {
            prime2 = GeneratePrime();
        }
        long product = prime1 * prime2;
        long phi = (prime1 - 1) * (prime2 - 1);

        // Choose e such that 1 < e < phi and GCD(e, phi) = 1
        long exponent1 = GeneratePrime();
        while (GCD(exponent1, phi) != 1)
        {
            exponent1 += 2;
        }

        // Calculate d such that d*e ≡ 1 (mod phi)
        long exponent2 = ModInverse(exponent1, phi);

        return (exponent1, exponent2, product);
    }

    public static long Encrypt(long message, long exponent, long modulus)
    {
        return ModExp(message, exponent, modulus);
    }

    public static long Decrypt(long encryptedMessage, long exponent, long modulus)
    {
        return ModExp(encryptedMessage, exponent, modulus);
    }
}
