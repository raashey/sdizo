#ifndef TABLE_H
#define TABLE_H

class Table
{
	public:
	
		int *tab;
		int amount; //ilość elementów w tablicy
	
	
	int loadFromFileT(); 
	
	bool isValueInTable(int val);
	
	void addValue(int value);

	void deleteFromTable(int index);

	void display();	
};

#endif
