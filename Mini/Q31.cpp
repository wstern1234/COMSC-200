#include <iostream>
using namespace std;

class Rectangle {

private:
    int width, height;


public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    friend void doubleIt(/*const*/ Rectangle&);
    friend Rectangle* tenTime(/*const*/ Rectangle&);
};
    
void doubleIt(/*const*/ Rectangle& param)
{
    param.width = param.width*2;
    param.height = param.height*2;
    
    return;
}
    
Rectangle* tenTime(/*const*/ Rectangle& param)
{
    param.width *= 10;
    param.height *= 10;

    return &param;
}


int main ()
{
    Rectangle bar (2,3);
    cout << "Before: " << bar.area() << '\n';
    
    doubleIt(bar);
    cout << "After doubleIt: " << bar.area() << '\n';
    
    // Rectangle foo = bar;
    // cout << "foo After: " << foo.area() << '\n';
    
    Rectangle * p = tenTime(bar);
    cout << "After tenTime: " << p->area() << '\n';
    
    return 0;
}