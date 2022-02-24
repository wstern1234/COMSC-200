#include <iostream>

using namespace std;




struct Student
{
    int ID = 0;
    string name = "";
    string address = "";
    string phoneNum = "";
};

void display(Student* arr[], const int SIZE);




int main() {
  
    const int SIZE = 9;

    /// Declare an array for holding the pointers of Student objects
    /// Initialize all elements with nullptr
    Student * arrStud[SIZE] = {nullptr};

    /// Add the first student info
    ///  (12345, "Amy", "113 Main St. Livermore, CA 94578",  "510-123-3454")

    Student stu1 = {12345, "Amy", "113 Main St. Livermore, CA 94578",  "510-123-3454"};

    arrStud[0] = &stu1;

 
 
    /// Add the second student info
    ///  (22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082")

    Student stu2 = {22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082"};

    arrStud[1] = &stu2;

  
  
    /// Add the third student info
    ///  (22387, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455", "925-765-8979")

    Student stu3 = {22387, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455", "925-765-8979"};

    arrStud[2] = &stu3;



    /// The following display() function will display the information of all students in the array
    /// The function should check if an element is null first. If it is not null, the information is displayed.
    display(arrStud, SIZE);

    
    return 0;
}


void display(Student* arr[], const int SIZE) {

  for (int i = 0; i < SIZE; i++) {

    if (arr[i] != nullptr) {

      cout << arr[i]->name << endl;
      cout << "================" << endl;
      cout << "ID: " << arr[i]->ID << endl;
      cout << "address: " << arr[i]->address << endl;
      cout << "phone number: " << arr[i]->phoneNum << endl;
      cout << endl << endl << endl;

    }

  }

}
