#how will a higher order function look like in C
#int f(int g(int), int x) -- this syntax is not available in C/C++
#g(x);
#};

def f(g,l):
	return g(l)


def func1(l):
	sum=0
	for x in l:
		sum = sum+x
	return sum


def func2(l):
	prod=1
	for x in l:
		prod= prod*x
	return prod 



l = [1,2,3,4]

v1 = f (func1,l)
v2 = f (func2,l)

print (v1,v2)

v3 = f(10,l)



