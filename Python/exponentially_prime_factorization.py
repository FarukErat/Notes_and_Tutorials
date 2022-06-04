from time import sleep
num = int(input("Enter a number: "))
if num < 2:
    print("The number does not have a prime factorization")
    input("Press Enter to continue...")
    exit()
pow = 0
divider = 2
flag = 0
result = ""
while num != 1:
    if num % divider == 0:
        pow += 1
        num /= divider
        if pow == 1:
            result += str(divider)
        flag = divider
        divider -= 1  # This is to check out if the number is multiple of divider again
    if flag == divider:  # this being true means that the number is not multiple of divider anymore
        if pow != 1:
            result += " ^ " + str(pow) + '\n'
        else:
            result += '\n'
        pow = 0
    divider += 1
if pow != 1:
    result += " ^ " + str(pow) + '\n'
print("Prime Factors")
print("-------------")
print(result)
print("-------------")
sleep(3)
