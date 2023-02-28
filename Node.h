#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include "LinkedList.h"
#include "Composers.h"

using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node<T>* next;
public:
	Node();
	Node(T data);
	Node<T>* getNext() const;
	Node<T>* setNext(Node<T>* next);
	T getData() const;
	void setData(const T& data);
};

//default constructor that initializes next to nullptr
template<typename T>
Node<T>::Node() {
	next = nullptr;
}

//constructor that initializes data to the passed argument data and next to nullptr.
template <typename T>
Node<T>::Node(T data) {
	this->data = data;
	next = nullptr;
}

//function that returns the next node in the linked list.
template <typename T>
Node<T>* Node<T>::getNext() const {
	return next;
}

//function that sets the next node in the linked list to the passed argument next.
template <typename T>
Node<T>* Node<T>::setNext(Node<T>* next) {
	return this->next = next;
}

//function that returns the data stored in the node.
template <typename T>
T Node<T>::getData() const {
	return data;
}

//function that sets the data stored in the node to the passed argument data.
template <typename T>
void Node<T>::setData(const T& data) {
	this->data = data;
}