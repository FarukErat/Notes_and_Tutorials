def new_rap(f, x0=0, tol=1e-8, max_iter=100):
    x = x0
    f_prime =  lambda x: (f(x + tol) - f(x)) / tol
    for i in range(max_iter):
        x = x - f(x) / f_prime(x)
        if abs(f(x)) < tol:
            return x
    raise RuntimeError("Maximum number of iterations exceeded")


def square_root(x):
    return new_rap(lambda y: y**2 - x, x)


for i in range(1, 10):
    print("square root of", i, ":", square_root(i))
