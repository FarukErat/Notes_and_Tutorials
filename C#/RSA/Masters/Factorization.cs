using MassTransit;
using Microsoft.Extensions.DependencyInjection;
using Slaves;

namespace Masters;

public static class Master
{
    private static readonly IBusControl _busControl;

    static Master()
    {
        IServiceCollection services = new ServiceCollection();
        services.AddMassTransit(x =>
        {
            x.AddConsumer<FactorizationConsumer>();
            x.SetKebabCaseEndpointNameFormatter();

            x.UsingRabbitMq((context, cfg) =>
            {
                cfg.Host("localhost", h =>
                {
                    h.Username("guest");
                    h.Password("guest");
                });

                cfg.ConfigureEndpoints(context);
            });
        });

        ServiceProvider serviceProvider = services.BuildServiceProvider();
        _busControl = serviceProvider.GetRequiredService<IBusControl>();
        _busControl.Start();
    }

    public static async Task SendFactorizationRequestAsync(long number, long lowerBound, long upperBound)
    {
        await _busControl.Publish(new FactorizationRequest(
            Number: number,
            LowerBound: lowerBound,
            UpperBound: upperBound));
    }
}
