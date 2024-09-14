using System.Numerics;
using Services;

BigInteger message = 123456789;
Console.WriteLine($"Message: {message}\n");

(BigInteger product, BigInteger exponent1, BigInteger exponent2) = Factorization.GenerateKeys();

Console.WriteLine($"Product: {product}");
Console.WriteLine($"Exponent1: {exponent1}");
Console.WriteLine($"Exponent2: {exponent2}\n");

BigInteger encrypted = Factorization.Encrypt(message, product, exponent1);
BigInteger decrypted = Factorization.Encrypt(encrypted, product, exponent2);

Console.WriteLine($"Encrypted with exponent1: {encrypted}");
Console.WriteLine($"Decrypted with exponent2: {decrypted}\n");

encrypted = Factorization.Encrypt(message, product, exponent2);
decrypted = Factorization.Encrypt(encrypted, product, exponent1);

Console.WriteLine($"Encrypted with exponent2: {encrypted}");
Console.WriteLine($"Decrypted with exponent1: {decrypted}\n");
