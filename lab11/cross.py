#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.1.1 (lab11, problem 2, program 1) = cross.py 

def cross(l1,l2):
    list = []
    if len(l1) == 0: return list
    for i in range(len(l2)):
        list.append((l1[0],l2[i]))
    return list + cross(l1[1:],l2)

print(cross([1,2,3,4],[2,3,5,3,2]))