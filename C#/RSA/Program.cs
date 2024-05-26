using Masters;

long number = 123456789;
long lowerBound = 2;
long upperBound = 123456789;
int count = 10;
long interval = (upperBound - lowerBound) / count;

// [0, count)
IEnumerable<Task> tasks = Enumerable.Range(0, count)
    .Select(selector =>
    {
        return Master.SendFactorizationRequestAsync(
           number: number,
           lowerBound: lowerBound + interval * selector,
           upperBound: selector == count - 1 ? upperBound : lowerBound + interval * (selector + 1)); // truncation
    });

await Task.WhenAll(tasks);
