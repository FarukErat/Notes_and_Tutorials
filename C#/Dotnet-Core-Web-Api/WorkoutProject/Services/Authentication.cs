using WorkoutProject.Dtos;
using WorkoutProject.Models;

namespace WorkoutProject.Services;

public class AuthenticationService : IAuthenticationService
{
    private readonly IMongoDBService _mongoDBService;
    private readonly IJwtService _jwtService;
    private readonly IPasswordManager _passwordManager;

    public AuthenticationService(
        IMongoDBService mongoDBService,
        IJwtService jwtService,
        IPasswordManager passwordManager)
    {
        _mongoDBService = mongoDBService;
        _jwtService = jwtService;
        _passwordManager = passwordManager;
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
            PasswordHash = _passwordManager.HashPassword(request.Password),
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

        var validPassword = _passwordManager.VerifyPassword(request.Password, existingUser.PasswordHash);
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