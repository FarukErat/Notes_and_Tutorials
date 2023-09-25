using Konscious.Security.Cryptography;
using System.Security.Cryptography;
using System.Text;

namespace WorkoutProject.Services;

public class Argon2idPass : IPasswordManager
{
    private readonly int degreeOfParallelism = 4;
    private readonly int memorySize = 65536; // 2^16
    private readonly int iterations = 4;

    public string HashPassword(string password)
    {
        // Generate a random salt
        byte[] salt = new byte[16];
        using (var rng = RandomNumberGenerator.Create())
        {
            rng.GetBytes(salt);
        }

        // Hash the password with Argon2id
        using (var hasher = new Argon2id(Encoding.UTF8.GetBytes(password)))
        {
            hasher.Salt = salt;
            hasher.DegreeOfParallelism = degreeOfParallelism;
            hasher.MemorySize = memorySize;
            hasher.Iterations = iterations;

            byte[] hashBytes = hasher.GetBytes(32); // 32 bytes is a common hash size
            byte[] saltPlusHash = new byte[salt.Length + hashBytes.Length];
            Buffer.BlockCopy(salt, 0, saltPlusHash, 0, salt.Length);
            Buffer.BlockCopy(hashBytes, 0, saltPlusHash, salt.Length, hashBytes.Length);

            return Convert.ToBase64String(saltPlusHash);
        }
    }

    public bool VerifyPassword(string password, string passwordHash)
    {
        try
        {
            byte[] saltPlusHash = Convert.FromBase64String(passwordHash);

            byte[] salt = new byte[16];
            byte[] hashBytes = new byte[saltPlusHash.Length - 16];
            Buffer.BlockCopy(saltPlusHash, 0, salt, 0, salt.Length);
            Buffer.BlockCopy(saltPlusHash, salt.Length, hashBytes, 0, hashBytes.Length);

            using (var hasher = new Argon2id(Encoding.UTF8.GetBytes(password)))
            {
                hasher.Salt = salt;
                hasher.DegreeOfParallelism = degreeOfParallelism;
                hasher.MemorySize = memorySize;
                hasher.Iterations = iterations;

                byte[] computedHashBytes = hasher.GetBytes(32); // 32 bytes is a common hash size

                // Compare the computed hash with the stored hash
                for (int i = 0; i < computedHashBytes.Length; i++)
                {
                    if (computedHashBytes[i] != hashBytes[i])
                    {
                        return false; // Passwords don't match
                    }
                }

                return true; // Passwords match
            }
        }
        catch
        {
            return false; // Invalid hash format
        }
    }
}

