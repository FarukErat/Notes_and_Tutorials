using MassTransit;
using Services;

namespace Slaves;

public sealed record class FactorizationRequest(long Number, long LowerBound, long UpperBound);
public sealed record class FactorizationResponse(bool IsFound, long Factor);

public sealed class FactorizationConsumer : IConsumer<FactorizationRequest>
{
    public async Task Consume(ConsumeContext<FactorizationRequest> context)
    {
        long result = Factorizer.SmallestOddFactorInRangeMultiThreaded(
            number: context.Message.Number,
            lowerBound: context.Message.LowerBound,
            upperBound: context.Message.UpperBound);

        await context.RespondAsync(new FactorizationResponse(
                IsFound: result != 0,
                Factor: result));
    }
}
