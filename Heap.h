#ifndef HEAP_H
#define HEAP_H

class Heap
{
	int size;
	int* tab;
	
	public:
	
	bool loadFromFileH();
		
	void addValueToHeap(int value);
	
	void deleteFromHeap(int value);
	
	bool isValueInHeap(int value);
	
	void display();
		
};

#endif
