using System.Diagnostics;
using static Services.Factorization;

if (args.Length != 2)
{
    Console.WriteLine("Invalid arguments");
    return;
}

if (!long.TryParse(args[1], out long number))
{
    Console.WriteLine("Invalid number");
    return;
}

Stopwatch stopwatch = new();
stopwatch.Start();
switch (args[0])
{
    case "isprime":
        Console.WriteLine("{0} is {1}prime", number, IsPrime(number) ? "" : "not ");
        break;
    case "factorize":
        Console.WriteLine($"Prime factors of {number}:");
        PrintFactors(Factorize(number));
        break;
    case "primes":
        Console.WriteLine($"Primes up to {number}:");
        PrintPrimes(Primes(number));
        break;
    default:
        Console.WriteLine("Invalid command");
        return;
}
stopwatch.Stop();
Console.WriteLine($"Elapsed ms: {stopwatch.ElapsedMilliseconds}");

static void PrintFactors(List<(long prime, short exponent)> factors)
{
    foreach ((long prime, short exponent) in factors)
    {
        Console.Write($"{prime}");
        if (exponent > 1)
        {
            Console.Write($" ^ {exponent}");
        }
        Console.WriteLine();
    }
}

static void PrintPrimes(List<long> primes)
{
    foreach (long prime in primes)
    {
        Console.WriteLine(prime);
    }
}
