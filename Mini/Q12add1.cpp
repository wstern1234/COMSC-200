#include <iostream>

using namespace std;




class A {

public:
    virtual void print () {
      cout << "print A class" << endl;
    }

    void show () {
      cout << "show A class" << endl;
    }
};




class B : public A {

public:
///print () is already virtual function in A class, we could also declared as virtual void print () explicitly
    void print () {
      cout << "print B class" << endl;
    }

    void show () {
      cout << "show B class" << endl;
    }
};



// For Step 2 in Sample_Poly1.txt
class C : public B {};




int main()
{
  A *aPtr;
  B b;
  aPtr = &b;

  //virtual function, binded at runtime (Runtime polymorphism)
  aPtr->print();

  // Non-virtual function, binded at compile time
  aPtr->show();


  cout << "\n\nStep 2:" << endl;

  
// Lines 61-65 are for Step 2 in Sample_Poly1.txt
  C c;
  aPtr = &c;

// Line 65 uses print() from B because C publicly inherits the virtual function print() from class B
  aPtr->print();


  
  cout << "\n\n\nQ13:" << endl;



// For separate Q13 prompt: Write a C++ program to verify that in Redefining, the compiler chooses which function to call based upon the object reference rather than the actual type of the object. (Lines 74-78)
// We know B inherits from A, A* temp, and temp = new B. However, if temp->show() is called, then show() from A is called. Even though temp is a B and B has a show(), it still calls show() from A because of Redefining.
  
  A* temp;
  temp = new B();
  temp->show();



  return 0;
} // end main