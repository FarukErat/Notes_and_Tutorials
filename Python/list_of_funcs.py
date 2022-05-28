ADD = 0
SUB = 1
MUL = 2
DIV = 3


def add(left, right):
    return left + right


def sub(left, right):
    return left - right


def mul(left, right):
    return left * right


def div(left, right):
    return left / right


calc = [add, sub, mul, div]

print(calc[ADD](1, 2))
