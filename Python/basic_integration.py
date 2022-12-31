def integrate(f, start, finish, n=1000):
    if n < 2:
        return "n must be greater than 2"
    h = (finish - start) / n
    sum = 0
    for i in range(n):
        sum += f(start + h*i)
    return sum * h


def f(x):
    return x**3 + 2 * x**2 + 3 * x + 4


print(integrate(f, 0, 1))  # output:     6.413667249999999
print(77 / 12)             # real value: 6.416666666666667
