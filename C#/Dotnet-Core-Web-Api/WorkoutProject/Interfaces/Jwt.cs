using System.Security.Claims;
using WorkoutProject.Models;

public interface IJwtService
{
    string GenerateJwtToken(UserModel user);
    public ClaimsPrincipal ValidateJwtToken(string token);
}
