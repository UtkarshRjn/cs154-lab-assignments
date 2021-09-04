#include<iostream>
#include<sstream>
#include<ctime>
using namespace std;

struct DiceRes{
	int frequency[6] = {0};
};

void increaseFrequency(struct DiceRes* a, int x){
	a->frequency[x-1]++;
}
void printProb(struct DiceRes* a, int N){
	for(int i=0;i<6;i++){
		double prob = (a->frequency[i])/N;
		cout << "The probability of occurence of " << i+1 << " : " << prob << endl; 
	}
}

int main(int argc, char *argv[]){
	stringstream num(argv[1]);
	double N = 0;num >> N;
 	struct DiceRes *a;
	for(int i=0;i<N;i++){
		int x = rand()%6 + 1; // rand()%6 generates number from 0 to 5 thus +1 would make it from 1 to 6 
		cout << x << endl;
 		increaseFrequency(a,x);
	}
	printProb(a,N);
}