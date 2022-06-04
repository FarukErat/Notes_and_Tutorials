def prime_factor(num):
    if num < 2:
        return "The number must be equal to or greater than 2."
    pow = 0
    divider = 2
    last_divider = 0
    result = ""
    while num != 1:
        if num % divider == 0:  # if divider is a factor
            pow += 1
            num /= divider
            if pow == 1:  # if divider is found for the first time
                result += str(divider)
            last_divider = divider
            divider -= 1  # This is to check out if the number is multiple of divider again
        # When the divider was multiple but is not anymore
        # because it did not satisfy the condition above
        # therefore the below comment code was not executed
        # last_divider = divider
        # divider -= 1
        # the below code checks if last_divider == divider, otherwise it would be executed
        # even when it is not just after the divider is not multiple
        elif last_divider == divider:
            if pow != 1:
                result += " ^ " + str(pow)
            result += '\n'
            pow = 0
        divider += 1
    if pow != 1:
        result += " ^ " + str(pow)
    return result


if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print("Prime Factors")
    print("-------------")
    print(prime_factor(num))
    print("-------------")
