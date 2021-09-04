//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 3.1.1 (assignment 3, part 1, program 3) = model_3.cpp 

#include <iostream>
using namespace std;
#define MAX 100

struct Stack {
// Note that card are top are basically the same variable
  int S[MAX]; // S[45] is 46th element!
  int top = 0; // current position in stack which is empty, position indicator
  int card = 0;
};

void push (int elem, struct Stack* s){// add an element on top of stack
    
    if((s->top) >= MAX) {
        cout << "Stack Overflow";
    }
    else {
        s->S[++(s->top)] = elem;
        cout << elem << " pushed into stack\n";
    }
}

int pop (struct Stack* s){  // note the value at the top, remove the top and return the value 
    if((s->top) <= 0){
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int elem = s->S[(s->top)--];
        return elem;
    }
}

int return_card(struct Stack* s){ // cardinality, how many elements in stack 
  s->card = s-> top;
  return s->card;
}

int main () { // is a user of the object, through its abstraction... 

struct Stack s1, s2;

int e;
  push (10,&s1);
  push(12,&s1);
  push(14,&s1);
  e = pop(&s1);
  cout << e << endl;
  e = pop(&s1);
  cout << e << endl;

  push (10,&s1);
  push(12,&s1);
  push(14,&s1);
  e = pop(&s1);
  cout << e << endl;
  e = pop(&s1);
  cout << e << endl;

}
