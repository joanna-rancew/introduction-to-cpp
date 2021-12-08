#pragma once
#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;
class Product {
public:
	///konstruktor klasy Product
	/**konstruktor kopiujacy, operator przypisania - domyslne */
	Product(std::string = "Produkt bez nazwy", int = 0);

	///destruktor klasy Product
	~Product();

	///funkcja ustawiania ceny 
	void setPrice(int p);
	///funkcja zwracajaca cene
	int getPrice() { return price; }

	///funkcja ustawiania nazwy marki
	string getBrand() { return brand; }
	///funkcja zwracajaca nazwe marki
	void setBrand(string b);



	///OPERATOR STRUMIENIOWY:
		/**	zwraca uporzadkowane dane o Beauty Salon na strumien postaci:
		brand
		price

		w string*/
	friend ostream& operator<<(ostream &s, Product &b);
	///funkcja odczytu z pliku
	void inputFile();
	///funkcja zapisu do pliku
	void outputFile();
	friend Product& operator>>(iostream &s, Product &p);


private:
	int price; ///<cena klasy Product
	std::string brand; ///<nazwa marki klasy Product

};




Product::Product(std::string n, int p)
{

	this->price = p;
	this->brand.clear();
	this->brand.insert(0, n);

}


Product::~Product() {


}

void Product::setPrice(int p)
{
	this->price = p;
}

void Product::setBrand(string b)
{
	brand = b;
}

void Product::inputFile()
{
	fstream file;


	file.open("daneproduct.txt", ios::in);//otwieranie pliku do odczytu
	if (file.good() == false) {
		cout << "Problem z plikiem";
		return;
	}

	file >> brand;
	file >> price;


	file.close();
}

Product& operator>>(iostream &s, Product &p) {
	
	s >> p.brand;
	s >> p.price;
	return p;
}

void Product::outputFile()
{
	fstream file;

	file.open("product1.txt", ios::out);	//otwieranie pliku do zapisu
	if (file.is_open())
		file << *this;

	file.close();
}

ostream& operator<<(ostream &s, Product &p) {

	return  s << p.brand << p.price;


}

