using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Serilog;
using WorkoutProject.Dtos;
using WorkoutProject.Helpers;
using WorkoutProject.Services;

namespace WorkoutProject.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class AuthenticationController : ControllerBase
    {
        private readonly IAuthenticationService _authenticationService;
        public AuthenticationController(IAuthenticationService authenticationService)
        {
            _authenticationService = authenticationService;
        }

        [HttpPost("signup")]
        public async Task<IActionResult> SignUp([FromBody] SignupRequestDto request)
        {
            try
            {
                var result = await _authenticationService.SignUpAsync(request);
                return Ok(result);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [HttpPost("login")]
        public async Task<IActionResult> Login([FromBody] LoginRequestDto request)
        {
            try
            {
                var result = await _authenticationService.LoginAsync(request);
                return Ok(result);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [Authorize]
        [HttpGet("secret-resource")]
        public IActionResult SecretResource()
        {
            return Ok("This is a secret resource");
        }

        [CustomAuthorize("NewUser", "")]
        [HttpGet("custom-auth")]
        public IActionResult CustomAuth()
        {
            return Ok("This is also a secret resource");
        }
    }
}
