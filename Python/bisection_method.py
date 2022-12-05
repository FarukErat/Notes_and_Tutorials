def bisection(f, lower, upper, tol=1e-8, maxiter=100):
    """Find root of f(x) using bisection method.

    Parameters
    ----------
    f : function
        Function to find root of.
    lower, upper : float
        Interval to search for root.
    tol : float
        Tolerance for stopping criterion.
    maxiter : int
        Maximum number of iterations.

    Returns
    -------
    x : float
        Estimated root location.
    """
    if f(upper)*f(lower) > 0:
        raise ValueError("f(upper) and f(lower) must have different signs")
    for i in range(maxiter):
        mid = (lower + upper)/2
        fm = f(mid)
        if abs(fm) < tol:
            return mid
        elif fm < 0:
            lower = mid
        else:
            upper = mid
    raise RuntimeError("Maximum number of iterations exceeded")


def square_root(x):
    return bisection(lambda y: y**2 - x, 0, x)


for i in range(1, 10):
    print("square root of", i, ":", square_root(i))

# square root of 1 : 0.9999999962747097
# square root of 2 : 1.4142135605216026
# square root of 3 : 1.732050810009241
# square root of 4 : 2.0
# square root of 5 : 2.2360679786652327
# square root of 6 : 2.4494897425174713
# square root of 7 : 2.6457513100467622
# square root of 8 : 2.8284271247684956
# square root of 9 : 3.000000001396984
