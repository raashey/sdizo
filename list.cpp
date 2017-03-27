#include "List.h"

int sizeOfList(){
	
	return counter;
	
}

doubleList * loadFromFileL(char* fileName){
	
	doubleList* e;
	fstream plik;
	plik.open(fileName,ios::in);
	if(plik.good()==false)
		cout<<"Plik zostal zle wczytany";
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

bool isValueInList(int val, doubleList*& head){
	
	doubleList* e;
	e=head;
	while(p){
		if(e->data=val)
			return true;
		e=e->next;	
	}
	return false;	
}

void * addValue(int value, doubleList*& head, doubleList*& tail){
	
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

void * deleteFromList(int index,int amount,doubleList*& head, doubleList*& tail){
	
	doubleList* e,p,n;
	if(head){
		e=head;
		if(index<amount){
			for(int i=0; i<index+1; i++)
				e=e->next;
			if(p==NULL){
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

void display(doubleList*& head){
	
	doubleList* e;
	e=head;
	while(e){
		cout<<i<<". "<<e->data;
		e=e->next;
	}
}
	
