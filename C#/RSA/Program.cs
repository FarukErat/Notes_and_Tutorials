using Consumers;
using MassTransit;
using static Configurations.Config;

WebApplicationBuilder builder = WebApplication.CreateBuilder(args);
builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddMassTransit(x =>
{
    x.AddConsumer<FactorizationConsumer>();
    x.SetKebabCaseEndpointNameFormatter();

    x.UsingRabbitMq((context, cfg) =>
    {
        cfg.Host(RabbitMQHost, h =>
        {
            h.Username(RabbitMQUsername);
            h.Password(RabbitMQPassword);
        });

        cfg.ConfigureEndpoints(context);
    });
});


WebApplication app = builder.Build();
// app.UseSwagger();
// app.UseSwaggerUI();
app.MapControllers();

app.Run();
