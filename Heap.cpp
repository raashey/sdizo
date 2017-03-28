#include "Heap.h"
#include <iostream>
#include <fstream>

using namespace std;
bool Heap::loadFromFileH(){
	
	int n=0;
	int j,k;
	int v;
	fstream plik;
	plik.open("liczby.txt");
	plik>>size;
	tab=new int[size];
	if(plik.good()==false){
		cout<<"Plik zostal zle wczytany";
		return false;
	}
	for(int i=0; i<size; i++){
		j = n++;
		k = (j-1)/2;
		plik>>v;
  		while(j>0 && tab[k]<v){
    		tab[j] = tab[k];
    		j=k;
    		k=(j-1)/2;
  		}
		tab[j] = v;
	}
	plik.close();
	return true;	
}


void Heap::addValueToHeap(int value){
	
	int j,k;
	int* aux = new int [size+1];
	for(int i=0; i<size; i++)
		aux[i]=tab[i];
	aux[size]=value;
	size++;
	delete[] tab;
	tab=aux;
	j = size;
	k = (j-1)/2;
	while(j>0 && tab[k]<value){
		tab[j]=tab[k];
		j=k;
		k=(j-1)/2;
	}
	tab[j]=value;
}

void Heap::deleteFromHeap(int value){
	
	int index;
	for(int i=0;i<size;i++){
		if(tab[i]==value)
			index=i;	
	}
	int j,k,v;
	v=tab[size-1];
	j=index;
	k=2*index+1;
	tab[index]=tab[size-1];
	int* aux = new int [--size];
	for(int h=0; h<size; h++)
		aux[h]=tab[h];
	delete[] tab;
	tab=aux;
    while(k<size-1)
    {
      if(k+1 < size-1 && tab[k+1] > tab[k]) k++;
      if(v >= tab[k]) break;
      tab[j] = tab[k];
      j = k;
      k = 2*k+1;
    }
    tab[j] = v;
}
	


void Heap::display(){
	
	for(int i=0; i<size; i++)
		cout<<i+1<<". "<<tab[i]<<endl;
	
}

bool Heap::isValueInHeap(int value){
	
	for(int i=0; i<size; i++){
		if(tab[i]==value)
			return true;
	}
	return false;
				
}
