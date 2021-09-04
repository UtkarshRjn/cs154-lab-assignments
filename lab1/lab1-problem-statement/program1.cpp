#include<iostream>
#include<fstream>
using namespace std;

struct letter{
	int count[52] = {0};
};

void setCount(struct letter* a, char &ch){
	if(ch>=65 && ch <= 90){   // ch is from 'A' to 'Z'
		a->count[ch-65]++;
	}
	else if(ch>=97 && ch <= 122){  // ch is from 'a' to 'z'
		a->count[ch-97+26]++;
	}	
}
void printCount(struct letter* a){
	for(int i=0;i<52;i++){
		cout << a->count[i] << " ";  // frequency is printed for A,B,C,D....Z,a,b,c...z in this order seperated by spaces
	}
}

int main(int argc, char *argv[]){
	ifstream fin;
	fin.open(argv[1]);
	char ch;
	struct letter* a;
	while(!fin.eof()){
		fin.get(ch);
		setCount(a,ch);
	}
	printCount(a);

	fin.close();
}