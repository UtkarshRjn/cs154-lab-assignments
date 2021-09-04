// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 1.2.2 (assignment 1, part 2, program 2) = prog2.cpp 

#include<iostream>
#include<fstream>
using namespace std;

class letter{
	int count[52] = {0};
public:
	void setCount(char);
	void printCount(void);
	void initialize(void);
};

void letter::initialize(void){
	for(int i=0;i<52;i++){
		count[i] = 0;
	}
}

void letter::setCount(char ch){
	if(ch>=65 && ch <= 90){   // ch is from 'A' to 'Z'
		count[ch-65]++;
	}
	else if(ch>=97 && ch <= 122){  // ch is from 'a' to 'z'
		count[ch-97+26]++;
	}	
}
void letter::printCount(void){
	for(int i=0;i<26;i++){
		cout << "Frequency of " << char(i+65) << " is : " << count[i] << endl;
	}
	for(int i=26;i<52;i++){
		cout << "Frequency of " << char(i+97-26) << " is : " << count[i] << endl; 
	}
}

int main(int argc, char *argv[]){
	
	if (argc < 2) {
		printf("usage: name_of_txt_file\n");
		exit(1);
  	};

	ifstream fin;
	fin.open(argv[1]);
	char ch;
	
	letter* a = new letter();
	a->initialize();
	while(!fin.eof()){
		fin.get(ch);
		a->setCount(ch);
	}
	a->printCount();

	fin.close();
}