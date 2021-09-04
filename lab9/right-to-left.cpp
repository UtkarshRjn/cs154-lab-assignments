#include <iostream>
using namespace std;
class A {
 int id;
 public:
	A (int v) {id=v;}
	A &operator = (A &a) {
		cout << "executing " << id << "=" << a.id << endl;
		return *this;
	}
};

int main () {
 int a=90, b=8, c=3;
	a = (++b) = (c++);
 cout << a << " " << b << " " << c << " " << endl;
 
 A a1(1), a2(2), a3(3);
	a1=a2=a3;

// change
 a = 90, b = 8, c =3;
 ++b = c++;
 a = ++b;
cout << a << " " <<  b << " " << c << " " << endl; // 4 4 4


// change
a = 2,b = 1,c =4;
++c = ++a = --b;
cout << a << " " << b << " " << c << endl; // 0 0 0

}
