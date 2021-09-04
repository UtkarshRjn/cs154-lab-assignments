    #include <iostream>

using namespace std;

void f(int x, int y, int z) {
    cout << x << " " << y << " " << z << endl;
}

int main () {
int i=10;

f(i, i++, ++i);

// i = 100;

f(++i, i++, ++i);

//changes
int a = 1;
f(a++,a++,a++); // prints 3 2 1
a = 1;
f(++a,++a,++a); // prints 4 4 4

cout << i << endl;

}
