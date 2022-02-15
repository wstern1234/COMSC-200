#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;




struct ShipRecord
{
    int serialNum = 0;
    int shipType = 0;
    string name = "";
    int year = 0;
    int cap = 0;
    ShipRecord* link = nullptr;
};

const int SIZE = 10;




class HashMgr {

    ShipRecord* hashTable[SIZE] = { nullptr };

public:
    HashMgr() {
        string line;
        ifstream myfile;
        myfile.open("shipRecords.txt");
        if (myfile.is_open()) {

            while (!myfile.eof()) {

                getline(myfile, line);
                addInfo(line);
            }

            myfile.close();
        }
    }


    ~HashMgr() {
        for (ShipRecord* i : hashTable) {
            delete i;
        }
    }

    void addInfo(string line) {


        int tempSerial, tempType, tempYear, tempCap;
        string tempName;
        stringstream ss(line);
        ShipRecord* ship;

        ss >> tempSerial >> tempType >> tempName >> tempYear >> tempCap;

        int index = tempSerial % 10;


        ship = new ShipRecord{ tempSerial, tempType, tempName, tempYear, tempCap };



        if (hashTable[index] != nullptr) {



            ShipRecord* new_node = new ShipRecord();

            /* 2. put in the data */
            new_node = ship;

            /* 3. Make next of new node as head */
            new_node->link = hashTable[index];

            /* 4. move the head to point to the new node */
            hashTable[index] = new_node;

        }

        else {
            hashTable[index] = new ShipRecord{ tempSerial, tempType, tempName, tempYear, tempCap };
            hashTable[index]->link = nullptr;
        }

    } // func end




    void displayOne(int serialNum) {

        bool found = false;
        bool bucket = false;

        for (ShipRecord* ship : hashTable) {

            if (ship != nullptr) {

                while (ship->link != nullptr) {

                    if (bucket == false && ship->serialNum == serialNum) {
                        cout << "Bucket #" << (ship->serialNum % 10) << endl;
                        bucket = true;
                    }

                    if (ship->serialNum == serialNum) {
                        cout << "    " << ship->serialNum << "  " << ship->shipType << " " << ship->name << setw(25 - ship->name.length()) << ship->year << "   " << ship->cap << endl;
                        found = true;
                        break;
                    }

                    ship = ship->link;
                }


                if (ship->serialNum == serialNum && found == false) {

                    if (bucket == false && ship->serialNum == serialNum) {
                        cout << "Bucket #" << (ship->serialNum % 10) << endl;
                        bucket = true;
                    }

                    cout << "    " << ship->serialNum << "  " << ship->shipType << " " << ship->name << setw(25 - ship->name.length()) << ship->year << "   " << ship->cap << endl;
                    found = true;
                    break;

                }
            }

        }


        if (found == false)
            cout << "\n\n    " << "The record (serial number: " << serialNum << ") does not exist." << endl;

    } // func end




    void displayAll() {

        ///*


        for (ShipRecord* ship : hashTable) {

                

            if (ship != nullptr) {

                cout << "Bucket #" << (ship->serialNum % 10) << endl;

                if (ship->link != nullptr) {

                    while (ship->link != nullptr) {

                        cout << "    " << ship->serialNum << "  " << ship->shipType << " " << ship->name << setw(25 - ship->name.length()) << ship->year << "   " << ship->cap << endl;
                        ship = ship->link;

                    }

                }



                cout << "    " << ship->serialNum << "  " << ship->shipType << " " << ship->name << setw(25 - ship->name.length()) << ship->year << "   " << ship->cap << endl;

            }

        }

    } // func end


    void deleteOne(int serialNum) {

        ShipRecord* temp = hashTable[serialNum % 10];
        ShipRecord* prev = NULL;


        if (temp != NULL && temp->serialNum == serialNum)
        {
            hashTable[serialNum % 10] = temp->link;
            delete temp;
            return;
        }

        
        else
        {
            while (temp != NULL && temp->serialNum != serialNum)
            {
                prev = temp;
                temp = temp->link;
            }

            if (temp == NULL)
                return;

            prev->link = temp->link;

            delete temp;
        }

    } // func end

};


int main() {

    HashMgr hm;
    cout << "displayAll()" << endl << endl;
    hm.displayAll();
    cout << "-----------------------------------------------------------\n\n\n" << endl;
    cout << "displayOne()" << endl << endl;
    hm.displayOne(1010);
    hm.displayOne(1009);
    hm.displayOne(1019);
    hm.displayOne(1029);
    hm.displayOne(1039);
    hm.displayOne(1014);
    hm.displayOne(1008);
    cout << "-----------------------------------------------------------\n\n\n" << endl;
    hm.deleteOne(1010);
    hm.deleteOne(1009);
    hm.deleteOne(1039);
    cout << "displayAll() with deleted records" << endl << endl;
    hm.displayAll();




    return 0;

} // func end