#include<conio.h>
#include<string>
#include<iostream>
#include "Table.h"
#include "List.h"

using namespace std;


//przykładowa implementacja tablicy ale tylko jest TYLKO szkielet 
//staramy się unikać używania funkcji we/wy w klasie (opócz metody  display)

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Wyswietl" << endl;
	cout << "6.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

  

void menu_table()
{
	char opt;
	int index, value;
	Table myTab;


	do{
		displayMenu("--- TABLICA ---");
		opt = getch();
		cout << endl;
		switch (opt){
		case '1': // Wczytywanie tablicy z pliku
			myTab.loadFromFileT();
			myTab.display();
			break;

		case '2': //Usuwanie elementu z tablicy
			cout << " Podaj index:";
			cin >> index;
			myTab.deleteFromTable(index);
			myTab.display();
			break;

		case '3': //Dodawanie elemetu do tablicy
			cout << " Podaj wartosc:";
			cin >> value;
			myTab.addValue(value);
			myTab.display();			
			break;

		case '4': //Znajdowanie elemetu w tablicy
			cout << "Podaj wartosc:";
			cin >> value;
			if (myTab.isValueInTable(value))
				cout << "Podana wartosc jest w tablicy";
			else
				cout << "Podanej wartosci NIE ma w tablicy";
			break;

		case '5':  //tutaj wyświetlanie tablicy
			myTab.display();
			break;

		case '6': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego 
			      // można sobie tu dodać własne case'y
			break;
		}

	} while (opt != '0');
}
void menu_list()
{
	char opt;
	int index, value;
	List myList;


	do{
		displayMenu("--- LISTA ---");
		opt = getch();
		cout << endl;
		switch (opt){
		case '1': // Wczytywanie tablicy z pliku
			myList.loadFromFileL();
			myList.display();
			break;

		case '2': //Usuwanie elementu z tablicy
			cout << " Podaj index:";
			cin >> index;
			myList.deleteFromList(index);
			myList.display();
			break;

		case '3': //Dodawanie elemetu do tablicy
			cout << " Podaj wartosc:";
			cin >> value;
			myList.addValue(value);
			myList.display();			
			break;

		case '4': //Znajdowanie elemetu w tablicy
			cout << " Podaj wartosc:";
			cin >> value;
			if (myList.isValueInList(value))
				cout << "Podana wartosc jest w tablicy";
			else
				cout << "Podanej wartosci nie ma w tablicy";
			break;

		case '5':  //tutaj wyświetlanie tablicy
			myList.display();
			break;

		case '6': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego 
			      // można sobie tu dodać własne case'y
			break;
		}

	} while (opt != '0');
}

void menu_heap()
{
	//analogicznie jak menu_table()
}

void menu_tree()
{
	
}
int main(int argc, char* argv[])
{

	char option;
	do{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "4.Drzewo czerwono-czarne" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";		
		option = getch();
		cout << endl;

		switch (option){
			
		case '1':
			menu_table();
			break;	
			
		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;

		case '4':
			menu_tree();
			break;		
		}

	} while (option != '0');
	

	return 0;
}
