// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 2.1.1 (assignment 2, part 1, program 1) = singlelift.cpp 

#include<iostream>
using namespace std;
#define UP 1
#define DOWN -1
#define PAUSED 0

class Lift{
	int current_floor; // Floor at which lift is currently present
	int status; // status = UP, means lift is moving up; status = DOWN, means lift is going down; status = 0, means lift is paused;
	// Lift is paused only when there is no Car call or Landing call.
	size_t capacity;
	size_t passengers; // Number of persons in the Lift at a moment
	size_t CarCall[7] = {0}; // This array stores the car calls at respective floors.i.e, CarCall[4] = 2, means two passengers have to exit the lift at floor 4.
	int LandingCall[7] = {0}; // This array stores the Landing calls at respective floors.i.e, LandingCall[i] = 0 means noone has called lift at the ith floor, LandingCall[i] = UP(DOWN) means someone wants to go up(down) at the ith floor 
public:
	Lift(int init_floor, size_t capacity){
		current_floor = init_floor;
		status = PAUSED;
		passengers = 0;
		capacity = capacity;
		cout << "Printing initial status of lift:\n";
		print_status();
	}

	int get_current_floor(void);
	void set_LandingCall(int,int);
private:
	void set_CarCall(int);
	void set_direction(int);
	bool check_request(void);
	void start_lift(void);
	void print_status(void);
};

int Lift::get_current_floor(void){ // Gives the current_floor, used in floor class to allocate lift in twolifts.cpp
	return current_floor;
}

void Lift::set_LandingCall(int floor, int direction){ // this sets the landing call whenever up/down is pressed at a floor.
	LandingCall[floor] = direction;
	this -> set_direction(floor); 
	this -> start_lift(); // lift is started after landingCall is made
}

void Lift::set_direction(int floor){ // when the lift is paused it sets the direction as to whether lift would move up or down
	if((passengers == 0 || passengers == 1) && status == PAUSED){
			if(floor > current_floor) { status = UP; cout << "\nDoor Closes" << "\tLift starts moving upward " << endl;}
			else if(floor < current_floor) { status = DOWN; cout << "\nDoor Closes" << "\tLift starts moving downward" << endl;}
	}
}

void Lift::set_CarCall(int floor){ // whenever a person enters the lift this function sets the CarCall(destinaiton where the passenger what to go)
	CarCall[floor]++;
	this -> set_direction(floor);
	this -> start_lift();
}

void Lift::start_lift(void){ // This is the member function responsible for the working of the program (contains a while loop)
	while(check_request()!= true){
		if(status == UP && current_floor!=6) {current_floor++;}
		else if(status == DOWN && current_floor!=0) {current_floor--;}
	} // Ending of this loop changes the value of current_floor at the floor at which the lift will stop. 
}

bool Lift::check_request(void){ // This checks at every floor whether it has to take someone in or make someone exit the lift at that floor, this is in accordance with the logic present in the video  

	if(status == UP || status == PAUSED){
		if(CarCall[current_floor]!=0) {
			passengers -= CarCall[current_floor];
			if(passengers == 0) status = PAUSED;
			cout << CarCall[current_floor] << " passenger(s) left the lift at floor " << current_floor << endl;
			CarCall[current_floor] = 0;
			this -> print_status();
			return true;
		}
		else if((LandingCall[current_floor]==UP && current_floor != 6) || (LandingCall[current_floor]==DOWN && (current_floor == 6 || passengers == 0))){ 
			passengers += 1; // assuming only one person is there at a floor at a time calling lift to simplify the model
			LandingCall[current_floor]=0;
			if(passengers==1 || passengers > capacity) status = PAUSED;
			cout << "A passenger entered the lift at floor " << current_floor << endl;
			this -> print_status();
			cout << "Enter the destination for this passenger: ";
			int floor;
			cin >> floor;
			this -> set_CarCall(floor);
			return true;
		}
	}
	else if(status == DOWN || status == PAUSED){
		if(CarCall[current_floor]!=0) {
			passengers -= CarCall[current_floor];
			if(passengers == 0) status = PAUSED;
			cout << CarCall[current_floor] << " passenger(s) left the lift at  floor " << current_floor << endl;
			CarCall[current_floor] = 0;
			this -> print_status();	
			return true;
		}
		else if((LandingCall[current_floor]==DOWN && current_floor !=0) || (LandingCall[current_floor]==UP && (current_floor == 0 || passengers == 0))) {
			passengers += 1; // assuming only one person is there at a floor at a time calling lift to simplify the model
			LandingCall[current_floor]=0;
			if(passengers == 1 || passengers > capacity) status = PAUSED;
			cout << "A passenger entered the lift at floor " << current_floor << endl;
			this -> print_status();
			cout << "Enter the destination for this passenger: ";
			int floor;
			cin >> floor;
			this -> set_CarCall(floor);
			return true;
		}
	}
}

void Lift::print_status(void){ // print the status of the lift at floors where the lift stops to pick or depart passenger

	cout << "=======================================================\n"
	<< "FLOOR : " << current_floor 
	<< "\nNumber of Occupants : " << passengers 
	<< "\nDOOR: Opens"
	<< "\n=======================================================\n";
}

class Floor{
	int floor_num;
	Lift *lift_ptr;
public:
	void up(void);
	void down(void);
	void set_floor_num(int);
	void set_lift_ptr(Lift*);
};

void Floor::up(void) {  // A function to simulate the up button at floors
	cout << "\nSOMEONE CALLED THE LIFT AT FLOOR " << floor_num << endl;
	cout << "Enter c to continue:";
	char ch; cin >> ch;
	lift_ptr->set_LandingCall(floor_num,UP);
}
void Floor::down(void){ // A function to simulate the down button at floors
	cout << "\nSOMEONE CALLED THE LIFT AT FLOOR " << floor_num << endl;
	cout << "Enter c to continue:";
	char ch; cin >> ch;
	lift_ptr->set_LandingCall(floor_num,DOWN);
}
// Member functions used for the initialization of a Floor variable
void Floor::set_floor_num(int floor){ floor_num = floor;}
void Floor::set_lift_ptr(Lift* lift){ lift_ptr = lift;}

int main(){
	Lift lift(0,5);
	Floor floor[7];
	
	// initializing floors
	for(int i=0;i<7;i++){
		floor[i].set_floor_num(i);
		floor[i].set_lift_ptr(&lift);
	}

	// A specified set of input as suggested by Sir 
	floor[3].down();
	floor[6].down();
	floor[0].up();
	floor[4].up();
	floor[2].up();
	floor[1].up();

}