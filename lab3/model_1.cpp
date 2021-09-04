//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 3.1.1 (assignment 3, part 1, program 1) = model_1.cpp 

#include <iostream>
using namespace std;

#define MAX 100

void push (int elem); // add an element on top of stack
int pop ();  // note the value at the top, remove the top and return the value 
int return_card(); // cardinality, how many elements in stack 

// Note that card and top are basically the same variable
int S[MAX]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int card=0; // cardinality, no. of elements in the stack

void push(int elem) {
    assert(top < MAX);
    else {
        S[++top] = elem;
        cout << elem << " pushed into stack\n";
    }
}

int pop (void){
    
    assert(top >= 0);
    else {
        int elem = S[top--];
        return elem;
    }
}

int return_card(void){
  card = top;
  return card;
}

int main () { // is a user of the object, through its abstraction... 
  
  int e;
  for(int i=0;i<1000;i++){
      push(i);
  }
  e = pop();
  cout << e << endl;
  e = pop();
  cout << e << endl;
}