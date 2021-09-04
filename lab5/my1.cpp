#include<iostream>
using namespace std;

class Student{
    protected:
        string university;
        int rollNo;
        string major;
    public:
        Student(string s1, int x, string s2){university = s1; rollNo = x;major = s2;}
        virtual void status() = 0;
        virtual void show(){
            cout << "University == " << university << endl;
            cout << "RollNo == " << rollNo << endl;
            cout << "Major == " << major << endl;
            cout << "-----------------\n\n";
        }
};

class Undergraduate : public Student{
    protected:
    string degree;
    public:
        Undergraduate(string s1, int x, string s2):Student(s1, x, s2){
            university = s1; 
            rollNo = x;
            major = s2;
            degree = "undegraduate";
        }
        virtual void status(){
            cout << "I am an " << degree << endl; 
        }
};

class Graduate : public Student{
    protected:
    string degree;
    public:
        Graduate(string s1, int x, string s2):Student( s1,  x, s2){
            university = s1; 
            rollNo = x;
            major = s2;
            degree = "graduate";
        }
        virtual void status(){
            cout << "I am a " << degree << endl; 
        }
};

class Masters : public Graduate{
    public:
        Masters(string s1, int x, string s2):Graduate( s1, x, s2){
            university = s1;
            rollNo = x;
            major = s2;
        }
        virtual void status(){ cout << "I am a " << degree << " pursuing Masters" << endl;}
};

class PHD : public Graduate{
    public:
        PHD(string s1, int x, string s2):Graduate( s1, x, s2){
            university = s1; 
            rollNo = x;
            major = s2;
        }
        virtual void status(){cout << "I am a " << degree << " pursuing PHD" << endl;}
};

class Btech : public Undergraduate{
    public:
        Btech(string s1, int x, string s2):Undergraduate( s1, x, s2){
            university = s1; 
            rollNo = x;
            major = s2;
        }
        virtual void status(){cout << "I am an " << degree << " pursuing Btech" << endl;} 
};

class BS : public Undergraduate{
    public:
        BS(string s1, int x, string s2):Undergraduate(s1, x, s2){
            university = s1; 
            rollNo = x;
            major = s2;
        }
        virtual void status(){cout << "I am an " << degree << " pursuing BS" << endl;}
};

class DualDegree : public Undergraduate{
    public:
        DualDegree(string s1, int x, string s2):Undergraduate(s1, x, s2){university = s1; rollNo = x;major = s2;}
        virtual void status(){cout << "I am an " << degree << " pursuing DualDegree" << endl;}

};

int main(int argc, char *argv[]){
    Student *s1;
    Student *s2;
    Undergraduate *ug1;
    Btech *btech1;
    PHD phd1("IITM",251000151,"Energy Engineering");

    s1 = new DualDegree("IITB",200070147,"Electrial Engineering");
    s1-> status(); s1->show();
    ug1 = new Undergraduate("IITD",200050126,"CSE");
    ug1-> status(); ug1->show();
    s1 = ug1;
    s1->status();s1->show();
    s2 = new Masters("IITK",200061450,"Civil Engineering");
    s2->status();s2->show();
    btech1 = new Btech("IITB",200041521,"Metallurgical Enginnering");
    s2 = btech1;
    s2->status();s2->show();
    phd1.status();phd1.show();
    
}