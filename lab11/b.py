#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.1.2 (lab11, problem 1, program 2) = b.py 

count = 0

def ackerman(m,n):
    global count
    count = count + 1
    if m==0: return n+1
    if n==0: return ackerman(m-1,1)
    else: return ackerman(m-1, ackerman(m,n-1))

print("ackerman(2,2) :" , ackerman(2,2))
print("Total number of calls :", count)