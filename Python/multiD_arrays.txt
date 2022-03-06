# constants for the loops
ROW = 3
COL = 5

# create a 2D array of size ROW x COL
arr1 = [[1] * COL for i in range(ROW)]
for row in range(ROW):
    for col in range(COL):
        print(arr1[row][col], end=' ')
    print()

'''
Output:
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
'''

print()

# the same proccess with two for loops repeating
# since there is no list multiplication it is one dimensional
arr2 = [2 for i in range(COL) for j in range(ROW)]
for row in range(ROW):
    for col in range(COL):
        print(arr2[row*COL+col], end=' ')
    print()

'''
Output:
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
'''
