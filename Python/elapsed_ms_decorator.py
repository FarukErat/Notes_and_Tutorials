import time


def elapsedMS(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print("Elapsed time: {} ms".format((end - start) * 1000))
        return result
    return wrapper


if __name__ == "__main__":
    @elapsedMS
    def test():
        for i in range(10000000):
            pass

    test()
