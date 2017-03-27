#ifndef LIST_H
#define LIST_H

class List
{
	public:
	
	struct doubleList{
		
		doubleList *next;
		doubleList *prev;
		int data;
	};
	
	doubleList *head;
	doubleList *tail;
	int counter;
	

	int sizeOfList();
	
	doubleList * loadFromFileL(char* fileName);
	
	bool isValueInList(int val, doubleList*& head);
	
	void * addValue(int index, doubleList*& head, doubleList*& tail);

	void * deleteFromList(int index, doubleList*& head, doubleList*& tail);

	void display(doubleList*& head);
};

#endif
