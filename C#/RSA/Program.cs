using System.Diagnostics;
using Services;

#region Factorization
Console.WriteLine("---Factorization---");
long number = 11021;
Console.WriteLine($"Number: {number}");

Stopwatch stopwatch = new();

stopwatch.Start();
long multiThreaded = Factorizer.SmallestOddFactorInRangeMultiThreaded(number, 2, number);
stopwatch.Stop();
Console.WriteLine($"Multi-threaded: {multiThreaded} ({stopwatch.ElapsedMilliseconds}ms)");

stopwatch.Restart();
long singleThreaded = Factorizer.SmallestOddFactorInRangeSingleThreaded(number, 2, number);
stopwatch.Stop();
Console.WriteLine($"Single-threaded: {singleThreaded} ({stopwatch.ElapsedMilliseconds}ms)");
#endregion

#region RSA Key Generation
Console.WriteLine("\n---RSA Key Generation---");
(long exponent1, long exponent2, long product) = RsaUtil.GenerateKeys();
Console.WriteLine($"Exponent 1: {exponent1}");
Console.WriteLine($"Exponent 2: {exponent2}");
Console.WriteLine($"Product: {product}");

Console.WriteLine("\n---RSA Encryption and Decryption---");
long message = 1234;
Console.WriteLine($"Message: {message}");

long encrypted = RsaUtil.Encrypt(message, exponent1, product);
Console.WriteLine($"Encrypted: {encrypted}");

long decrypted = RsaUtil.Encrypt(encrypted, exponent2, product);
Console.WriteLine($"Decrypted: {decrypted}");
#endregion

#region RSA Brute Force
Console.WriteLine("\n---RSA Brute Force---");
Console.WriteLine($"Known exponent: {exponent1}");
long otherExponent = RsaBruteForce.FindOtherExponent(exponent1, product);
Console.WriteLine($"Other exponent: {otherExponent}");
#endregion
