#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>
class Node {
public:
	T value;

	Node * next;
	Node * previous;


public:
	Node();
	~Node();
	friend ostream& operator<<(ostream &s, Node &b) { return s << b.value << "\n"; }
	T getValue() { return value; }

};

template<class T>
Node<T>::Node()
{
	
	next = NULL;
	previous = NULL;
}

template<class T>
Node<T>::~Node() {
	
	Node *temp1 = new Node;
	temp1 = previous;
	if(previous)
	temp1->next = next;

	Node *temp2 = new Node;
	temp2 = next;
	if(next)
	temp2->previous = previous;
	
}


