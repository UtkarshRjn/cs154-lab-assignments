// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 8.1.1 (assignment 8, part 1, program 1) = str2int.cpp

#include<iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

int str2int (string s) {
 // define your other needed variables
vector<int> v;
char c;
const char* x;
int num;

assert(s.length() != 0); // assert for precondition

// the logic, which does not check for any condition, can be buggy
for(int i=0;i < s.length();i++){
      c = s[i];
      x = &c;
      num = atoi(x);
      if (c !='0') assert(num != 0); // assert for postcondition
      v.push_back(num);
   }


   int ans = 0;
   int pow = 1;
   for(int i=0;i<s.length();i++){
      ans = ans + v[s.length()-i-1] * pow;
      pow = pow*10;
   }
   // add assertios for postcondition
   assert(ans!=0); // assert for post condition
	return ans;
};

int main() {

// develop main which catches errors through assertions
// report bugs

string s1 = "hello", s2 = "1245215";
string s3 = "000", s4 = "";

// Part 1
cout << str2int(s1) << endl; // Assertion 'num != 0' failed
// Part 2
cout << str2int(s2) << endl; // working case
// Part 3
cout << str2int(s3) << endl; // Assertion 'ans != 0' failed 
// Part 4
cout << str2int(s4) << endl; // Assertion 's.length() != 0' failed

}
