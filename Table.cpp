#include "Table.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;
int Table::loadFromFileT(){
	
	fstream plik;
	plik.open("liczby.txt");
	plik>>amount;
	tab=new int[amount];
	if(plik.good()==false)
		cout<<"Plik zostal zle wczytany";
	for(int i=0; i<amount; i++)
		plik>>tab[i];
	plik.close();
	return 1;		
}

bool Table::isValueInTable(int val){
	
	for(int i=0; i<amount; i++){
		if(this->tab[i]==val)
			return true;
	}
	return false;
				
}

void Table::addValue(int value){
	
	amount++;
	int *aux=new int [amount];
	for(int i=0; i<amount-1; i++){
		aux[i]=tab[i];
	}
	aux[amount-1]=value;
	delete[] tab;
	tab=aux;
}

void Table::deleteFromTable(int index){
	
	amount--;
	int *aux = new int [amount];
	for(int i=0; i<amount+1; i++){
		if(i==index-1)
			continue;
		if(i<index-1)
			aux[i]=tab[i];
		else
			aux[i-1]=tab[i];		
			
	}
	delete[] tab;
	tab=aux;	
	
}

void Table::display(){
	
	for(int i=0; i<amount; i++)
		cout<<i+1<<". "<<tab[i]<<endl;
	
}
