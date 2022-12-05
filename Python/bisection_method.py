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


print(bisection(lambda x: x**2 - 8, 0, 4))
