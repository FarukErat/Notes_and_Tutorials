'''
an alternative solution for
print(int("1010", 2))  # 1x2^3 + 0x2^2 + 1x2^1 + 0x2^0
print(int("1010", 8))  # 1x8^3 + 0x8^2 + 1x8^1 + 0x8^0
print(int("1010", 10))  # 1x10^3 + 0x10^2 + 1x10^1 + 0x10^0
'''


def digit_num(num, base):
    '''returns the number of digits required to represent the passed number over the passed base'''
    count = 0  # number of digits
    while num:  # while the number is not 0
        num //= base  # divide the number by the base
        count += 1  # and increase the count
    return count  # return the count


def inc_by_one(digits, base):
    '''increases the rightmost digit of passed list by one'''
    digits_len = len(digits)  # length of the list
    i = digits_len - 1  # index of the last digit (rightmost)
    while digits[i] == base - 1:  # if the last digit is equal to base - 1
        digits[i] = 0  # set it to 0
        i -= 1  # and decrease the index
    digits[i] += 1  # otherwise increase the digit
    return digits  # return the list


def dec_to_base(num, base):
    '''converts the passed number to desired base as a list'''
    if base < 2:  # if the base is less than 2
        return "Base must be greater than 1"  # return error message
    num = abs(num)  # get the absolute value of the number
    digits = [0] * digit_num(num, base)  # list of digits
    for i in range(num):  # for each digit
        digits = inc_by_one(digits, base)  # increase the digit by one
    return digits  # return the list


if __name__ == "__main__":
    num = int(input("Enter an integer: "))
    base = int(input("Enter a base: "))
    print(dec_to_base(num, base))
