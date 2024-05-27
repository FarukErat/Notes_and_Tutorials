namespace Services;

public static class RsaBruteForce
{
    public static long FindOtherExponent(long exponent1, long product)
    {
        long prime1 = Factorizer.SmallestOddFactorInRangeMultiThreaded(product, 2, product);
        long prime2 = product / prime1;
        long phi = (prime1 - 1) * (prime2 - 1);
        long exponent2 = ModInverse(exponent1, phi);
        return exponent2;
    }

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

    private static long ModInverse(long a, long m)
    {
        long m0 = m, t, q;
        long x0 = 0, x1 = 1;
        if (m == 1 || GCD(a, m) != 1)
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
}
