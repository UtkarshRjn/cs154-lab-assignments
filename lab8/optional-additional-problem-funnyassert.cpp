#include <iostream>
using namespace std;
//#define NDEBUG

// explain how this code will behave. there is no assert here but
// an attempt is made by the programmer to define one's own assert
//if you can do a better job and give some meaning to it, rewrite, and 
//explain

void error(int line, const char* file, const string& msg){
    cerr << "a.out: " << file << ":" << line << ": " << "Assertion'" << msg << "' failed" << endl;  
    abort();
}

#ifdef NDEBUG
#define codeassert( arg ) ((void)0)
#else
#define codeassert( arg ) \
    ((arg)? (void)0 : error(__LINE__, __FILE__,#arg))
#endif

int main() {

int i, j;
cin >> i;
cin >> j;

codeassert(i==j);
codeassert(true);
codeassert(false);

} 

