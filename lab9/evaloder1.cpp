#include <iostream>
using namespace std;


int p=1;

int f(int i) { p=p+i; return p; }

int main () {

 cout << f(p) << " " << f(p) << " " << f(p) << " " << f(++p) << endl;

p =1;
 // Change 
 cout << f(p++) << " " << f(++p) << " " << f(p) << " " << endl; // 3 8 16

}
