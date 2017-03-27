#ifndef LIST_H
#define LIST_H

class List
{
	public:
		
		int amount;
	
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
	
	bool isValueInList(int val);
	
	void addValue(int index);

	void deleteFromList(int index);

	void display();
};

#endif
