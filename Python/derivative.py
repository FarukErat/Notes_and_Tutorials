def derivative(f, x, h=1e-10):
    return (f(x + h) - f(x)) / h


if __name__ == '__main__':
    def f(x): return x ** 3
    print(derivative(f, 2))
