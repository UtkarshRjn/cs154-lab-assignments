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

class Collection {
 int *array, card, maxsize; // storage and cardinality
 public:
	 Collection (int sz) {
		array = new int [sz];	
		card = 0;
		maxsize = sz;
	 }

	 Collection &operator << (int elem) { // Collection&  ---> this ensures cascading of operator
		if (card < maxsize) array [card++] = elem;
		return *this;
	 }

	// fetch the last element
	Collection &operator >> (int elem) {
		for(int i=0;i<elem;i++){
			int x;
			if(card > 0) x = array [--card];
			cout << "Element " << x << " popped out" << endl;
		}
		return *this;
	}

	// Merge another collection into it.
	Collection &operator +(Collection c){
		
		for(int i=card;i<maxsize;i++){
			array[i] = c.array[i-card];
		}
		card = card + c.card;
		if(card > maxsize) card = maxsize;
		return *this;
	}

	 void prn() { 
		for (int i=0; i<card; i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main () {

	Collection c1 (8);

		c1 << 1;
		c1 << 2;
		c1 << 3;
		c1.prn();

	Collection c2(3);

		c2 << 1 << 2 << 3 << 4 << 5;
		c2.prn();
	
	Collection c3(4);
		// Cascading operators
		c3 << 1 << 4 << 8 << 2;
		c3.prn();
		
		// fetching last two elements
		c3 >> 2;
		c3.prn();

		// Mergeing of c3 into c1
		c1 = c1 + c3;
		c1.prn();

	Collection c4(100);
	for(int i=1;i<=10;i++){
		c4 << 10*i;
	}
	c4.prn();
	c4 >> 2 >> 3; // cascading >> operator
	c4.prn();

	c4 = c4 + c1 + c2 +c3; // cascading + operator
	c4.prn();
}
