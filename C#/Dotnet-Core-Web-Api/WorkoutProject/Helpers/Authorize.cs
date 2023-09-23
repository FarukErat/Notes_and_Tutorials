using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Filters;
using System.Security.Claims;
using WorkoutProject.Models;
using WorkoutProject.Services;

namespace WorkoutProject.Helpers;

[AttributeUsage(AttributeTargets.Class | AttributeTargets.Method)]
public class CustomAuthorizeAttribute : TypeFilterAttribute
{
    public CustomAuthorizeAttribute(string roles, string policy) : base(typeof(CustomAuthorizeFilter))
    {
        Arguments = new object[] { roles, policy };
    }
}

public class CustomAuthorizeFilter : IAsyncAuthorizationFilter
{
    private readonly string _roles;
    private readonly string _policy;
    private readonly IMongoDBService _mongoDBService;
    private readonly IJwtService _jwtService;

    public CustomAuthorizeFilter(string roles, string policy, IMongoDBService mongoDBService, IJwtService jwtService)
    {
        _roles = roles;
        _policy = policy;
        _mongoDBService = mongoDBService;
        _jwtService = jwtService;
    }

    public async Task OnAuthorizationAsync(AuthorizationFilterContext context)
    {
        var authorizationHeader = context.HttpContext.Request.Headers["Authorization"].ToString();
        if (string.IsNullOrEmpty(authorizationHeader) || !authorizationHeader.StartsWith("Bearer "))
        {
            context.Result = new UnauthorizedObjectResult(new { error = "Authorization token required" });
            return;
        }

        var token = authorizationHeader.Split(' ')[1];

        try
        {
            ClaimsPrincipal claimsPrincipal = _jwtService.ValidateJwtToken(token);

            var user = (UserModel?)context.HttpContext.Items["User"];
            if (user == null)
            {
                var username = claimsPrincipal.FindFirst("username")?.Value;
                user = await _mongoDBService.FindByUsernameAsync(username!);
            }

            if (user == null)
            {
                context.Result = new ForbidResult();
                return;
            }

            if (!string.IsNullOrEmpty(_roles))
            {
                var userRoles = _roles.Split(',');
                bool isAuthorized = false;
                foreach (var role in userRoles)
                {
                    if (user.Role == role.Trim())
                    {
                        isAuthorized = true;
                        break;
                    }
                }

                if (!isAuthorized)
                {
                    context.Result = new ForbidResult();
                    return;
                }
            }

            if (!string.IsNullOrEmpty(_policy))
            {
                var authorized = context.HttpContext.User.HasClaim(ClaimTypes.Role, _policy);
                if (!authorized)
                {
                    context.Result = new ForbidResult();
                    return;
                }
            }

            context.HttpContext.Items["User"] = user;
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex);
            context.Result = new UnauthorizedObjectResult(new { error = "Request is not authorized" });
        }
    }
}

