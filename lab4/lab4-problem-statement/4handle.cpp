#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Radio_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Light_Button.H> // needed to use the Fl_Box class

//Declaration of class and functions
class MyButton;
bool adjacent_buttons(int,int);
char *int2charstar (int);

// Definition of global variables
int i_blank, j_blank;
MyButton *button[4][4];

// Definition of class
class MyButton : public Fl_Button {
	int number,i,j;
	public:
		MyButton (int x, int y, int w, int h, const char *l); 
		int handle(int e); // e is incoming mouse event of different kinds
		void change_number(int x);
		int get_number(void);
};

MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
	number = atoi(l);
	j = (x - 100)/100;
	i = (y - 100)/100;
}

int MyButton :: handle (int e) {
	if (e == FL_PUSH && adjacent_buttons(i,j)) {
		if(i==i_blank && j == j_blank) return 1;// Ensures clicking the blank button doesn't do anything
		this->label("");
		button[i_blank][j_blank]->label(int2charstar(number)); // exchanges the label with the blank button
		button[i_blank][j_blank]->change_number(number); // exchanges the number associated with the blank button 
		i_blank = i;
		j_blank = j;
	}
	return 1;
}

void MyButton :: change_number(int x){number = x;}
int MyButton :: get_number(void){return number;}

// Definition of functions
bool adjacent_buttons(int i, int j){

	// This function ensures that only adjacent buttons are exchanged with the blank button
	
	if((i==i_blank && abs(j-j_blank)==1)||(j==j_blank && abs(i-i_blank)==1)) return true;
	else return false;
}

char *int2charstar (int v) {
	char *s = new char[sizeof(int)];
	sprintf(s,"%d",v);
	return s;
}

void init_game(){
	i_blank=3;
	j_blank=3;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			button[i][j] = new MyButton(100*j+100,100*i+100,100,100,int2charstar(j+4*i+1));
			button[i][j]->down_color(FL_RED);
		}
	}
	button[i_blank][j_blank]->label("");
}


int main(int argc, char *argv[]) {
	Fl_Window *window;

	window = new Fl_Window (600,600,"DEMO"); // outer window
	init_game();

	window->color(FL_WHITE);

	window->end();
	window->show();
	return(Fl::run());  // the process waits from here on for events
}