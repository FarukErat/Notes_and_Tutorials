using System.Text;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;
using Serilog;
using WorkoutProject.Models;
using WorkoutProject.Services;

namespace WorkoutProject
{
    public class Startup
    {
        public IConfiguration Configuration { get; }

        public Startup(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public void ConfigureServices(IServiceCollection services)
        {
            services.Configure<MongoDBSettingsModel>(Configuration.GetSection("MongoDB"));

            // Dependency injection
            services.AddSingleton<IMongoDBService, MongoDBService>();
            services.AddSingleton<IAuthenticationService, AuthenticationService>();
            services.AddSingleton<IJwtService>(new JwtService(
                "https://localhost:5001",
                "https://localhost:5001",
                Environment.GetEnvironmentVariable("JwtIssuerSigningKey")!
                ));

            // Rules for JWT authorization [Authorize]
            services.AddAuthentication(options =>
            {
                options.DefaultAuthenticateScheme = JwtBearerDefaults.AuthenticationScheme;
                options.DefaultChallengeScheme = JwtBearerDefaults.AuthenticationScheme;
            }).AddJwtBearer(options =>
            {
                options.RequireHttpsMetadata = true;
                options.SaveToken = true;
                options.TokenValidationParameters = new TokenValidationParameters
                {
                    ValidateIssuer = true,
                    ValidIssuer = "https://localhost:5001",

                    ValidateAudience = true,
                    ValidAudience = "https://localhost:5001",

                    ValidateIssuerSigningKey = true,
                    IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(
                        Environment.GetEnvironmentVariable("JwtIssuerSigningKey")!
                    )),

                    ValidateLifetime = true,
                    ClockSkew = TimeSpan.Zero
                };
            });

            Log.Logger = new LoggerConfiguration()
            .MinimumLevel.Debug()
            .WriteTo.File("logs/log.txt", rollingInterval: RollingInterval.Day)
            .CreateLogger();

            services.AddControllers();
            services.AddEndpointsApiExplorer();
            services.AddSwaggerGen();
        }

        public void Configure(WebApplication app)
        {
            if (app.Environment.IsDevelopment())
            {
                app.UseSwagger();
                app.UseSwaggerUI();
            }

            app.UseHttpsRedirection();

            app.UseAuthentication();

            app.UseAuthorization();

            app.MapControllers();

            app.Run();
        }
    }
}
