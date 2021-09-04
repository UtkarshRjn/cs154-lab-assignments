// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 1.1.1 (assignment 1, part 1, program 1) = prog1.c 

#include<iostream>
#include<time.h>
using namespace std;

struct DiceRes{
	int frequency[6];
};

void initialize(struct DiceRes* a){
	for(int i=0;i<6;i++){
		a->frequency[i] = 0;
	}
}
void increaseFrequency(struct DiceRes* a, int x){
	a->frequency[x-1] = a->frequency[x-1] + 1;
}
void printProb(struct DiceRes* a, double N){
	for(int i=0;i<6;i++){
		double f = a->frequency[i];
		double prob = f/N;
		printf("The probability of occurence of %d : %lf \n",i+1,prob); 
	}
}

int main(int argc, char *argv[]){
	srand(time(0));
	double N = 0;
	
	if (argc < 2) {
		printf("usage: no_of_tries\n");
		exit(1);
  	};
	
	N = atoi(argv[1]);
 	printf("counting over %d throws\n",(int)N);

 	struct DiceRes *a = new struct DiceRes();
 	initialize(a);
	for(int i=0;i<N;i++){
		int x = rand()%6 + 1; // rand()%6 generates number from 0 to 5 thus +1 would make it from 1 to 6 
 		increaseFrequency(a,x);
	}
	printProb(a,N);
}
