#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Factory {

public:

	Factory(std::string = "Anonim", float = 0, int = 0, int = 0);
	~Factory();

	float getArea() { return area; }
	std::string getName() { return name; }
	int getNumberOfEmployees() { return number_of_employees; }
	int getNumberOfProducts() { return number_of_products; }

	friend Factory& operator>>(iostream &s, Factory &p);
	friend ostream& operator<<(ostream &s, Factory &b);
	Factory& operator=(const Factory&);
	friend bool operator==(Factory&, const Factory&);

private:
	float area;
	std::string name;
	int number_of_employees;
	int number_of_products;


};

Factory::Factory(std::string name, float area, int number_of_employees, int number_of_products)
{

	//przygotowywanie miejsca dla pracownikow w zaleznosci od ilosci
	this->number_of_employees = number_of_employees;


	this->area = area;

	//dopisanie do pustej nazwy imienia po 0
	this->name.insert(0, name);


	if (number_of_products) {
		this->number_of_products = number_of_products;
	}
	else {

		this->number_of_products = 0;
	}

}

inline Factory::~Factory()
{
}

inline Factory & Factory::operator=(const Factory &f)
{
	this->area = f.area;
	this->name = "";
	this->name.insert(0, f.name);
	this->number_of_employees = f.number_of_employees;
	this->number_of_products = f.number_of_products;
	return *this;
}

inline bool operator==(Factory&e, const Factory &f)
{
	if (e.area != f.area)
		return false;

	if (e.number_of_employees != f.number_of_employees)
		return false;

	if (e.number_of_products != f.number_of_products)
		return false;


	return true;
}



Factory & operator>>(iostream & s, Factory & p)
{
	p.name = "";
	s >> p.area;
	s >> p.name;
	s >> p.number_of_employees;
	s >> p.number_of_products;


	return p;
}


inline ostream & operator<<(ostream & s, Factory & p)
{
	s << p.area << "\n";
	s << p.name << "\n";
	s << p.number_of_employees << "\n";
	s << p.number_of_products;
	return s;
}