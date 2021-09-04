#include <iostream>
#include <sstream>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use Fl_Button

using namespace std;

// class MyButton : public Fl_Button {
// 	int state;
// 	public:
// 		MyButton (int x, int y, int w, int h, const char *l); 
// 		int handle(int e); // e is incoming mouse event of different kinds
//  };

// MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
// 	state =0;
// }

// int MyButton :: handle (int e) {
// 	if (state ==0) { 
// 		this->label("00");
// 		state = 1;
// 	}
// 	else {
// 		this->label("11");
// 		state = 0;
// 	}
// 	return 1;
// }


char *int2charstar (int v) {
	char *s = new char[sizeof(int)];
	sprintf(s,"%d",v);
	return s;
}

class MyButton : public Fl_Button {
	int count;
	public:
		MyButton (int x, int y, int w, int h, const char *l); 
		int handle(int e); // e is incoming mouse event of different kinds
 };

MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
	count = 0;
}

int MyButton :: handle (int e) {
	if (e == FL_PUSH) { 
		label(int2charstar(count));
	}
	return 1;
};

int main(int argc, char *argv[]) {
    	Fl_Window *window;

window = new Fl_Window (600,600,"DEMO"); // outer window

		// Fl_Button *button1 = new Fl_Button(100,100,100,100,"Button1");
		// Fl_Button *button2 = new Fl_Button(300,300,100,100,"Button2");
		Fl_Button *button[4][4];
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				button[i][j] = new MyButton(100*j+100,100*i+100,100,100,int2charstar(j+4*i+1));
			}
		}
		button[3][3]->label(" ");
		window->end();
    	window->show();
    	
		int s = Fl::run();  // the process waits from here on for events
		cout << "exiting.....\n";

		return s;
}


