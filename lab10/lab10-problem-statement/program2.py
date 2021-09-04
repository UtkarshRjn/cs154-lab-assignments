for e in set(open("data.txt").read().split()): 
    print(e, open("data.txt").read().split().count(e))