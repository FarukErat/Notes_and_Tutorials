# an implementation of composite trapezoidal rule for integration

def integrate(f, start, finish, n=1000):
    if n < 2:
        return "n must be greater than 2"
    h = (finish - start) / n
    sum = f(start) + f(finish)
    for i in range(1, n):
        sum += 2 * f(start + h*i)
    return sum * h / 2


def f(x):
    return x**3 + 2 * x**2 + 3 * x + 4


print(integrate(f, 0, 1))  # output:     6.416667249999999
print(77 / 12)             # real value: 6.416666666666667
