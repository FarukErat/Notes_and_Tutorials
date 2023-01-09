# taken from https://www.w3schools.com/python/python_try_except.asp

x = -1

if x < 0:
    raise Exception("Sorry, no numbers below zero")

if type(x) is int:
    raise TypeError("Integers are not allowed")
