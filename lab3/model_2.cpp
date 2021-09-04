//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 3.1.2 (assignment 3, part 1, program 2) = model_2.cpp 

#include <iostream>
using namespace std;

#define MAX 100

void push (int elem, int *S, int *top, int *card); // add an element on top of stack
int pop (int *S, int *top, int *card);  // note the value at the top, remove the top and return the value 
int return_card(int *S, int *top, int *card); // cardinality, how many elements in stack 

// Note that card are top are basically the same variable
int S1[MAX]; // S[45] is 46th element!
int top1=0; // current position in stack which is empty, position indicator
int card1=0; // cardinality, no. of elements in the stack

int S2[MAX]; // S[45] is 46th element!
int top2=0; // current position in stack which is empty, position indicator
int card2=0; // cardinality, no. of elements in the stack


void push(int elem, int *S, int*top, int *card) {
    if(*top >= MAX) {
        cout << "Stack Overflow";
    }
    else {
        S[++(*top)] = elem;
        cout << elem << " pushed into stack\n";
    }
            
}

int pop(int *S, int *top, int *card){
    if((*top) < 0){
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int elem = S[(*top)--];
        return elem;
    }
}

int return_card(int *S, int *top, int* card){
  *card = *top;
  return (*card);
}

int main () { // is a user of the object, through its abstraction... 
int e;
  push (10, S1, &top1, &card1);
  push(12, S1, &top1, &card1);
  push (14, S1, &top1, &card1);
  e=pop(S1, &top1, &card1);
  cout << e << endl;
  e=pop(S1, &top1, &card1);
  cout << e << endl;

  push (10, S2, &top2, &card2);
  push(12, S2, &top2, &card2);
  push (14,S2, &top2, &card2);
  e=pop(S2, &top2, &card2);
  cout << e << endl;
  e=pop(S2, &top2, &card2);
  cout << e << endl;

}


