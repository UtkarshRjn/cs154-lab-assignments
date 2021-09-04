#define Windows_x 600
#define Windows_y Windows_x
#define button_edge 100

static const int f = Windows_x/button_edge;

class MyButton : public Fl_Button {
	int number,i,j;
	public:
		MyButton (int x, int y, int w, int h, const char *l); 
		int handle(int e); // e is incoming mouse event of different kinds
		void change_number(int x);
		int get_number(){return number;}
};