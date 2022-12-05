def new_cot_integ(func, lower, upper, n):
    h = (upper - lower) / n
    x = lower
    sum = 0
    for i in range(n):
        sum += func(x) + 4 * func(x + h / 2) + func(x + h)
        x += h
    return sum * h / 6


print(new_cot_integ(lambda x: x ** 2, 0, 2, 100))
# 2.66666666666667
