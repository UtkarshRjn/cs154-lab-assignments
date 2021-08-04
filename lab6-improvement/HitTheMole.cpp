//Program written by: Utkarsh Ranjan (200050147)
//Progam part of:CS 152/CS154 2021 Batch
// Program for: problem 6.1 (assignment 6, program 1) = HitTheMole.cpp (shapes2.cpp)

#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <iostream>

using namespace std;

#define Windows_x 800
#define Windows_y 800
#define Hole_COLOR 131
#define Hammer_COLOR 120
#define Mole_COLOR 72
#define Bob_COLOR 88
static const double refreshtime = 3.0;

void timeractions(void* p);

class Hole : public Fl_Widget{
    // This class is a subclass of the abstract superclass Fl_Widget with the definition of 
    // the function draw (which is a pure virtual function in the superclass Fl_Widget)
    protected:
    int x,y,w,h;
    public:
        Hole (int x,int y,int w, int h) : Fl_Widget (x,y,w,h) { 
            this->x=x; this->y=y;
            this->w=w; this->h=h;
        }
        virtual void draw(){
            fl_draw_box (FL_OFLAT_BOX, x, y, w, h,Hole_COLOR);
            fl_color(FL_WHITE);
            fl_pie (x+35,y-20,30,30,0,360);
        }
};

class MovingObject : public Fl_Widget{
    // An abstract class
    // This is a superclass with two child class Hammer and Mole.
    protected:
    int x, y, w, h;
    public:
        MovingObject(int x,int y,int w,int h): Fl_Widget(x,y,w,h){
            this->x=x; this->y=y;
		    this->w=w; this->h=h;
        }
    virtual void moveUp() = 0;
    virtual void moveDown() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    int handle(int e) {
			
	if (e==FL_KEYDOWN) {  // FL_KEYDOWN has been used to make use of keyboard for the controls of the game
		switch(Fl::event_key()){
                case 'w': // Up Arrow
                    moveUp();
                break;
                case 's': // Down Arrow
                    moveDown();
                break;
                case 'a': // Left Arrow
                    moveLeft();
                break;
                case 'd': // Right Arrow
                    moveRight();
                break;
                case 'q':
                    exit(0); // Exits the game
                break;
                default:
                break;
            }
		}
		return 1;
	}

};

class Hammer : public MovingObject {

// Not an abstract class
 public:
   Hammer (int x,int y,int w, int h) : MovingObject (x,y,w,h) { }
    // Bullet bullet;
    public:
	virtual void draw(){
        fl_draw_box (FL_RFLAT_BOX, x, y, w,h,Hammer_COLOR); // Handle of the hammer 
        fl_color(Bob_COLOR);
        fl_pie (x-7.5,y+95,2*w,2*w,0,360); // Bob of the hammer
    }

// wipe and refresh are not the functions of the MovingObject but these are used in moveUp/Down/Left/Right which are functions of a MovingObject
    virtual void wipe(){ 
        // Removes the object from its previous position
        fl_draw_box (FL_RFLAT_BOX, x, y, w,h,FL_WHITE);
        fl_color(FL_WHITE);
        fl_pie (x-7.5,y+95,2*w,2*w,0,360);
    }

    virtual void refresh(int x, int y) {
        // Redraws the object
        resize(x,y,w,h);
        fl_draw_box (FL_RFLAT_BOX, x, y, w,h,Hammer_COLOR);
        fl_color(Bob_COLOR);
        fl_pie (x-7.5,y+95,2*w,2*w,0,360);
   }

    void moveUp(){wipe();y-=10;refresh(x,y);}
    void moveDown(){wipe();y+=10;refresh(x,y);}
    void moveLeft(){wipe();x-=10;refresh(x,y);}
    void moveRight(){wipe();x+=10;refresh(x,y);}
};

class Mole : public MovingObject{

// Not an abstract class
    public:
        Mole (int x, int y, int w) : MovingObject(x,y,w,w) {}
        virtual void draw() {
            fl_color(Mole_COLOR);
            fl_pie (x,y,w,h,0,360);
        }
        virtual void wipe() {
            fl_color(FL_WHITE);
	        fl_pie (x,y,w,h,0,360);
        }
        virtual void refresh(int x, int y) {

            resize(x,y,w,h);
            fl_color(Mole_COLOR);
            fl_pie (x,y,w,h,0,360);
        }
   
    void moveUp(){wipe();y-=10;refresh(x,y);}
    void moveDown(){wipe();y+=10;refresh(x,y);}
    void moveLeft(){wipe();x-=10;refresh(x,y);}
    void moveRight(){wipe();x+=10;refresh(x,y);}
    friend void timeractions(void* p);
    void periodic(){

        fl_color(Mole_COLOR);
        fl_pie (Windows_x/2+200*(rand()%3-1)-15,Windows_y/2+200*(rand()%3-1)-30,30,30,0,360);
        fl_pie (Windows_x/2+200*(rand()%3-1)-15,Windows_y/2+200*(rand()%3-1)-30,30,30,0,360);
        fl_color(FL_WHITE);
        fl_pie (Windows_x/2+200*(rand()%3-1)-15,Windows_y/2+200*(rand()%3-1)-30,30,30,0,360);
        fl_pie (Windows_x/2+200*(rand()%3-1)-15,Windows_y/2+200*(rand()%3-1)-30,30,30,0,360);
        fl_pie (Windows_x/2+200*(rand()%3-1)-15,Windows_y/2+200*(rand()%3-1)-30,30,30,0,360);
    
        Fl::repeat_timeout (refreshtime,timeractions,this);
    }
};

void timeractions(void *p){ 
    //this is the function that provides periodicity to the program
	((Mole *)p)->periodic ();
}

void initgame(){
    // this function initiate holes and the hammer at the beggining of the game.
    new Hammer(Windows_x/2-7.5,Windows_y/2-155,15,100);
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            new Hole(Windows_x/2+200*i-50,Windows_y/2+200*j-10,100,20);
        }
    }
}

int main(int argc, char *argv[]) {
    Fl_Window *window;
    window = new Fl_Window (Windows_x,Windows_y,"HitTheMole"); // outer window`
    window->color(FL_WHITE);
    initgame();
    window->end();
    window->show();

    Fl::add_timeout(refreshtime, timeractions);
    return(Fl::run());  // the process waits from here on for events
}