#include "HashTable.h"

int main()
{
	HashTable table(20);

	table.add(3, 3);
	table.add(4, 4);
	table.add(1, 1);
	table.add(9, 2);
	table.add(2, 2);
	table.add(5, 5);
	table.add(5, 4);
	table.add(15, 4); 
	table.add(15, 8);
	table.printTable();
}
