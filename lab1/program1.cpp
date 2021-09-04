//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 1.1.2 (assignment 1, part 1, program 2) = prog1.cpp 

#include<iostream>
#include<time.h>
using namespace std;

class DiceRes{
	double frequency[6]; // frequency of each outcome
public:
	void initialize(void); // instead of using a constructot I have used a function to initialize frequency
	void increaseFrequency(int);
	void printProb(double);
};

void DiceRes::initialize(void){
	for(int i=0;i<6;i++){
		frequency[i] = 0;
	}
}

void DiceRes::increaseFrequency(int x){
	frequency[x-1]++;
}

void DiceRes::printProb(double N){
	for(int i=0;i<6;i++){
		double prob = frequency[i]/N;
		cout << "The probability of occurence of " << i+1 << " : " << prob << endl; 
	}
}

int main(int argc, char *argv[]){
	
	srand(time(0));
	double N = 0;
	
	if (argc < 2) {
		cout << "usage: no_of_tries\n";
		exit(1);
  	};

	N = atoi(argv[1]);
 	cout << "counting over " << N << " tosses\n";
 
 	DiceRes *a = new DiceRes();
 	a->initialize();
	for(int i=0;i<N;i++){
		int x = rand()%6 + 1; // rand()%6 generates number from 0 to 5 thus +1 would make it from 1 to 6 
 		a->increaseFrequency(x);
	}
	a->printProb(N);
}