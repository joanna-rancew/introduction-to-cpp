#include <iostream>
#include "container.h"
#include <string>
#include "product.h"
#include "factory.h"

using namespace std;

void testInt();
int menu();
void testProduct();
void testFactory();
void failCheck();

int main() {

	while (1)
	{
		switch (menu()) {
		case 1: {
			testInt();
			break;
		}
		case 2: {

			testProduct();
			break;
		}


		case 3: {
			testFactory();
			break;
		}
		case 4: {


			cout << "Koniec programu\n";
			system("pause");
			return 0;
		}
		default:
		{
			//throw
			break;
		}

		}
	}



	system("pause");
	return 0;

}

void testInt() {
	try {
		int choice;
		Container<int> c;

		while (1) {
			cout << "Test na int - menu:\n1. Powrot\n2. Zapis do pliku\n3. Odczyt z pliku\n";
			cout << "4. Dodaj element\n5. Usun element\n6. Zamien ze soba\n7. Znajdz indeks elementu";
			do {
				cout << "Twoj wybor:	";
				cin >> choice;
				failCheck();
			} while (choice < 0 || cin.fail());
			cout << endl;


			switch (choice) {
			case 1: {
				//powrot
				return;
				break;
			}
			case 2: {
				//zapis do pliku
				c.outputFile();
				break;
			}
			case 3: {
				c.inputFile();
				//odczyt z pliku
				break;
			}
			case 4: {
				//dodawanie elementu
				int element;
				cout << "Podaj element int:		";
				cin >> element;
				c.push_back(element);

				break;
			}
			case 5: {
				//usuwanie elementu

				int idx;
				cout << "Podaj indeks elementu int:		";
				cin >> idx;
				c.pop_anywhere(idx);
				break;
			}
			case 6: {
				//zamiana

				int i, j;
				cout << "Podaj indeksy elementow int:		";
				cin >> j;
				cin >> i;
				c.replace(i, j);
				break;
			}
			case 7: {
				//znajdz podany
				int element;
				cout << "Podaj element int:		";
				cin >> element;
				cout << "Element znajduje sie na miejscu: " << c.indexOf(element);
				break;
			}
			default: {
				break;
			}

			}
		}

	}
	catch (string s) {
		cout << s;
	}

}


int menu() {
	int choice;
	cout << "Menu:\n";
	cout << "1. Test na int\n" << "2. Test na obiektach klasy Product\n" << "3. Test Factory\n" << "4. Koniec programu" << endl;

	do {
		cout << "Twoj wybor:	";
		cin >> choice;
		failCheck();
	} while (choice < 0 || cin.fail());

	cout << "\n\n";


	return choice;
}

void failCheck() {

	//czyszczenie bledow wprowadzania
	try {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(200000, '\n');
			throw string("\nBledna wartosc\n");
		}

	}
	catch (string s) {
		cout << s;
	}
}

	void testProduct() {

		Container<Product> c;
		int choice;
		while (1) {
			cout << "Test na Product - menu:\n1. Powrot\n2. Zapis do pliku\n3. Odczyt z pliku\n";
			cout << "4. Przesun na przod\n5. Usun element\n6. Zamien ze soba";
			
			do {
				cout << "\n Twoj wybor: ";
				cin >> choice;
				failCheck();
			} while (choice < 0 || cin.fail());

			cout << endl;


			switch (choice) {
			case 1: {
				//powrot
				return;
				break;
			}
			case 2: {
				//zapis do pliku
				c.outputFile();
				break;
			}
			case 3: {
				c.inputFile();
				//odczyt z pliku
				break;
			}

			case 5: {
				//usuwanie elementu

				int idx;
				cout << "Podaj indeks elementu Factory:		";
				cin >> idx;
				c.pop_anywhere(idx);
				break;
			}
			case 6: {
				//zamiana

				int i, j;
				cout << "Podaj indeksy elementow Factory:		";
				cin >> j;
				cin >> i;
				c.replace(i, j);
				break;
			}
			case 4: {
				//Move to front
				int  j;
				cout << "Podaj indeks elementu Factory:		";
				cin >> j;
				c.moveToFront(j);
				break;
			}
			default: {
				break;
			}
			}


		}
	}
	
	void testFactory() {

		int choice;
		Container<Factory> c;

		while (1) {
			cout << "Test na Factory - menu:\n1. Powrot\n2. Zapis do pliku\n3. Odczyt z pliku\n";
			cout << "4. Przesun na przod\n5. Usun element\n6. Zamien ze soba";
			do {
				cout << "\n Twoj wybor: ";
				cin >> choice;
				failCheck();
			} while (choice < 0 || cin.fail());
			cout << endl;


			switch (choice) {
			case 1: {
				//powrot
				return;
				break;
			}
			case 2: {
				//zapis do pliku
				c.outputFile();
				break;
			}
			case 3: {
				c.inputFile();
				//odczyt z pliku
				break;
			}

			case 5: {
				//usuwanie elementu

				int idx;
				cout << "Podaj indeks elementu Factory:		";
				cin >> idx;
				c.pop_anywhere(idx);
				break;
			}
			case 6: {
				//zamiana

				int i, j;
				cout << "Podaj indeksy elementow Factory:		";
				cin >> j;
				cin >> i;
				c.replace(i, j);
				break;
			}
			case 4: {
				//Move to front
				int  j;
				cout << "Podaj indeks elementu Factory:		";
				cin >> j;
				c.moveToFront(j);
				break;
			}
			default: {
				break;
			}
			}
		}

	}