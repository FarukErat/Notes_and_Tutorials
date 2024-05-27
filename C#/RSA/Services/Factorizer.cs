namespace Services;

public static class Factorizer
{
    public static long SmallestOddFactorInRangeSingleThreaded(long number, long lowerBound = 3, long upperBound = long.MaxValue)
    {
        if (number < 2
            || lowerBound > upperBound
            || number < lowerBound)
        {
            return 0;
        }

        if (lowerBound < 3
            || upperBound < 3)
        {
            lowerBound = 3;
            upperBound = number;
        }

        if (upperBound >= number)
        {
            upperBound = number - 1;
        }

        if (lowerBound % 2 == 0)
        {
            ++lowerBound;
        }

        for (long i = lowerBound; i <= upperBound; i += 2)
        {
            if (number % i == 0)
            {
                return i;
            }
        }

        return 0;
    }

    public static long SmallestOddFactorInRangeMultiThreaded(long number, long lowerBound, long upperBound)
    {
        // 9223372036854775783
        if (number < 2
            || number == long.MaxValue // due to the "toExclusive: upperBound + 1" in Parallel.For loop
            || lowerBound > upperBound
            || number < lowerBound)
        {
            return 0;
        }

        if (lowerBound < 3
            || upperBound < 3)
        {
            lowerBound = 3;
            upperBound = number;
        }

        if (upperBound >= number)
        {
            upperBound = number - 1;
        }

        if (lowerBound % 2 == 0)
        {
            ++lowerBound;
        }

        long result = 0;
        Parallel.For(
            fromInclusive: lowerBound,
            toExclusive: upperBound + 1,
            body: (i, state) =>
            {
                if (number % i == 0 && (result == 0 || i < result))
                {
                    result = i;
                    state.Stop();
                }
            }
        );

        return result;
    }
}
