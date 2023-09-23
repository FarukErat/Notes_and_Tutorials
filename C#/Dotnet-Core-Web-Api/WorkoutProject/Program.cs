DotNetEnv.Env.Load();

var builder = WebApplication.CreateBuilder(args);
var startup = new WorkoutProject.Startup(builder.Configuration);
startup.ConfigureServices(builder.Services);
var app = builder.Build();
startup.Configure(app);
