// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 1.2.1 (assignment 1, part 2, program 1) = prog2.c

#include<iostream>
#include<fstream>
using namespace std;

struct letter{
	int count[52];
};

void initialize(struct letter* a){
	for(int i=0;i<52;i++){
		a->count[i] = 0;
	}
}

void setCount(struct letter* a, char ch){
	if(ch>=65 && ch <= 90){   // ch is from 'A' to 'Z'
		a->count[ch-65]++;
	}
	else if(ch>=97 && ch <= 122){  // ch is from 'a' to 'z'
		a->count[ch-97+26]++;
	}
}
void printCount(struct letter* a){
	for(int i=0;i<26;i++){
		printf("Frequency of %c is : %d \n", i+65, a->count[i]);
	}
	for(int i=26;i<52;i++){
		printf("Frequency of %c is : %d \n", i+97-26, a->count[i]);
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
	struct letter* a = new struct letter();
	initialize(a);
	while(!fin.eof()){
		fin.get(ch);
		char temp = ch;
		setCount(a,temp);
	}
	printCount(a);

	fin.close();
}