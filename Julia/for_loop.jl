#for loop in range of [0, 9]
#output: i = 0 i = 1 i = 2 i = 3 i = 4 i = 5 i = 6 i = 7 i = 8 i = 9 
for i in 0:9
    print("i = ", i, " ")
end
println()

#for loop with iteration by 2 and in range of [0, 9]
#output: i = 0 i = 2 i = 4 i = 6 i = 8 
for i in 0:2:9
    print("i = ", i, " ")
end
println()

#nested for loop with i in range of [0, 3] and j in range of [5, 8]
#output: i = 0 j = 5 i = 0 j = 6 i = 0 j = 7 i = 1 j = 5 i = 1 j = 6 i = 1 j = 7 i = 2 j = 5 i = 2 j = 6 i = 2 j = 7 i = 3 j = 5 i = 3 j = 6 i = 3 j = 7 
for i in 0:3, j in 5:7
    print("i = ", i, " ", "j = ", j, " ")
end
println()

#nested for loop with iteration
#output: i = 0 j = 13 i = 0 j = 12 i = 0 j = 11 i = 3 j = 13 i = 3 j = 12 i = 3 j = 11 i = 6 j = 13 i = 6 j = 12 i = 6 j = 11 
for i in 0:3:7, j in 13:-1:11
    print("i = ", i, " ","j = ", j, " ")
end
println()
