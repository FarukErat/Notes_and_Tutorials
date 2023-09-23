using WorkoutProject.Dtos;
using WorkoutProject.Models;

namespace WorkoutProject.Services;

public class AuthenticationService : IAuthenticationService
{
    private readonly IMongoDBService _mongoDBService;
    private readonly IJwtService _jwtService;

    public AuthenticationService(IMongoDBService mongoDBService, IJwtService jwtService)
    {
        _mongoDBService = mongoDBService;
        _jwtService = jwtService;
    }
    public async Task<SignupResponseDto> SignUpAsync(SignupRequestDto request)
    {
        var existingUser = await _mongoDBService.FindByUsernameAsync(request.Username);
        if (existingUser != null)
        {
            throw new Exception("Username taken.");
        }

        var user = new UserModel
        {
            Username = request.Username,
            PasswordHash = BCrypt.Net.BCrypt.HashPassword(request.Password, workFactor: 12),
            Role = "NewUser"
        };
        await _mongoDBService.CreateAsync(user);

        var response = new SignupResponseDto
        {
            Username = user.Username,
            Token = _jwtService.GenerateJwtToken(user)
        };
        return response;
    }

    public async Task<LoginResponseDto> LoginAsync(LoginRequestDto request)
    {
        var existingUser = await _mongoDBService.FindByUsernameAsync(request.Username);
        if (existingUser == null)
        {
            throw new Exception("User not found.");
        }

        var validPassword = BCrypt.Net.BCrypt.Verify(request.Password, existingUser.PasswordHash);
        if (!validPassword)
        {
            throw new Exception("Invalid password.");
        }

        var response = new LoginResponseDto
        {
            Username = existingUser.Username,
            Token = _jwtService.GenerateJwtToken(existingUser)
        };
        return response;
    }
}