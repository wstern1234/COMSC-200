#include <iostream>

using namespace std;




template <typename T1, typename T2>
struct myPair {

    T1 first;
    T2 second;
    myPair<T1, T2>* next;

};




template <typename T1, typename T2>
class MyMap {

private:
    myPair<T1, T2>* head;
    myPair<T1, T2>* sorted;


    void insertionSort()
    {

        sorted = nullptr;
        myPair<T1, T2>* current = head;

        while (current != nullptr) {

            myPair<T1, T2>* next = current->next;

            sortedInsert(current);

            current = next;
        }

        head = sorted;
    }



    void sortedInsert(myPair<T1, T2>* newnode)
    {

        if (sorted == nullptr || sorted->first >= newnode->first) {
            newnode->next = sorted;
            sorted = newnode;
        }
        else {
            myPair<T1, T2>* current = sorted;

            while (current->next != nullptr
                && current->next->first < newnode->first) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }


public:

    

    bool insert(pair<T1, T2> pa) {

        myPair<T1, T2>* newPa = new myPair<T1, T2>{pa.first, pa.second};



        if (find(pa.first) == nullptr) {
            if (head != nullptr) {



                myPair<T1, T2>* new_node = new myPair<T1, T2>();

                /* 2. put in the data */
                new_node = newPa;

                /* 3. Make next of new node as head */
                new_node->next = head;

                /* 4. move the head to point to the new node */
                head = new_node;
                return true;

            }

            else {
                head = new myPair<T1, T2>{ newPa->first, newPa->second };
                head->next = nullptr;
                return true;
            }
        }

        return false;

    }


    myPair<T1, T2>* find(T1 key) {

        myPair<T1, T2>* current = head;
        while (current != nullptr)
        {
            if (current->first == key)
                return current;

            current = current->next;
        }
        return nullptr;

    }

    


    myPair<T1, T2>* begin() {
        return head;
    }



    myPair<T1, T2>* end() {
        return nullptr;
    }



    ~MyMap() {

        myPair<T1, T2>* temp = head;

        while (head) {

            temp = temp->next;
            delete head;
            head = temp;
        }

        delete temp;
    }



    void display() {

        insertionSort();

        myPair<T1, T2>* current = begin();

        while (current != end()) {

            cout << current->first << " -> " << current->second << endl;

            current = current->next;

        }

    }

};



int main()

{

    MyMap <char, int> mp1;







    mp1.insert(pair<char, int>('c', 300));
    mp1.insert(pair<char, int>('b', 200));

    mp1.insert(pair<char, int>('s', 904));

    mp1.insert(pair<char, int>('a', 100));

    mp1.insert(pair<char, int>('z', 900));
    mp1.insert(pair<char, int>('t', 203));



    bool ret = mp1.insert(pair<char, int>('z', 500));  /// This insertion should fail since the key exists

    if (ret == false)

    {

        cout << "element 'z' already existed" << endl;

    }

    else  /// True

        cout << "It is inserted." << endl;



    /* Test the find() function here with
    */
    // Return a pointer which points to the 'c' element

    // Modify the code here to show that the element

    // with the key 'c' is found.

    if (mp1.find('c')) {
        cout << mp1.find('c')->first << ": " << mp1.find('c')->second << endl;
    } else
        cout << "Not found" << endl;

    // Return a nullptr to indicate that the element cannot be found.

    // Modify the code here to show that the element

    // cannot be found.

    if (mp1.find('x')) {
        cout << mp1.find('x')->first << ": " << mp1.find('x')->second << endl;
    } else
        cout << "Not found" << endl;






    /// The following display() function will display

    ///  the values of elements in the form like

    ///             a -> 100

    /// which are sorted by the keys.

    /// This function should not be a member function

    /// of the map in STL.

    ///

    mp1.display();



    return 0;

}