# Program written by: Utkarsh Ranjan (200050147)
# Program part of: CS 152/CS154 Laboratory, 2021 batch
# Program for: lab10 function.py 
# 9 lines of code(using loop)

file = open("data.txt")
dict = {}
for line in file:
    line_list = line.split()
    for word in line_list:
        if word in dict: dict[word] += 1 
        else: dict[word] = 1
for key, value in dict.items(): print(f"{key}: {value}")
file.close()

# line of code (using builtin count function)
# for e in set(open("data.txt").read().split()): print(e, open("data.txt").read().split().count(e))