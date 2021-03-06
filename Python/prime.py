def prime_factor(number):
    divider = 2
    last_divider = 1
    factors = []
    powers = []
    result = []
    if number == 0:
        factors.append(0)
        powers.append(1)
    elif number == 1:
        factors.append(1)
        powers.append(1)
    else:
        if number < 0:
            number = -number
            factors.append(-1)
            powers.append(1)
        while number != 1:
            if number % divider == 0:
                number = number // divider
                if divider != last_divider:
                    factors.append(divider)
                    powers.append(1)
                else:
                    powers[-1] += 1
                last_divider = divider
            else:
                divider += 1
    for i in range(len(factors)):
        result.append((factors[i], powers[i]))
    return result


def print_factor(number):
    factors = prime_factor(number)
    for i in range(len(factors)):
        print(factors[i][0], end="")
        if factors[i][1] > 1:
            print(" ^", factors[i][1], end="")
        print()


if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print_factor(num)
