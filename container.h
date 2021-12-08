#pragma once
#include <iostream>
#include <stddef.h>
#include <fstream>
#include "node.h"
#include <cstring>

using namespace std;


template <class T>
class Container {
	unsigned int number_of_elements;
public:
	Node<T> * first;
	Container();
	Container(Container<T> &c);
	~Container();
	void clear();
	void push_back(T e);
	void push_anywhere(T e, int index);
	void pop_anywhere(int index);
	void replace(int idx1, int idx2);

	Container<T>& operator=(const Container<T>&);
	Container<T>& operator+(const Container<T>&);

	int indexOf(const T&);
	void moveToFront(int idx);

	void outputFile();
	void inputFile();

};

template<class T>
Container<T>::Container()
{
	number_of_elements = 0;
	first = NULL;
}


template<class T>
Container<T>::~Container()
{
	clear();
}

template <class T>
void Container<T>::clear()
{

	Node<T> *temp = first;

	while (temp) {
		first = temp->next;
		delete temp;
		temp = first;
	}
	if (first)
		first = NULL;

	number_of_elements = 0;
}

template <class T>
void Container<T>::push_back(T e)
{
	Node<T> * new_node = new Node<T>;
	Node<T> *temp = first;

	new_node->next = nullptr;
	new_node->value = e;

	if (number_of_elements == 0) {
		first = new_node;
		new_node->previous = NULL;

	}
	else {

		temp = first;

		for (unsigned int i = 1; i < number_of_elements; i++)
			temp = temp->next;
		temp->next = new_node;
		new_node->previous = temp;

	}

	number_of_elements++;
}

template<class T>
inline void Container<T>::push_anywhere(T e, int index)
{
	try {
		Node<T> *new_node = new Node<T>;
		Node<T> *temp = new Node<T>;
		new_node->value = e;

		if (index > number_of_elements || index < 0 || index == 0)
			throw "Zly indeks przy wstawianiu elementu";


		if (index == number_of_elements) {
			push_back(e);
			number_of_elements++;

			return;
		}

		if (index == 1) {
			first->previous = new_node;
			new_node->next = first;
			new_node->previous = NULL;
			first = new_node;
			first->value = new_node->value;
			number_of_elements++;

			return;
		}

		for (int i = 1; i < index; i++)
			temp = temp->next;
		new_node->previous = temp->previous;
		temp->previous->next = new_node;
		temp->previous = new_node;
		new_node->next = temp;


		number_of_elements++;

	}
	catch (string s) {
		cout << s;
	}
}

template<class T>
inline void Container<T>::pop_anywhere(int index)
{
	try {
		Node<T>* temp = first;
		if (!number_of_elements)
			throw "Pusta lista";

			if (index == 1) {
				first = temp->next;
				first->previous = NULL;
				delete temp;
				number_of_elements--;
				return;
			}


		for (int i = 1; i < index; i++)
			temp = temp->next;

		if (index == number_of_elements) {
			temp->previous->next = NULL;



			delete temp;
			number_of_elements--;
			return;
		}

		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
		number_of_elements--;
	}
	catch (string s) {
		cout << s;
	}
}

template<class T>
inline void Container<T>::replace(int idx1, int idx2)
{
	try {
		Node<T> * temp1 = first;
		Node<T> * temp2 = first;
		T value;


		if (number_of_elements == 0 || idx1 == idx2 || !temp1 || !temp2)
			throw "bledne indeksy";

		for (int i = 1; i < idx1; i++)
			temp1 = temp1->next;
		value = temp1->value;

		for (int i = 1; i < idx2; i++)
			temp2 = temp2->next;
		temp1->value = temp2->value;
		temp2->value = value;
	}
	catch (string s) {
		cout << s;
	}
}



template<class T>
Container<T>::Container(Container<T>& c)
{
	try {
		Node<T> * temp = c.first;
		if (!c.number_of_elements)
			throw "Kontener do skopiowania nie ma elementow";
		for (unsigned int i = 1; i < c.number_of_elements; i++) {
			this->push_back(temp->value);
			temp = temp->next;

		}
		this->push_back(temp->value);
	}
	catch (string s) {

		cout << s;
	}
}

template <class T>
Container<T>& Container<T>::operator=(const Container<T> &c)
{
	Node<T>* temp = c.first;
	this->clear();

	for (unsigned int i = 1; i < c.number_of_elements; i++) {

		this->push_back(temp->value);
		temp = temp->next;
	}
	this->push_back(temp->value);
	return *this;
}

template<class T>
inline Container<T>& Container<T>::operator+(const Container<T>& c)
{
	/*
	Container<T>  result;

	Node<T>* temp = first;

	for (unsigned int i = 1; i < number_of_elements; i++) {
		result.push_back(temp->value);
		temp = temp->next;
	}
	result.push_back(temp->value);

	temp = c.first;

	for (unsigned int i = 1; i < c.number_of_elements; i++) {

		result.push_back(temp->value);
		temp = temp->next;
	}
	result.push_back(temp->value);

	
	return result;

	*/
}

template<class T>
inline int Container<T>::indexOf(const T &e)
{
	Node<T>*temp = first;
	if (temp->value == e)
		return 1;
	for (unsigned int i = 1; i < number_of_elements; i++) {
		if (temp->value == e)
			return i;
		temp = temp->next;
	}
	if (temp->value == e)
		return number_of_elements;
	
	cout << "Nie ma takiego elementu\n";
	return 0;


}

template<class T>
inline void Container<T>::moveToFront(int idx)
{
	try {
		if (!number_of_elements)
			throw "Lista pusta";
			Node<T> * temp = first;
		if (idx == 1)
			return;

		for (int i = 1; i < idx; i++)
			temp = temp->next;

		T value = temp->value;
		for (int i = idx; i > 1; i--) {
			temp->value = temp->previous->value;
			temp = temp->previous;
		}
		first->value = value;
	}
	catch (string s) {
		cout << s;
	}
}



template <class T>
void Container<T>::outputFile()
{
	try {
		fstream file;
		Node<T>* temp = first;

		file.open("wynik.txt", ios::out);//otwieranie pliku do zapisu
		if (file.is_open())
		{
			if (number_of_elements == 0)
			{
				file.close();
				return;
			}
			file << number_of_elements << "\n";
			for (unsigned int i = 1; i < number_of_elements; i++) {

				file << temp->value << "\n";
				temp = temp->next;
			}
			file << temp->value << "\n";
		}
		file.close();
	}
	catch (string s) {
		cout << s;
	}
}

template <class T>
void Container<T>::inputFile() {
	try {

		T  value;
		int number;
		fstream file;
		this->clear();

		file.open("dane.txt", ios::in);	//otwieranie pliku do odczytu
		if (file.good() == false) {
			throw  "Problem z plikiem";

		}
		file >> number;
		for (int i = 0; i < number; i++) {
			file >> value;
			this->push_back(value);
		}

		file.close();

	}

	catch (string s) {
		cout << s;
	}
}