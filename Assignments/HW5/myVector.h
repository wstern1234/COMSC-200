#pragma once
#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

using namespace std;




template <typename T>
struct node {

    T item;
    node* next = nullptr;

    node(T x) :item(x) {}

};




template <typename T>
class myVector {

private:
    node<T>* head = nullptr;
    node<T>* tail = nullptr;


public:
    void push_back(T item);
    void pop_back();
    void display();

};




template <typename T>
void myVector<T>::push_back(T item) {

    node<T>* newNode = new node<T>{ item };

    if (!head) {
        head = newNode;
        return;
    }


    node<T>* current = head;

    while (current->next) {

        current = current->next;

    }

    current->next = newNode;

}




template <typename T>
void myVector<T>::pop_back() {

    node<T>* current = head;

    while (current->next) {

        tail = current;
        current = current->next;

    }

    tail->next = nullptr;
    delete current;

}




template <typename T>
void myVector<T>::display() {

    node<T>* p = head;


    while (p != nullptr) {

        cout << p->item << " ";
        p = p->next;

    }


    cout << endl;


}


#endif