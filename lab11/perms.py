#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.2.4 (lab11, problem 2, program 4) = perms.py 

def permutation(l1):
    list_per = []
    if len(l1) == 1:
        list_per.append(l1)
        return list_per
    else:
        for i in range(len(l1)):
            x = l1[i]
            for sublist in permutation(l1[:i] + l1[i+1:]):
                sublist.insert(0,x)
                list_per.append(sublist)
        return list_per

print(permutation([3,4,5]))