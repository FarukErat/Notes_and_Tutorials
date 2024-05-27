using Consumers;
using MassTransit;
using Microsoft.AspNetCore.Mvc;
using static Services.Factorizer;

namespace Controllers;

[ApiController]
[Route("[controller]")]
public class RsaController(
    ILogger<RsaController> logger,
    IPublishEndpoint publishEndpoint
) : ControllerBase
{
    private readonly ILogger<RsaController> _logger = logger;
    private readonly IPublishEndpoint _publishEndpoint = publishEndpoint;

    [HttpPost("factorization-request")]
    public async Task<IActionResult> FactorizationRequest(FactorizationRequest request)
    {
        long number = request.Number;
        long lowerBound = request.LowerBound;
        long upperBound = request.UpperBound;

        int count = 10;
        long interval = (upperBound - lowerBound) / count;

        // [0, count)
        IEnumerable<Task> tasks = Enumerable.Range(0, count)
            .Select(selector =>
            {
                long start = lowerBound + selector * interval;
                long end = selector == count - 1 ? upperBound : start + interval; // int truncation

                return _publishEndpoint.Publish(new FactorizationRequest(
                    Number: number,
                    LowerBound: start,
                    UpperBound: end));
            });

        await Task.WhenAll(tasks);

        return Ok();
    }

    [HttpGet("factorization-result")]
    public IActionResult FactorizationResult(long result)
    {
        _logger.LogInformation("Factorization result: {result}", result);
        return Ok(new { result });
    }
}
