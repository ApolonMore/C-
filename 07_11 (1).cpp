#include <iostream>
#include <cmath>

using namespace std;

class figure{
    protected:
    double x,y;
    public:
    figure(){
        x=0;
        y=0;
    }
    figure(double nx, double ny){
        x=nx;
        y=ny;
    }
    void virtual print(){
        cout << "("<<x<<","<<y<<")";
    }
    double virtual area()=0;
    double virtual lenth()=0;
};
class circle : public figure {
    protected:
    double r;
    public:
    circle (double nx, double ny, double nr){
        x=nx;y=ny;r=nr;
    }
    double area(){
        return r*r*4*atan(1);
    }
    double lenth(){
        return 2*r*4*atan(1);
    }
};
class square : public figure{
    protected:
    double f;
    public:
    square (double nx, double ny, double nf){
        x=nx;y=ny;f=nf;
    }
    double area(){
        return f*f*4;
    }
    double lenth(){
        return 4*f;
    }
    void print(){
        cout<<"("<<x<<","<<y<<"),"<<"("<<x+f<<","<<y<<")"<<","<<"("<<x<<","<<y-f<<")"<<","<<"("<<x+f<<","<<y-f<<")";
    }
};

int main()
{
    figure *p;
    //circle *c;
    //p=new figure(2,3);
    //p->print();
    //cout<<endl;
    //p=new circle(3,4,5);
    //p->print();
    //cout<<endl;
    //cout<<p->area()<<" "<<p->lenth()<<endl;
    p=new square(5,6,3);
    p->print();
    cout<<endl;
    cout<<p->area()<<" "<<p->lenth()<<endl;
    return 0;
}