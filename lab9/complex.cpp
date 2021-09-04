//program by Prof. R.K.Joshi
//for CS152, IIT Bombay

// Program modified by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: lab9 collection.cpp 

#include <iostream>
using namespace std;

//observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Complex {
 float i, j;
 public:
	 Complex (int x, int y) {
		i = x; j=y;
	 }

	 Complex operator + (Complex c) {
	 	cout << i << "+" << j << "i " << "+ " << c.i << "+" << c.j << "i" << endl;
		return Complex (i+c.i,j+c.j);
	 }

	Complex operator - (Complex c) {
	 	cout << i << "+" << j << "i " << "- " << c.i << "+" << c.j << "i" << endl;
		return Complex (i-c.i,j-c.j);
	 }

	Complex operator * (Complex c) {
		 cout << i << "+" << j << "i " << "* " << c.i << "+" << c.j << "i" << endl;
		 return Complex ((i*c.i - j*c.j),(i*c.j+j*c.i));  
	 }

	void print() { cout << i << "+" << j << "i" << endl;}

};

int main () {

Complex c1(10,10), c2(20,20), c3(0,0), c4(0,0);

	c3=c1+c2;

	c3.print();

	c3 = c3+c1+c2+c2;

	c3.print();

	c4 = c3 * c1; // * operator performing multiplication

	c4.print();

	c4 = c1 * c3 * c1; // cascading of * operator

	c4.print();

	c4 = c3 - c1; // - operator performing subtraction
	c4.print();

}
