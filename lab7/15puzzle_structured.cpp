// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 7 (assignment 7, part 1, program 2) = 15puzzle_structured.cpp 

#include <iostream>
#include <time.h>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Radio_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Light_Button.H> // needed to use the Fl_Box class
#include "button.h"

using namespace std;

// Definition of global variables
int i_blank, j_blank;
MyButton *button[4][4];
MyButton *game_button;

bool solved(){
	// This function returns true if the game is solved else return false 
	bool solved = true;
    if(i_blank!=3 || j_blank!=3 ) solved = false;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==3 && j==3) continue;
			if(button[i][j]->get_number() != 4*i+j+1) solved = false;
		}
	}
	return solved;
}

bool adjacent_buttons(int i, int j){

	// This function ensures that only adjacent buttons are exchanged with the blank button
	bool adjacent = false;
    if((i==i_blank && abs(j-j_blank)==1)||(j==j_blank && abs(i-i_blank)==1)) adjacent = true;
    return adjacent;
}

char *int2charstar (int v) {
	char *s = new char[sizeof(int)];
	sprintf(s,"%d",v);
	return s;
}

void exchange_buttons(int i,int j){ // Enchanges blank button with the button at index(i,j) i.e, button[i][j];
		button[i][j]->label("");
		button[i_blank][j_blank]->label(int2charstar(button[i][j]->get_number())); // exchanges the label with the blank button
		button[i_blank][j_blank]->change_number(button[i][j]->get_number()); // exchanges the number associated with the blank button 
		i_blank = i;
		j_blank = j;
}

MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
	number = atoi(l);
	j = x/button_edge - f/2 + 2;
	i = y/button_edge - f/2 + 2;
}

int MyButton :: handle (int e) {
	if (e == FL_PUSH && adjacent_buttons(i,j)) {
		if(i==i_blank && j == j_blank) return 1;// Ensures clicking the blank button doesn't do anything
		exchange_buttons(i,j); // Enchanges blank button with the button at index(i,j) i.e, button[i][j];
		if(solved()) game_button->label("Solved"); // If the board is solved changes the label of game_button to solved
		else game_button->label("Unsolved"); // else keeps it unolved
	}
	return 1;
}

void MyButton :: change_number(int x){number = x;}

void init_game(){

	// Initiates the game
	i_blank=3;
	j_blank=3;
	game_button = new MyButton(Windows_x/2 - button_edge,Windows_y/2 - 2.5 * button_edge,button_edge*2,button_edge/2,"Unsolved");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			button[i][j] = new MyButton(Windows_x/2 + (j-2)*button_edge ,Windows_y/2 + (i-2)*button_edge  ,button_edge,button_edge,int2charstar(4*i+j+1));
			button[i][j]->down_color(FL_RED);
		}
	}
	button[i_blank][j_blank]->label("");
}

void shuffle_game(int x){

	// Compel the computer make 10*x random moves thus creating a random initial board situation 
	for(int i=0;i<10*x;i++){
		int r = rand()%4;
		switch(r){
			case 0:
				if(i_blank+1>3) {i--;continue;}
				exchange_buttons(i_blank+1,j_blank);
				break;
			case 1:
				if(j_blank+1>3) {i--;continue;}
				exchange_buttons(i_blank,j_blank+1);
				break; 
			case 2:
				if(i_blank-1<0) {i--;continue;}
				exchange_buttons(i_blank-1,j_blank);
				break;
			case 3:
				if(j_blank-1<0) {i--;continue;}
				exchange_buttons(i_blank,j_blank-1); 
				break;
			default:
				break;
		}
	}
}

int main(int argc, char *argv[]) {
	
	srand(time(0));
	Fl_Window *window;
	
	window = new Fl_Window (Windows_x,Windows_y,"15puzzle"); // outer window
	window->color(FL_WHITE);
	
	init_game();

	int x;
	cout << "Enter difficulty of the game(1 to 5): ";
    cin >> x;
	shuffle_game(x); // Compel the computer make 10*x random moves thus creating a random initial board situation 

	window->end();
	window->show();

	return(Fl::run());  // the process waits from here on for events
}