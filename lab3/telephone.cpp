//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 3.2.2 (assignment 3, part 2, program 2) = telephone.cpp 

#include <iostream>
using namespace std;
#define connected 1
#define timeout 2
#define number_donot_exist 3


class Telephone {
	int state; // idle, receiverup, in conversation, dialing, connecting 
public:
	void receiverup(void);
	void receiverdown(void);
	void dialdigit (string digit); // if number is dialed, randomly choose
			// connected, timeout, number does not exist state
};

void Telephone::dialdigit(string digit){
	cout << "dialing phone number: " <<  digit << endl;
	state = rand()%3 +1;
	if(state == connected || state == timeout){
		cout << "connecting....." << endl;
		cout << "dialing...." << endl;

		if(state == connected){
			this->receiverup();
		}
		else if(state == timeout){
			this -> receiverdown();
		} 
		
	}
	else { cout << "Invalid phone number" << endl;}

}

void Telephone::receiverup(void){
	cout << "Call recieved\nIn conversation......" << endl;
	cout << "call disconnected - call ended " << endl; 
}

void Telephone::receiverdown(void){
	cout << "No one recieved call - timeout" << endl;
}

int main (int argc, char *argv[]) {
	
	srand(time(0));
	Telephone t;
	t.dialdigit(argv[1]);

}
