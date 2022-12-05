def new_cot_integ(func, lower, upper, slice):
    h = (upper - lower) / slice
    x = lower
    sum = 0
    for i in range(slice):
        sum += func(x) + 4 * func(x + h / 2) + func(x + h)
        x += h
    return sum * h / 6


print(new_cot_integ(lambda x: x ** 2, 0, 2, 100))
# 2.66666666666667
