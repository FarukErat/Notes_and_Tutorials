namespace Configurations;

public static class Config
{
    public const long MinPrime = 1000;
    public const long MaxPrime = 10000;
    public static readonly string RabbitMQHost;
    public static readonly string RabbitMQUsername;
    public static readonly string RabbitMQPassword;
    public static readonly string WebHook;

    static Config()
    {
        RabbitMQHost = Environment.GetEnvironmentVariable("RABBITMQ_HOST")
            ?? throw new ArgumentNullException("RABBITMQ_HOST is not set in the environment variables.");
        RabbitMQUsername = Environment.GetEnvironmentVariable("RABBITMQ_USERNAME")
            ?? throw new ArgumentNullException("RABBITMQ_USERNAME is not set in the environment variables.");
        RabbitMQPassword = Environment.GetEnvironmentVariable("RABBITMQ_PASSWORD")
            ?? throw new ArgumentNullException("RABBITMQ_PASSWORD is not set in the environment variables.");
        string webHookHost = Environment.GetEnvironmentVariable("WEB_HOOK_HOST")
            ?? throw new ArgumentNullException("WEB_HOOK_HOST is not set in the environment variables.");
        WebHook = $"http://{webHookHost}/rsa/factorization-result?result=";
    }
}
