using System.Security.Claims;
using WorkoutProject.Models;

namespace WorkoutProject.Services;

public interface IJwtService
{
    string GenerateJwtToken(UserModel user);
    public ClaimsPrincipal ValidateJwtToken(string token);
}
