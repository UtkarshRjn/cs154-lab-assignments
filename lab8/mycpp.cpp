//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 8.1.5 (assignment 8, part 1, program 5) = mycpp.cpp

// This cpp file has been taken from lab3 model_4.cpp

#include <iostream>
#include <cassert>
using namespace std;
#define MAX 10

class Stack {
// Note that card are top are basically the same variable
  int S[MAX]; // S[45] is 46th element!
  int top = 0; // current position in stack which is empty, position indicator
  int card = 0;
public:
  void push (int elem) ;// add an element on top of stack
  int pop (void);  // note the value at the top, remove the top and return the value 
  int return_card(void); // cardinality, how many elements in stack 
};


void Stack::push(int elem) {
    assert(top < MAX);
    S[++top] = elem;
    cout << elem << " pushed into stack\n";
}

int Stack::pop(void){
    assert(top >= 0);
    int x = S[top--];
    return x;
}

int Stack::return_card(void){
  card = top;
  return card;
}

int main () { // is a user of the object, through its abstraction... 

Stack s1, s2;

int e;
  
// Part 1
  for(int i=0;i<1000;i++){
    s1.push (i); // Assertion 'top < MAX' failed
  }
  e = s1.pop();
  cout << e << endl;
  e = s1.pop();
  cout << e << endl;

// Part2
  s2.push (10);
  s2.push(12);
  s2.push (14);

  for(int i=0;i<10;i++){
      e=s2.pop();
      cout << e << endl; // Assertion 'top >= 0' failed
  }

}
