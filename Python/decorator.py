# taken from https://www.datacamp.com/tutorial/decorators-python

def uppercase_decorator(function):
    def wrapper():
        func = function()
        make_uppercase = func.upper()
        return make_uppercase

    return wrapper


def say_hi_1():
    return 'hello there'


decorate = uppercase_decorator(say_hi_1)
print(decorate())
# HELLO THERE


@uppercase_decorator
def say_hi_2():
    return 'hello there'


print(say_hi_2())
# HELLO THERE
