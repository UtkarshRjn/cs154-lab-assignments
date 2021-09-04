#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.1.4 (lab11, problem 1, program 4) = d.py 

class Table:
    
    dict_count = {}
    dict_value = {}
    count = 0

    def __inti__(self):
        pass

    def append(self,pair):
        if pair in self.dict_count: 
            self.dict_count[pair] += 1 
        else: 
            self.dict_count[pair] = 1
    
    def store(self,pair,val):
        self.dict_value[pair] = val

    def display(self):
        print("Total Calls : ", self.count)
        for key, value in self.dict_count.items():
            print(f"{key}: {value}")

t = Table()

def ackerman(m,n):
    if (m,n) in t.dict_value: return t.dict_value.get((m,n))
    t.append((m,n))
    t.count += 1
    if m==0: 
        t.store((0,n),n+1)
        return n+1
    if n==0: 
        t.store((m,0),ackerman(m-1,1))
        return ackerman(m-1,1)
    else:
        t.store((m,n), ackerman(m-1, ackerman(m,n-1)))
        return ackerman(m-1, ackerman(m,n-1))

print("ackerman(2,2) :" , ackerman(2,2))
t.display()