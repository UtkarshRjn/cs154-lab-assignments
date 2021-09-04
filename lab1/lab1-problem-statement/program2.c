#include<iostream>
#include<sstream>
#include<ctime>
using namespace std;

int main(int argc, char *argv[]){
	stringstream num(argv[1]);
	double N = 0;num >> N;
	cout << N << endl;
	double count[6] = {0};
	for(int i=0;i<N;i++){
		int x = rand()%6 + 1; // rand()%6 generates number from 0 to 5 thus +1 would make it from 1 to 6 
		count[x-1]++; // count[i] stores the number of times i+1 appeared on throwing the dice
	}
	for(int i=0;i<6;i++){
		double prob = count[i]/N;
		cout << "The probability of occurence of " << i+1 << " : " << prob << endl; 
	}
}