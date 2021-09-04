#anonymous function is defined inside f and returned

f = lambda x: x + x #function abstraction-- creates a function, we are assiging that to variable f

def f(x):
        return lambda y: x+y

g = lambda x: x*x if(x>10) else x+x

print(g(20))

g1 = f(10)
g2 = f(20)
g3 = f(30)

print(g1(100))
print(g1(200))
print(g2(100))
print(g2(200))
print(g3(100))
print(g3(200))

h = lambda x: x*x if(x>10) else (10 if x==9 else 0)