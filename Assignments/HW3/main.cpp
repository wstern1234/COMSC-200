/*
Part 1: (2 pts) Why “#ifndef RECTANGLE_H”, “#define RECTANGLE_H” and “#endif” have to be added to the .h file?

Their primary purpose is to prevent C++ header files from being included multiple times.




Part 2: (2 pts) Why the size of the array, i.e. 21, must be a const?

C++ forces arrays to have a constant size before the program to make sure nothing goes wrong in the memory.




Part 3: (2 pts) Why we prefer to let the array hold pointers to Rectangle, instead of Rectangle objects?

The size of pointers are always the same size and are typically smaller than objects. Therefore, pointers are much quicker/easier to work with

*/

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
#include "Rectangle.h"

const int SIZE = 21;

void display(Rectangle* []);
int squares = 0;
int hRect = 0;
int vRect = 0;

int main() {

    Rectangle* arrRect[SIZE] = { nullptr };

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {

        // Question 3
        /*
        arrRect[i] = new Rectangle();
        arrRect[i]->setWidth(2.0);
        arrRect[i]->setHeight(4.0);
        */

        // Question 4
        arrRect[i] = new Rectangle();

        int range = rand() % 7 + 1;
        int range2 = rand() % 7 + 1;

        arrRect[i] = new Rectangle(range, range2);
        arrRect[i]->setSerialNumber(10000 + i);

    }
    display(arrRect);

    for (Rectangle* rect : arrRect)
        delete rect;


} // main end

void display(Rectangle* arr[]) {



    cout << "Square\n=======================================" << endl;
    cout << "    Label         Width          Height" << endl;

    for (int i = 0; i < SIZE; i++) {
        string serNum = to_string(arr[i]->getSerialNumber());

        if (arr[i]->getWidth() == arr[i]->getHeight()) {
            cout << "    " << serNum.replace(0, 1, "R") << setw(14) << arr[i]->getWidth() << setw(16) << arr[i]->getHeight() << endl;
            squares++;
        }

    }

    cout << "=======================================" << endl;
    cout << "    Total" << setw(30) << squares << endl;




    cout << "\n\n\nHorizontal Rectangle\n=======================================" << endl;
    cout << "    Label         Width          Height" << endl;

    for (int i = 0; i < SIZE; i++) {
        string serNum = to_string(arr[i]->getSerialNumber());

        if (arr[i]->getWidth() > arr[i]->getHeight()) {
            cout << "    " << serNum.replace(0, 1, "R") << setw(14) << arr[i]->getWidth() << setw(16) << arr[i]->getHeight() << endl;
            hRect++;
        }

    }

    cout << "=======================================" << endl;
    cout << "    Total" << setw(30) << hRect << endl;




    cout << "\n\n\nVertical Rectangle\n=======================================" << endl;
    cout << "    Label         Width          Height" << endl;

    for (int i = 0; i < SIZE; i++) {
        string serNum = to_string(arr[i]->getSerialNumber());

        if (arr[i]->getWidth() < arr[i]->getHeight()) {
            cout << "    " << serNum.replace(0, 1, "R") << setw(14) << arr[i]->getWidth() << setw(16) << arr[i]->getHeight() << endl;
            vRect++;
        }

    }

    cout << "=======================================" << endl;
    cout << "    Total" << setw(30) << vRect << endl;

} // display end


/*
Question 1: Which parts of class Rectangle are data members? Are they public, private or protected?

The data members of Rectangle are serialNumber, width, and height. All three of these data members are private, hence the need for getters/setters.




Question 2: Which function(s) of class Rectangle is/are constructors, setters, getters or destructor?

The constructor is Rectangle(). The setters are setWidth(), setHeight(), and setSerialNumber(). The getters are getWidth(), getHeight(), and getSerialNumber(). The destructor is ~Rectangle().




Question 3: Delete the constructors and modify the code in main() to make the program work. Can a class have no constructor?

Yes, but it's much nicer and the standard to just use the constructor.




Question 4: Add the following two lines to a constructor which takes no parameter. Create 21 objects without providing any width or height. Display the width and height of these objects to see they are.
                width= 5.0;
                height = 7.0;
*/