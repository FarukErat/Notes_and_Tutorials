def prime_factor(number):
    end_search = number**0.5
    divider = 2
    last_divider = 1
    factors = []
    powers = []
    if number == 0 or number == 1:
        factors.append(number)
        powers.append(1)
    else:
        if number < 0:
            number = -number
            factors.append(-1)
            powers.append(1)
        while number != 1:
            if number % divider == 0:
                number = number // divider
                end_search = number**0.5
                if divider != last_divider:
                    factors.append(divider)
                    powers.append(1)
                    last_divider = divider
                else:
                    powers[-1] += 1
            else:
                divider += 1
                if divider > end_search:
                    divider = number
    result = []
    for i in range(len(factors)):
        result.append((factors[i], powers[i]))
    return result


def print_factor(number):
    factors = prime_factor(number)
    for i in range(len(factors)):
        print(factors[i][0], end="")
        if factors[i][1] != 1:
            print(" ^", factors[i][1], end="")
        print()


if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print_factor(num)
