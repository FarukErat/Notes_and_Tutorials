# an implemenatiton of the composite midpoint rule for integration

def integrate(f, start, finish, n=1000):
    if n % 2 != 0:
        return "n must be even"
    if n < 2:
        return "n must be greater than 2"
    h = (finish - start) / n
    sum = 0
    for i in range((n//2)+1):
        sum += f(start + 2*h*i)
    return sum * h * 2


def f(x):
    return x**3 + 2 * x**2 + 3 * x + 4


print(integrate(f, 0, 1))  # output:     6.410669000000006
print(77 / 12)             # real value: 6.416666666666667
