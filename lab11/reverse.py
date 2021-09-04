#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.2.2 (lab11, problem 2, program 2) = reverse.py 

def reverse(l):
   
    if len(l) != 1:
        x = l[0]
        l.pop(0)
        reverse(l)
        l.append(x)
    return l

print(reverse([1,2,3,5]))
