#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]){
	ifstream fin;
	fin.open(argv[1]);
	char ch;
	int count[52] = {0};
	while(!fin.eof()){
		fin.get(ch);
		if(ch>=65 && ch <= 90){   // ch is from 'A' to 'Z'
			count[ch-65]++;
		}
		else if(ch>=97 && ch <= 122){  // ch is from 'a' to 'z'
			count[ch-97+26]++;
		}
	}
	for(int i=0;i<52;i++){
		cout << count[i] << " ";  // frequency is printed for A,B,C,D....Z,a,b,c...z in this order seperated by spaces
	}

	fin.close();
}