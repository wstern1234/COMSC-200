#include <iostream>
using namespace std;

template<class T>
class Deque {
    struct listNode {
        T data;
        int index = 0;  /// the index for the element
        listNode* next = nullptr;
        listNode* previous = nullptr;
    };
    listNode* head = nullptr;
    listNode* tail = nullptr;

public:
    ~Deque() {
        /// ADD YOUR CODE HERE
        /// Release all dynamically allocated memory
        tail = head;

        while (head) {

            tail = tail->next;
            delete head;
            head = tail;
        }

        delete tail;
    }

    void push_back(T value) {

        listNode* newNode = new listNode {value};

        if (tail == nullptr)
            head = tail = newNode;
            
        else {
            
            newNode->previous = tail;
            newNode->index = newNode->previous->index + 1;
            
            tail->next = newNode;
            tail = newNode;
            
        }
        
    }

    void push_front(T value) {
        
        listNode* newNode = new listNode {value};

        if (head == nullptr)
            tail = head = newNode;
            
        else {
            
            newNode->next = head;
            head->previous = newNode;
            head = newNode;


            listNode* current = head->next;

            while (current != nullptr) {
    
                current->index += 1;
                current = current->next;
    
            }
            
        }
        
    }

    void display_forward() {
        /// ADD YOUR CODE HERE
        /// Display the values in the list from head to tail
        /// Use the link next to move the next node. (Do NOT use index.)

        listNode* current = head;

        while (current != nullptr) {

            cout << current->index << ". " << current->data << endl;

            current = current->next;

        }
        
    }

    void display_backward() {
        /// ADD YOUR CODE HERE
        /// Display the values in the list from tail to head
        /// Use the link previous to move the previous node. (Do NOT use index.)

        listNode* current = tail;

        while (current != nullptr) {

            cout << current->index << ". " << current->data << endl;

            current = current->previous;

        }

    }

    T operator[](int index) {
        /// ADD YOUR CODE HERE
        /// With the index, the value of the element is displayed

        listNode* current = head;

        while (current != nullptr) {

            if (current->index == index) {
                return current->data;
            }

            current = current->next;

        }
        
    }

    int size()
    {
        int sz = 0;
        /// ADD YOUR CODE HERE
        /// Return the size of the list

        listNode* current = head;

        while (current != nullptr) {

            sz++;
            current = current->next;

        }
        
        return sz;
    }
};

int main() {

    Deque<int> deque1;
    deque1.push_back(11);
    deque1.push_back(22);
    deque1.push_back(33);
    cout << "Checking push_back()" << endl;
    deque1.display_forward();  /// Should display   11  22  33
    cout << "\n" << endl;
    deque1.display_backward();  /// Should display   33  22  11

    deque1.push_front(0);
    cout << endl << endl << "Checking push_front()" << endl;
    deque1.display_forward();  /// Should display   0  11  22  33
    deque1.display_backward();  /// Should display   33  22  11  0

    cout << endl << endl << "Checking operator []" << endl;
    for (int i = 0; i < deque1.size(); i++)
    {
        cout << deque1[i] << endl;
    }

    return 0;
}