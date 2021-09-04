#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.1.3 (lab11, problem 1, program 3) = c.py 

class Table:
    
    dict_ack = {}
    count = 0

    def __inti__(self):
        pass

    def append(self,pair):
        if pair in self.dict_ack: 
            self.dict_ack[pair] += 1 
        else: 
            self.dict_ack[pair] = 1
    
    def display(self):
        print("Total Calls : ", self.count)
        for key, value in self.dict_ack.items():
            print(f"{key}: {value}")

t = Table()

def ackerman(m,n):
    t.append((m,n))
    t.count += 1
    if m==0: return n+1
    if n==0: return ackerman(m-1,1)
    else: return ackerman(m-1, ackerman(m,n-1))

print("ackerman(2,2) :" , ackerman(2,2))
t.display()