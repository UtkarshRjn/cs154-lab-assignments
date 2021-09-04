// Program written by: Utkarsh Ranjan (200050147)
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 7.1.1 (assignment 7, part 1, program 1) = 15puzzle_spaghetti.cpp 

#include <iostream>
#include <time.h>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Radio_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Light_Button.H> // needed to use the Fl_Box class

using namespace std;

//Declaration of class and functions
class MyButton;
bool solved();
void exchange_buttons(int,int);

// Definition of global variables
int i_blank, j_blank;
MyButton *button[4][4];
MyButton *game_button;

// Definition of class
class MyButton : public Fl_Button {
	int i,j;
	public:
	int number;
		MyButton (int x, int y, int w, int h, const char *l): Fl_Button (x,y,w,h,l){
				number = atoi(l);
				j = (x - 100)/100;
				i = (y - 100)/100;
		}
		int handle(int e){ // e is incoming mouse event of different kinds
            if (e == FL_PUSH && ((i==i_blank && abs(j-j_blank)==1)||(j==j_blank && abs(i-i_blank)==1))) {
                if(i==i_blank && j == j_blank) goto last;// Ensures clicking the blank button doesn't do anything
                exchange_buttons(i,j); // Enchanges blank button with the button at index(i,j) i.e, button[i][j];
                if(solved()) goto setlabel; // If the board is solved changes the label of game_button to solved
                game_button->label("Unsolved"); goto last; // else keeps it unsolved
				setlabel: game_button->label("Solved");
            }
            last : return 1;
        }
		void change_number(int x){number = x;}
};

bool solved(){
	
	// This function returns true if the game is solved else return false 
	if(i_blank!=3 || j_blank!=3 ) return false;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==3 && j==3) continue;
			if(button[i][j]->number != 4*i+j+1) return false;
		}
	}
	return true;
}

void exchange_buttons(int i,int j){ // Enchanges blank button with the button at index(i,j) i.e, button[i][j];
		button[i][j]->label("");
		char *s = new char[sizeof(int)];
		sprintf(s,"%d",button[i][j]->number);
		button[i_blank][j_blank]->label(s); // exchanges the label with the blank button
		button[i_blank][j_blank]->change_number(button[i][j]->number); // exchanges the number associated with the blank button 
		i_blank = i;
		j_blank = j;
}

int main(int argc, char *argv[]) {
	
	srand(time(0));
	Fl_Window *window;
	
	window = new Fl_Window (600,600,"DEMO"); // outer window
	window->color(FL_WHITE);
	
	i_blank=3;
	j_blank=3;
	game_button = new MyButton(200,50,200,50,"Unsolved");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
            char *s = new char[sizeof(int)];
	        sprintf(s,"%d",4*i+j+1);
			button[i][j] = new MyButton(100*j+100,100*i+100,100,100,s);
			button[i][j]->down_color(FL_RED);
		}
	}
	button[i_blank][j_blank]->label("");

	int x;
	cout << "Enter difficulty of the game(1 to 5): ";
    cin >> x;
	for(int i=0;i<10*x;i++){
		int r = rand()%4;
		if(r==0){
			if(i_blank+1>3) goto next;
			goto label1;	
		}
		if(r==1){
			if(j_blank+1>3) goto next;
			goto label2;
		}
		if(r==2){
			if(i_blank-1<0) goto next;
			goto label3;
		}
		if(r==3){
			if(j_blank-1<0) goto next;
			goto label4;
		}
		label1: exchange_buttons(i_blank+1,j_blank);goto end;
		label2: exchange_buttons(i_blank,j_blank+1);goto end;
		label3: exchange_buttons(i_blank-1,j_blank);goto end;
		label4: exchange_buttons(i_blank,j_blank-1);goto end;
		next: i--; goto last;
		last: continue;
		end:;
	}

	window->end();
	window->show();

	return(Fl::run());  // the process waits from here on for events
}