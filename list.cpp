#include "List.h"
#include <iostream>
#include <fstream>

int List::sizeOfList(){
	
	return counter;
	
}

List::doubleList * List::loadFromFileL(char* fileName){
	
	doubleList* e;
	fstream plik;
	plik.open(fileName,ios::in);
	if(plik.good()==false)
		cout<<"Plik zostal zle wczytany";
	plik>>amount;
	for(int i=0; i<amount; i++){
	 
		plik>>e->data; 
	  	if(tail) tail->next = e;
      	e->next = NULL; 
		e->prev = tail;
      	tail = e;
     	if(!head) head = tail;
     	counter++;	
	}
}

bool List::isValueInList(int val){
	
	doubleList* e;
	e=head;
	while(e){
		if(e->data=val)
			return true;
		e=e->next;	
	}
	return false;	
}

void List::addValue(int value){
	
	doubleList* e;
	e->data=value;
	if(tail) 
		tail->next = e;
    e->next = NULL; 
	e->prev = tail;
    tail = e;
    if(!head) 
		head = tail;
    counter++;
}

void List::deleteFromList(int index){
	
	doubleList* e= new doubleList;
	doubleList* p= new doubleList;
	doubleList* n= new doubleList;
	if(head){
		e=head;
		if(index<amount){
			for(int i=0; i<index+1; i++)
				e=e->next;
			if(e==NULL){
				e=tail;
				tail=tail->prev;
				e=NULL;
				return;
			}
			p=e->prev;
			n=e->next;
			p->next=e->next;
			n->prev=e->prev;
			e=NULL;
			counter--;
			return;
		}
		else
			cout<<"Zbyt duzy indeks";	
	}
	else
		cout<<"Brak listy";
}

void List::display(){
	
	int i=0;
	doubleList* e;
	e=head;
	while(e){
		cout<<i<<". "<<e->data;
		e=e->next;
		i++;
	}
}
