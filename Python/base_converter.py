'''
an alternative solution for
print(int("1010", 2))  # 1x2^3 + 0x2^2 + 1x2^1 + 0x2^0
print(int("1010", 8))  # 1x8^3 + 0x8^2 + 1x8^1 + 0x8^0
print(int("1010", 10))  # 1x10^3 + 0x10^2 + 1x10^1 + 0x10^0
'''

# increases the rightmost digit of passed list by one
def increase_num_by_one(digits, base):
    digits_len = len(digits)  # length of the list
    i = digits_len - 1  # index of the last digit (rightmost)
    while digits[i] == base - 1:  # if the last digit is equal to base - 1
        digits[i] = 0  # set it to 0
        i -= 1  # and decrease the index
    digits[i] += 1  # otherwise increase the digit
    return digits  # return the list

# returns the number of digits in the passed number
def digit_num(num, base):
    count = 0  # number of digits
    while num:  # while the number is not 0
        num //= base  # divide the number by the base
        count += 1  # and increase the count
    return count  # return the count

# converts the passed number to desired base as a list
def decimal_to_any_base(num, base):
    digits = [0] * digit_num(num, base)  # list of digits
    for i in range(num):  # for each digit
        digits = increase_num_by_one(digits, base)  # increase the digit by one
    return digits  # return the list

# converts the passed number to desired base
def convert_to_base(num, base):
    if base < 2:  # if the base is less than 2
        return "Base must be greater than 1"  # return error message
    digits = decimal_to_any_base(num, base)  # convert the number to base
    len_num = len(digits)  # number of digits
    output = ""  # output string"""
    for i in range(len_num):  # for each digit
        output += str(digits[i])  # add the digit to the output string
        output += " "  # add a space
    return output  # return the output string


# prints '5 10 0' since 975 = 5 * 13^2 + 10 * 13^1 + 0 * 13^0
print(convert_to_base(975, 13)) 
