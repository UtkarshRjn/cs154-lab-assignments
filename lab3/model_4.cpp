//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 3.1.4 (assignment 3, part 1, program 4) = model_4.cpp 

#include <iostream>
using namespace std;
#define MAX 100

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
    if(top >= MAX) {
        cout << "Stack Overflow";
    }
    else {
        S[++top] = elem;
        cout << elem << " pushed into stack\n";
    }  
}

int Stack::pop (void){
    if(top < 0){
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = S[top--];
        return x;
    }
}

int Stack::return_card(void){
  card = top;
  return card;
}

int main () { // is a user of the object, through its abstraction... 

Stack s1, s2;

int e;
  s1.push (10);
  s1.push(12);
  s1.push (14);
  e = s1.pop();
  cout << e << endl;
  e = s1.pop();
  cout << e << endl;

  s2.push (10);
  s2.push(12);
  s2.push (14);
  e=s2.pop();
  cout << e << endl;
  e=s2.pop();
  cout << e << endl;

}
