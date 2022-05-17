/*
On the top of the main.cpp file explain why the following statements:

cin.clear();
cin.ignore(32768, '\n');

are used.

cin.clear() resets the error flag on cin so that any other processes that run in the future function properly. cin.ignore(32768, '\n') goes to a new line so that any other unwanted input will be ignored and not cause the parsing process to fail. Furthermore, the next 32768 characters are skipped to protect the parsing process, so the code expects the input to not be abnormally large.




I       123456789   John      F
I       512434990   Mary      F
I       342432444   Peter     M
I       470068625   Jim       M
I       234324324   Tammy     F
I       121219000   Ester     F
U       123456789   John      M
D       10010       Ester     F
D       121219000   Ester     F
D       121219000   Ester     F
I       123456789   John      F
U       999999999   John      M

*/

#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    long long ssn;
    string name;
    char gender;
};

class StudentMgr {

private:
vector<Student> sList;

void insertStudent(long long, string, char);
void updateStudent(long long, string, char);
void deleteStudent(long long);
int findStudentIndex(long long);
//binary search using SSN
void sortBySSN();
int binarySearch(int, int, int);

public:
StudentMgr();
~StudentMgr();
void displayStudent(long long);
void displayAll();
};

StudentMgr::StudentMgr() {
    
/// TO DO: Add your code here
/// In each iteration of a while loop do the following:
/// Conduct an action. An action is one the following
/// 'I' - Insert the record. Use push_back to add the record to the end
/// of the vector sList. Sort the vector after all records are added.
/// If you use map, it does not have to be sorted.
///  'U' - Update the record
///  'D' - Delete the record

    
    string line;
    ifstream myfile;
    myfile.open("studentRecords2.txt");
    if (myfile.is_open()) {

        while (!myfile.eof()) {

            char instruct, gender;
            long long ssn;
            string tempName = "";

            myfile >> instruct >> ssn >> tempName >> gender;

            instruct = tolower(instruct);


            try {

                if (ssn < 1010001 || ssn > 999999999) {
                    throw ssn;
                }

                switch(instruct) {

                    case 'i':
                        insertStudent(ssn, tempName, gender);
                        sortBySSN();
                        break;
    
                    case 'u':
                        updateStudent(ssn, tempName, gender);
                        sortBySSN();
                        break;
    
                    case 'd':
                        deleteStudent(ssn);
                        break;
                    default:
                        throw instruct;
                
                }
                
            } catch (long long e) {

                cout << "Error prompt, SSN " << e << " is not a valid number." << endl;
                
            } catch (char e2) {

                cout << "Error prompt, \'" << e2 << "\' is not a valid action." << endl;
                
            }

            

        } // end while

    }
    
}




StudentMgr::~StudentMgr() {
    sList.clear();
}




void StudentMgr::insertStudent(long long ssn, string name, char gender) {

    try {
    
    for (int i = 0; i < sList.size(); i++) {
        
        if (sList.at(i).ssn == ssn)
            throw i;
        
    }

        sList.push_back( Student{ssn, name, gender} );
    } catch (int e) {
        cout << "Error prompt, SSN" << ssn << " record exists." << endl;
    }
    
}




void StudentMgr::updateStudent(long long ssn, string name, char gender) {

    bool isFound = false;
    int i;
   try {
    for (i = 0; i < sList.size(); i++) {
        if (sList.at(i).ssn == ssn) {
            sList.at(i) = Student{ssn, name, gender};
            isFound = true;
            }

        
        }

       if (!isFound)
           throw i;

       } catch (int e) {
       cout << "Error prompt, SSN " << ssn << " no such record." << endl;
       }
    
}




void StudentMgr::deleteStudent(long long ssn) {

bool isFound = false;
int i;
   try {
    
    for (int i = 0; i < sList.size(); i++) {

        if (sList.at(i).ssn == ssn) {
            sList.erase(sList.begin() + i);
            isFound = true;
        }
        
    }
       if (!isFound)
           throw i;
    } catch (int e) {
       cout << "Error prompt, SSN " << ssn << " no such record" << endl;
    }
    
}




void StudentMgr::displayStudent(long long ssn) {

    

    try {
        int index = findStudentIndex(ssn);
        
        if (sList.at(index).ssn == ssn) {
    
            cout << "SSN              Name                        Gender" << endl;
            cout << "---              ----                        ------" << endl;
            
            cout << left << setw(17) << sList.at(index).ssn << setw(28) << sList.at(index).name << sList.at(index).gender << endl;
            
        }
    } catch (int e) {
        cout << "Inputted SSN does not exist. Error Message: " << e << endl;
    }
    
}




void StudentMgr::displayAll() {
    
    cout << "SSN              Name                        Gender" << endl;
    cout << "---              ----                        ------" << endl;

    
    for (int i = 0; i < sList.size(); i++)
        cout << left << setw(17) << sList.at(i).ssn << setw(28) << sList.at(i).name << sList.at(i).gender << endl;
    
}




int StudentMgr::findStudentIndex(long long ssn) {
    
/// TO DO: Add your code here
/// Binary search should be conducted if you use vector.
/// If the record cannot be found, throw an integer -1 here to signal that
/// an exception has occurred.
    int index = binarySearch(ssn, 0, sList.size() - 1);

    if (index != 0) {
        if ( sList.at(index - 1).ssn == ssn)
            return (index - 1);
    }
    
    else
        throw -1;
    
}



//gives non-zeroed index
int StudentMgr::binarySearch(int ssn, int left, int right)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ( ssn == sList.at(mid).ssn )
            return mid + 1;
        else if ( ssn > sList.at(mid).ssn )
            left = mid + 1;
        else
            right = mid - 1;
    }
 
    return left;

    
}




void StudentMgr::sortBySSN() {
    
/// TO DO: Add your code here   
/// You may or may not need to use this function. You may append new record to the end of the   
/// vector. After all records are appended, sort all of them at a time.

    int i, loc, j, k;
    Student selected;
 
    for (i = 1; i < sList.size(); ++i)
    {
        j = i - 1;
        selected = sList.at(i);
 
        // find location where selected should be inseretd
        loc = binarySearch(selected.ssn, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            sList.at(j + 1) = sList.at(j);
            j--;
        }
        sList.at(j + 1) = selected;
    }
    
}





int main() {
    
    StudentMgr sm;
    char input;
    
    while (input != 'q') {
        
        cout << endl << endl << "Select an option:" << endl;
        cout << "-----------------" << endl << endl;
        cout << "A. Display all student info" << endl;
        cout << "S. Display specific student" << endl;
        cout << "Q. Quit the program" << endl;
        cout << "--------------------------------" << endl;
        cout << "Enter selection: ";
        
        cin >> input;
        cin.clear();
        cin.ignore(32768, '\n');
        
        input = tolower(input); 
        
        switch (input) {
            
            case 'a':
                sm.displayAll();
                break;
            
            case 's':
            {
                cout << "Input SSN: ";
                long long ssn;
                cin >> ssn;
                cin.clear();
                cin.ignore(32768,'\n');
                sm.displayStudent(ssn);
            }
            
        }
        
    }


    
    return 0;
}
