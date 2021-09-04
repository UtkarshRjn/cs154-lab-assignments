// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 8.1.3 (assignment 8, part 1, program 3) = substring.cpp

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Returns the index at which substring is present in a string else return -1
int find(string str, string sub) {  

int N = str.length();
int M = sub.length();
int index = 0;

// assert for precondition
assert(N!=0); 
assert(M!=0);
assert(M<=N);

for(int i=0; i<=N-M; i++){
    int j;
    for(j=0; j<=M; j++){
        if (str[i+j] != sub[j])
            break;
    }
    index = i;
    assert(index >= 0); // assert for post condition
    if(j == M) return index;
}
return -1;

}

int main () {

// add testing code here which fails the above function and that failure
//gets caught by the assertions that you have

string s1 = "SchoolforFun";
string s2 = "for";
string s3 = "hello";
string s4 = "Hellohello";
string s5 = "";
string s6 = "Resonance";

// Part 1
cout << find(s1,s2) << endl; // Working Case.
// Part 2
cout << find(s3,s4) << endl; // Assertion 'M<=N' failed.
// Part 3
cout << find(s5,s6) << endl; // Assertion 'N!=0' failed.



}
