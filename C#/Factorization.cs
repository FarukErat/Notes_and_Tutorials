namespace Services;

// 9_223_372_036_854_775_783 is the largest prime number that fits in a long
// to test the performance of the IsPrime method

public static class Factorization
{
    public static bool IsPrime(long number)
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

        long sqrtN = (long)Math.Sqrt(number);
        object lockObject = new();
        bool result = true;
        long count = sqrtN / 6 + 1; // +1 due to integer truncation

        Parallel.For(
            fromInclusive: 1, // 1 since the first candidate is 5
            toExclusive: count + 1, // +1 due to exclusive upper bound
            parallelOptions: new ParallelOptions { MaxDegreeOfParallelism = Environment.ProcessorCount },
            body: (i, state) =>
            {
                long k1 = 6 * i - 1;
                long k2 = 6 * i + 1;

                if (result
                    && (number % k1 == 0 || number % k2 == 0)
                    && (number != k1 && number != k2))
                {
                    lock (lockObject)
                    {
                        result = false;
                    }
                    state.Stop();
                }
            }
        );

        return result;
    }

    public static List<(long prime, short exponent)> Factorize(long number)
    {
        if (number < 2)
        {
            return [];
        }

        List<(long, short)> factors = [];
        short exponent = 0;
        while (number % 2 == 0)
        {
            number /= 2;
            exponent++;
        }
        if (exponent > 0)
        {
            factors.Add((2, exponent));
        }

        exponent = 0;
        while (number % 3 == 0)
        {
            number /= 3;
            exponent++;
        }
        if (exponent > 0)
        {
            factors.Add((3, exponent));
        }

        long i = 5;
        long sqrtN = (long)Math.Sqrt(number);
        while (number != 1)
        {
            exponent = 0;
            while (number % i == 0)
            {
                number /= i;
                exponent++;
            }
            if (exponent > 0)
            {
                factors.Add((i, exponent));
            }

            exponent = 0;
            while (number % (i + 2) == 0)
            {
                number /= i + 2;
                exponent++;
            }
            if (exponent > 0)
            {
                factors.Add((i + 2, exponent));
            }
            if (i >= sqrtN)
            {
                i = number;
            }
            else
            {
                i += 6;
            }
        }

        if (factors.Count == 0)
        {
            factors.Add((number, 1));
        }

        return factors;
    }

    public static List<long> Primes(long till)
    {
        if (till < 2)
        {
            return [];
        }

        if (till < 3)
        {
            return [2];
        }

        if (till < 5)
        {
            return [2, 3];
        }

        List<long> primes = [2, 3];
        for (long i = 5; i <= till; i += 6)
        {
            if (IsPrime(i))
            {
                primes.Add(i);
            }

            if (i + 2 <= till && IsPrime(i + 2))
            {
                primes.Add(i + 2);
            }
        }

        return primes;
    }
}
