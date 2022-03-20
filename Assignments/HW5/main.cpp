/*

Why we normally place the entire class template in the .h file? (Another way to ask the question is that why the entire class template, including the declaration and definition, has to be included?) Be sure to elaborate your points.

All has to be together before compiled for compiler (FIX)

*/




#include <iostream>
#include "myVector.h"

using namespace std;




int main() {
    
    cout << "This is a <vector> copy for practice called myVector\n\n\n" << endl;

    
    
    myVector<int> myVect;

    cout << "First myVector" << endl;
    
    for (int i = 1; i <= 10; i++)
        myVect.push_back(i);
    
    myVect.display();

    myVect.pop_back();
    myVect.display();



    
    myVector<string> myVect2;

    cout << "\n\nSecond myVector" << endl;
    
    myVect2.push_back("This");
    myVect2.push_back("is");
    myVect2.push_back("a");
    myVect2.push_back("test");
    myVect2.push_back("sentence");
    myVect2.display();

    myVect2.pop_back();
    myVect2.display();



    return 0;

}