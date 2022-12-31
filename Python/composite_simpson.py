# an implementation of composite simpson rule for integration

def integrate(f, start, finish, n=1000):
    if n % 2 != 0:
        return "n must be even"
    if n < 2:
        return "n must be greater than 2"

    h = (finish - start) / n
    sum = f(start) + f(finish)

    for i in range(1, n//2):
        sum += 2 * f(start + 2*h*i)

    for i in range(1, (n//2)+1):
        sum += 4 * f(start + h*(2*i-1))

    return sum * h / 3


def f(x):
    return x**3 + 2 * x**2 + 3 * x + 4


print(integrate(f, 0, 1))  # output:     6.416666666666662
print(77 / 12)             # real value: 6.416666666666667
