#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.1.1 (lab11, problem 1, program 1) = a.py 

def ackerman(m,n):
    if m==0: return n+1
    if n==0: return ackerman(m-1,1)
    else: return ackerman(m-1, ackerman(m,n-1))

print("ackerman(2,2) :" , ackerman(2,2))