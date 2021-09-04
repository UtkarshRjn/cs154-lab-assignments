#include <iostream>
using namespace std;

class A{
    protected:
    int x;
 	public:
		A(int v){x = v;}
		virtual void f()=0;
		virtual void g()=0;
		virtual void k(){cout << x << " A::k\n";}
};
class B : public A{
	 int y;
	 public:
		B(int v):A(v+10){y = v;}
		virtual void f(){cout << y << " B::f\n";}
		virtual void g(){cout << y << " B::g\n";}
		virtual void k(){cout << y << " B::k\n";}
};
class C : public A{
	 int z;
	 public:
 		C(int v):A(v+20){z=v;}
		virtual void f(){cout << z << " C::f\n";}
		virtual void k(){cout << z << " C::k\n";}
		virtual void g(){cout << z << " C::g\n";}
		virtual void h(){cout << z << " C::h\n";}
};
class D : public B, public C {
	 int w;
	 public:
 		D(int v):B(v+10),C(v+20){w=v;}
		virtual void f(){cout << w << " D::f\n";}
		virtual void k(){cout << w << " D::k\n";}
};

int main(){
	A* ap;
	B* bp;
	C* cp;
	D* dp;
	// A a; error! A is an abstract class
	// B b; error! B is an abstract class
	C c(100);
	D d(200);

	// d.g(); // error: request for member g is ambiguous
	d.B::g(); d.C::g(); d.k();
	c.g();
	ap = &c;
	ap -> k(); ap-> f();
	// ap = new D(50); // error: 'A' is an ambiguous base of 'D'
	ap = new C(800);
	// ap -> h(); // error: 'class A' has no member named 'h'
	ap -> f(); ap -> k(); ap -> g();
	cp = new D(100);
	cp -> h(); cp -> f(); cp->k(); cp -> g();

}