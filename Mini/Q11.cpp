#include <iostream>

using namespace std;




class A {

public:
  int pub_Int = 0;

};


class B : public A {

public:
  B() {

    pub_Int += 1;

  }

};


class C : private B {

public:
  C() {

    pub_Int += 10;

  }

  int getPubInt () {
    return pub_Int;
  }

};


int main() {

  B test1 = B();

  cout << test1.pub_Int << endl;


  C test2 = C();

  cout << test2.getPubInt() << endl;


  delete[] &test1;
  delete[] &test2;



  return 0;
}