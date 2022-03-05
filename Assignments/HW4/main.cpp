#include <iostream> 
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;




const int SIZE = 99;

class Shape {
protected:
    string shapeType;
    int serialNumber;

public:
    Shape(string type, int serNum) {
        shapeType = type;
        serialNumber = serNum;
    }

    string getType() {
        return shapeType;
    }

    int getSerNum() {
        return serialNumber;
    }

    virtual void draw() = 0;
};




class Circle : public Shape {
protected:
    int radius;

public:
    Circle(string type, int serNum, int rad) : Shape(type, serNum) {
        radius = rad;
    }

    int getRadius() {
        return radius;
    }

    void draw() {

        for (int y = radius; y >= -radius; y -= 2) {
            for (int x = -radius; x <= radius; x++) {

                if ((int)(sqrt(pow(x, 2) + pow(y, 2))) <= radius) cout << "*";
                else cout << " ";

            }
            cout << endl;
        }

    }

};




class Spray : public Circle {
protected:
    int density;

public:
    Spray(string type, int serNum, int rad, int den) : Circle(type, serNum, rad) {
        density = den;
    }

    int getDensity() {
        return density;
    }

    void draw() {

        srand(time(0));
        int random;

        for (int y = radius; y >= -radius; y -= 2) {
            for (int x = -radius; x <= radius; x++) {
                random = rand() % 101;

                if ((int)(sqrt(pow(x, 2) + pow(y, 2))) <= radius && random <= density)
                    cout << "*";
                else
                    cout << " ";

            }
            cout << endl;
        }

    }
};




class Rectangle : public Shape {
protected:
    int height;
    int width;

public:
    Rectangle(string type, int serNum, int h, int w) : Shape(type, serNum) {
        height = h;
        width = w;
    }

    int getHeight() {
        return height;
    }
    int getWidth() {
        return width;
    }

    void draw() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cout << "* ";
            }
            
            cout << endl;
        }
    }

};




class Square : public Rectangle {
protected:

public:
    Square(string type, int serNum, int length) : Rectangle(type, serNum, length, length) {}

};




class MgrShape {

    Shape* arrShapes[SIZE] = { nullptr };


public:

    MgrShape() {

        string line;
        ifstream myfile;
        myfile.open("shaperecords.txt");
        if (myfile.is_open()) {

            while (!myfile.eof()) {

                getline(myfile, line);
                populateShapeData(line);


            }

        }

    } // end constructor

    void populateShapeData(string line) {
    
        string type;
        int serNum, length, dummy;
        stringstream ss(line);

        ss >> type >> serNum >> length >> dummy;

        int index = 0;
        while (arrShapes[index] != nullptr)
            index++;


        if (line[0] == 'C') {

            arrShapes[index] = new Circle(type, serNum, length);
            index++;

        }
        else if (line[0] == 'S') {

            arrShapes[index] = new Spray(type, serNum, length, dummy);
            index++;

        }
        else if (line[0] == 'R') {

            arrShapes[index] = new Rectangle(type, serNum, length, dummy);
            index++;

        }
        else if (line[0] == 'Q') {

            arrShapes[index] = new Square(type, serNum, length);
            index++;

        }

    }

    void displayAll() {

        for (Shape* shape : arrShapes) {
            if (shape != nullptr) {
                shape->draw();
                cout << endl << endl;
            }
        }

    } // end displayAll()

    ~MgrShape() {

        for (Shape* shape : arrShapes) {
            if (shape != nullptr)
                delete shape;
        }

    } // end displayAll()



};

//main function  
int main() {
    MgrShape ms;
    ms.displayAll();
    return 0;
}
