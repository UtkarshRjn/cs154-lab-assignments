#  Program written by: Utkarsh Ranjan (200050147)
#  Program part of: CS 152/CS154 Laboratory, 2021 batch
#  Program for: problem 11.1.5 (lab11, problem 1, program 5) = e.py 

class Table:
    
    dict_count = {}
    dict_value = {}
    count = 0
    
    def __inti__(self):
        pass

    def append(self,i):
        if i in self.dict_count: 
            self.dict_count[i] += 1 
        else: 
            self.dict_count[i] = 1

    def store(self,i, val):
        self.dict_value[i] = val 

    def display(self):
        print("Total Calls : ", self.count)
        for key, value in self.dict_count.items():
            print(f"fibonnaci({key}): {value}")

t = Table()

def fibonnaci(n):
    if n in t.dict_value: return t.dict_value.get(n)
    t.append(n)
    t.count += 1
    if n==1: 
        t.store(1,1)
        return 1
    elif n==2:
        t.store(2,1)
        return 1
    else: 
        t.store(n,fibonnaci(n-1) + fibonnaci(n-2))
        return fibonnaci(n-1) + fibonnaci(n-2)

print(fibonnaci(8))
t.display()