'''
Converts a number from one base to another base

Works with alphabets as well as numbers, thus returns a string
'''

def val(c):
    c = c.upper()
    if c >= '0' and c <= '9':
        return ord(c) - ord('0')
    else:
        return ord(c) - ord('A') + 10


def reVal(num):
    if num >= 0 and num <= 9:
        return chr(num + ord('0'))
    else:
        return chr(num - 10 + ord('A'))


def toDeci(str, base):
    llen = len(str)
    power = 1
    num = 0
    for i in range(llen - 1, -1, -1):
        if val(str[i]) >= base:
            print('Invalid Number')
            return -1
        num += val(str[i]) * power
        power = power * base
    return num


def fromDeci(res, base):
    str = ''
    while res > 0:
        str += reVal(res % base)
        res = int(res / base)
    return str[::-1]


def base_to_base(str, base1, base2):
    num = toDeci(str, base1)
    return fromDeci(num, base2)


if __name__ == '__main__':
    print(base_to_base('g', 20, 16))
