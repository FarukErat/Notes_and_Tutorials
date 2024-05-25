namespace Services;

public static class Factorizer
{
    public static long SmallestOddFactorInRangeSingleThreaded(long number, long lowerBound = 3, long upperBound = long.MaxValue)
    {
        if (number < 2
            || lowerBound < 2
            || upperBound < 2
            || lowerBound > upperBound
            || number < lowerBound
            || number > upperBound)
        {
            return 0;
        }

        if (upperBound > number)
        {
            upperBound = number;
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
        if (number < 2
            || number == long.MaxValue // due to the "toExclusive: upperBound + 1" in Parallel.For loop
            || lowerBound < 2
            || upperBound < 2
            || lowerBound > upperBound
            || number < lowerBound
            || number > upperBound)
        {
            return 0;
        }

        if (upperBound > number)
        {
            upperBound = number;
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
