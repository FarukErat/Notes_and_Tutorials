'''
Converts a number from one base to another base.

Works with only numbers, thus returns a list of digits.
'''


def convert_base(digits, from_base, to_base):
    # Handle exceptions
    if min(from_base, to_base) < 2:
        raise ValueError('Bases must be >= 2')
    if len(set(digits)) == 1 and digits[0] == 0:
        return [0]
    for digit in digits:
        if not 0 <= digit < from_base:
            raise ValueError('All digits must satisfy 0 <= d < from_base')

    # First, we need to convert the number to base 10
    base10_num = 0
    power = 0
    for digit in digits[::-1]:
        base10_num += digit * (from_base ** power)
        power += 1

    # Now that we have the number in base 10, we can convert it to any other base
    # by repeatedly dividing by the target base and keeping track of the remainders
    output = []
    while base10_num > 0:
        output.append(base10_num % to_base)
        base10_num //= to_base

    # The output is reversed, so we need to reverse it again to get the correct result
    return output[::-1]


# Example usage:
if __name__ == '__main__':
    print(convert_base([9, 21, 31], 7, 2))
    print(convert_base([9, 21, 31], 99, 10))
    print(convert_base([9, 21, 31], 19, 16))
