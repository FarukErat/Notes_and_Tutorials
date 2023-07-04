using Microsoft.AspNetCore.Mvc;
using System.Security.Cryptography;

namespace HashWithBcrypt.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class BcryptController : ControllerBase
    {
        const UInt16 _rounds = 12;

        // POST api/bcrypt/hash
        [HttpPost("hash")]
        public IActionResult HashPassword([FromBody] PasswordRequest request)
        {
            string hashedPassword = HashPassword(request.Password);
            return Ok(hashedPassword);
        }

        // POST api/bcrypt/verify
        [HttpPost("verify")]
        public IActionResult VerifyPassword([FromBody] VerifyRequest request)
        {
            bool passwordMatch = VerifyPassword(request.Password, request.HashedPassword);
            return Ok(passwordMatch);
        }

        public static string HashPassword(string password)
        {
            // Generate a random salt
            byte[] salt = new byte[16];
            using (var rng = new RNGCryptoServiceProvider())
            {
                rng.GetBytes(salt);
            }

            // Hash the password with the salt
            string hashedPassword = BCrypt.Net.BCrypt.HashPassword(password, BCrypt.Net.BCrypt.GenerateSalt(_rounds));

            return hashedPassword;
        }

        public static bool VerifyPassword(string password, string hashedPassword)
        {
            bool passwordMatch = BCrypt.Net.BCrypt.Verify(password, hashedPassword);
            return passwordMatch;
        }
    }

    public class PasswordRequest
    {
        public string Password { get; set; }
    }

    public class VerifyRequest
    {
        public string Password { get; set; }
        public string HashedPassword { get; set; }
    }
}
