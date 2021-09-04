// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 8.1.2 (assignment 8, part 1, program 2) = collection.cpp

#include <iostream>
using namespace std;
#include <cassert>
// A program which is not correct
class Collection {
int *S;
int cap, card;

  public:
	Collection(int sz) {
		S = new int [sz];
		card=0;
    cap = sz;
  //... add assertion(s)...
    assert(cap == sz); // assert for postcondition
	}

	void push_back(int elem) {
  //... add assertion(s)...
      assert(card<cap); // assert for precondition
  
  //... add logic
      S[card++]=elem;
  
  //... add assertion(s)...
      assert(card != cap+1); // assert for postcondition

	}

	int pop_back() {
  //... add assertion(s)...
      assert(card != 0); // assert for precondition
  
  //... add logic
      return S[--card];
      
  //... add assertion(s)...
      assert(card > 0); // assert for postcondition
	}
};

int main () {

// add code that tests the class above and fails it, which gets caught by assertions

// Part 1
Collection c(10);
  for (int i=0;i<100;i++){
    c.push_back(i); // Assertion card < cap failed
  }

  cout << c.pop_back() << endl;
  cout << c.pop_back() << endl;

// Part 2
Collection d(10);
  for(int i=0;i<10;i++){
    d.push_back(i);
  }
  for(int i=0;i<60;i++){
    cout << d.pop_back() << endl; // Assertion 'card != 0' failed.
  }

}

