//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 3.2.1 (assignment 3, part 2, program 1) = vendingmachine.cpp 

#include <iostream>
using namespace std;
#define MAX 100
#define drinkid_factor 5526 
#define price_factor 10

class VendingMachine {
	int drinkid[MAX]; // array to store drinkID of various drinks in the vending machine
	int price[MAX]; // array to store price of drink at the respective index of the drinkID
 public:
 	VendingMachine(){
 		for(int i=0;i<MAX;i++){
 			drinkid[i] = drinkid_factor*(i+1);
 		}
 		for(int i=0;i<MAX;i++){
 			price[i] = price_factor*(i+1);
 		}
 	}
	void insertcoin (int val);
	bool selectdrink (int drinkid); 

};

void VendingMachine::insertcoin(int val){ // checks if the inserted value of coin corresponds to some drink and accordingly calls selectdrink member function
	cout << "value of coin inserted: " << val << endl;
	bool drink_exist = false;
	for(int i=0;i<MAX;i++){
		if(val == price[i]){
			this -> selectdrink(drinkid[i]);
			drink_exist = true;
			break;
		}
	}
	if(!drink_exist){this -> selectdrink(0);}
}

bool VendingMachine::selectdrink(int drinkid){ // prints the statement for the two cases. returns true when drink is present else return false
	if(drinkid!=0){
		cout << "Allocating drink with drink ID: " << drinkid << "\n\n";
		return true;
	}
	else if(drinkid==0){
		cout << "There is no drink at this price in the vending machine." << "\n";
		cout << "Try inserting coin value as some multiple of 10 :)" << "\n\n";
		return false;
	}
}

// Insert all coins at once seperated by spaces as command line argument
// Insert coin values as multiples of 10(to get a drink) else any other value won't fetch a drink
int main (int argc, char *argv[]) { 
	VendingMachine v;

	for(int i=1;i<argc;i++){
		double N;
		N = atoi(argv[i]);
		v.insertcoin(N);
	}
}
