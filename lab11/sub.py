#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.2.3 (lab11, problem 2, program 3) = sub.py 

def sub(l1,l2):
    if len(l2) == 0 : 
        return False
    for i in range(len(l1)):
        if l1[i] != l2[i]: 
            return sub(l1,l2[1:])
    else: 
        return True

print(sub([4,5], [1,2,3,4,5,6]))