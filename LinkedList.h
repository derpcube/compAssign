#pragma once

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Composers.h"
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();
    void printList() const;
    void append(const T data);
    void prepend(const T data);
    void sortByDate();
    bool removeFront();
    void insert(const T data);
    bool remove(const T data);
    bool find(const T data);
    bool isEmpty() const;
    void swap(Node<T>* a, Node<T>* b);
    T getFirst() const;
    T getLast() const;
    ~LinkedList();
};

//default constructor that initializes the head and tail to null
template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
}

//destructor that frees the memory allocated by the list
template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;

    while (current != NULL) {
        Node<T>* temp = current->getNext();

        delete current;

        current = temp;
    }
}

//prints the data in the list
template <typename T>
void LinkedList<T>::printList() const {
    Node<T>* current = head;

    while (current != NULL) {
        cout << current->getData() << " ";
        current = current->getNext();
    }

    cout << endl;
}

//adds a new node to the end of the list with the given data
template <typename T>
void LinkedList<T>::append(const T data) {
    Node<T>* node = new Node<T>;

    node->setData(data);
    node->setNext(NULL);

    if (head == NULL) {
        head = node;
        tail = node;
    }
    else {
        tail->setNext(node);
        tail = node;
    }
}

//adds a new node to the beginning of the list with the given data
template <typename T>
void LinkedList<T>::prepend(const T data) {
    Node<T>* node = new Node<T>;

    node->setData(data);
    node->setNext(head);

    if (head == NULL) {
        tail = node;
    }

    head = node;
}

//removes the first node from the list
template <typename T>
bool LinkedList<T>::removeFront() {
    if (head != NULL) {
        Node<T>* temp = head->getNext();

        delete head;

        head = temp;

        return true;
    }

    return false;
}

//inserts a new node into the list in the correct position
template <typename T>
void LinkedList<T>::insert(const T data) {
    Node<T>* node = new Node<T>;
    node->setData(data);

    if (head == NULL) {
        // The list is empty, so make the new node the head and tail
        head = node;
        tail = node;
    }
    else if (data < head->getData()) {
        // The new node should be the new head
        node->setNext(head);
        head = node;
    }
    else {
        // Find the appropriate location to insert the new node
        Node<T>* current = head;

        while (current->getNext() != NULL &&
            data > current->getNext()->getData()) {
            current = current->getNext();
        }

        // Insert the new node after the current node
        node->setNext(current->getNext());
        current->setNext(node);

        // If the new node is the last node, update the tail pointer
        if (node->getNext() == NULL) {
            tail = node;
        }
    }
}

//removes the first occurrence of the node with the given data
template <typename T>
bool LinkedList<T>::remove(const T data) {
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current) {
        if (current->getData() == data) {
            if (previous == nullptr) {
                head = current->getNext();
            }
            else {
                previous->setNext(current->getNext());

                if (current == tail) {
                    tail = previous;
                }
            }
            delete current;
            return true;
        }

        previous = current;
        current = current->getNext();
    }

    return false;
}

//searches the list for a node with the given data and returns true if found, false otherwise
template <typename T>
bool LinkedList<T>::find(const T data) {
    Node<T>* current = head;
    while (current != NULL) {
        if (current->getData() == data) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

//returns true if the list is empty, false otherwise
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return head == NULL;
}

//returns the data in the first node of the list
template <typename T>
T LinkedList<T>::getFirst() const {
    return head->getData();
}

//returns the data in the last node of the list
template <typename T>
T LinkedList<T>::getLast() const {
    return tail->getData();
}

//sorts the list using bubble sort by the death year of the composers in ascending order
template <typename T>
void LinkedList<T>::sortByDate() {
    // Check if the list is empty or has only one element
    if (head == NULL || head->getNext() == NULL) {
        return;
    }

    // Use a sorting algorithm to sort the list by date
    bool swapped = true;
    Node<T>* ptr1 = head;
    Node<T>* ptr2 = NULL;

    while (swapped) {
        swapped = false;
        ptr1 = head;

        while (ptr1->getNext() != ptr2) {
            if (ptr1->getData().getDeathYear() >
                ptr1->getNext()->getData().getDeathYear()) {
                swap(ptr1, ptr1->getNext());
                swapped = true;
            }
            ptr1 = ptr1->getNext();
        }
        ptr2 = ptr1;
    }
}

//swaps two nodes
template <typename T>
void LinkedList<T>::swap(Node<T>* a, Node<T>* b) {
    T temp = a->getData();
    a->setData(b->getData());
    b->setData(temp);
}
