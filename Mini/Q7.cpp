#include <iostream>

using namespace std;

class Student
{
  int ID = 0;
  string Name = "";
  string Address = "";
  string phoneNum = "";

  public:
    Student(int id, string name, string address, string pNum) {

      if (id < 99999 && id > 10000)
        ID = id;
      else
        ID = -1;

      Name = name;
      Address = address;
      phoneNum = pNum;

    }

    int getID() {
      return ID;
    }
    string getName() {
      return Name;
    }
    string getAddress() {
      return Address;
    }
    string getPhoneNum() {
      return phoneNum;
    }
    
    void setID(int id) {
      if (id < 99999 && id > 10000)
        ID = id;
      else
        ID = -1;
    }
    void setName(string name) {
      Name = name;
    }
    void setAddress(string address) {
      Address = address;
    }
    void setPhoneNum(string pNum) {
      phoneNum = pNum;
    }
};

void displayarrStud(Student** arr, int SIZE)
{
for (int i = 0; i < SIZE; i++)
{
if (arr[i] != nullptr)
{
cout << "Student ID: " << arr[i]->getID() << endl;
cout << "Student Name: " << arr[i]->getName() << endl;
cout << "Student Address: " << arr[i]->getAddress() << endl;
cout << "Student Telephone: " << arr[i]->getPhoneNum() << endl;
cout << "---------------------------------------" << endl;
}
}
}

int main()
{
const int SIZE = 9;

/// Declare an array for holding the pointers of Student objects
/// Initialize all elements with nullptr
Student * arrStud[SIZE] = {nullptr};

/// Add the first student inf

arrStud[0] = new Student(0, "", "", "");
arrStud[0]->setID(12345);
arrStud[0]->setName("Amy");
arrStud[0]->setAddress("113 Main St., Livermore, CA 94578");
arrStud[0]->setPhoneNum("510-123-3454");

/// (12345, "Amy", "113 Main St. Livermore, CA 94578", "510-123-3454")
/// into the array.

/// Add the second student info

arrStud[1] = new Student(0, "", "", "");
arrStud[1]->setID(22387);
arrStud[1]->setName("Bill");
arrStud[1]->setAddress("Apt #4, Diablo Ave. Pleasant Hill, CA 94455");
arrStud[1]->setPhoneNum("925-456-9082");

/// (22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082")
/// into the array.

/// Add the third student info


arrStud[2] = new Student(0, "", "", "");
arrStud[2]->setID(22387);
arrStud[2]->setName("Carl");
arrStud[2]->setAddress("Apt #8, Diablo Ave. Pleasant Hill, CA 94455");
arrStud[2]->setPhoneNum("925-765-8979");

/// (22387, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455". "925-765-8979")
/// into the array.

/// Add the fourth student info


arrStud[3] = new Student(0, "", "", "");
arrStud[3]->setID(555556);
arrStud[3]->setName("Err");
arrStud[3]->setAddress("666 Main St. Walnut Creek, CA 94589");
arrStud[3]->setPhoneNum("510-555-6666");

/// (555556, "Err", "666 Main St. Walnut Creek, CA 94589", "510-555-6666")
/// into the array.

/// Check size of the array
cout << "The size of the arrStud: " << sizeof(arrStud) << endl;

/// The following display() function will display the information of all students in the array
/// The function should check if an element is null first. If it is not null, the information is displayed.
/// display(arrStud, SIZE);
cout << "Display the data in arrStud" << endl;

displayarrStud(arrStud, SIZE);

for (int i = 0; i < SIZE; i++)
{
  if (arrStud[i] != nullptr)
  {
    delete arrStud[i];
  }
}
// Message in template

return 0;
}