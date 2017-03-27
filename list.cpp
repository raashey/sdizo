#include "List.h"
#include <fstream>
#include <iostream>

using namespace std;
int List::sizeOfList(){
	
	return counter;
	
}

void List::loadFromFileL(){
	
	head=tail=NULL;
	doubleList* pom=new doubleList;
	doubleList* tmp=new doubleList;
	fstream plik;
	plik.open("liczby.txt");
	if(plik.good()==false)
		cout<<"Plik zostal zle wczytany";
	plik>>amount;
	for(int i=0; i<amount; i++){
	 	
	 	tmp=new doubleList;
	 	plik>>tmp->data;
		tmp->prev=NULL;
		tmp->next=NULL;
		if (head == NULL)
			head = tmp;
		else
		{
			pom = head;
			while (pom->next != NULL)
				pom = pom->next;
			tmp->prev = pom;
			pom->next = tmp;
		}
		counter++;
	}
	tail=tmp;
}

bool List::isValueInList(int val){
	
	doubleList* e;
	e=head;
	while(e){
		if(e->data==val)
			return true;
		e=e->next;	
	}
	return false;	
}

void List::addValue(int value){
	
	doubleList* e= new doubleList;
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
			for(int i=0; i<index-1; i++)
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
	
	int i=1;
	doubleList* e;
	e=head;
	while(e){
		cout<<i<<". "<<e->data<<endl;
		e=e->next;
		i++;
	}
}
	
