# import necesary modules
from time import sleep
# take number from user for its prime factorization
num = int(input("Enter a number: "))
# if the number is less than 2, print error
if num < 2:
    print("The number does not have a prime factorization")
    input("Press Enter to continue...")
    exit()
print("Prime Factors")
# declare a variable (pow) to store the power of the prime factor
pow = 0
# declare a counter (i) to try dividing the number
# the counter starts from 2
i = 2
# declare a variable (flag) to check if the divisor has changed
flag = 0
# repeate the loop until the number is 1
while num != 1:
    # if the number is divisible by i
    if num % i == 0:
        # increase the power of the prime factor by 1
        pow += 1
        # divide the number by i
        num /= i
        # if pow is 1, print the prime factor
        if pow == 1:
            print(i, end="")
        # assign the value of flag to i
        flag = i
        # decrease the value of i by 1
        i -= 1
    # if flag is equal to i, it means the divisor has changed
    # print power of the prime factor
    if flag == i:
        # print the power of the prime factor, only if it is not 1
        if pow != 1:
            print(" ^", pow)
        # print function for new line
        else:
            print("")
        # reset the value of pow to 0
        pow = 0
    # increase the value of i by 1
    i += 1
# since the loop is stopped when num is 1, the last prime factor is the last number
# print the power of the last prime factor, only if it is not 1
if pow != 1:
    print(" ^", pow)
input("Press Enter to continue...")
