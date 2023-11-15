//#include "HashTable.h"
#include "test.h"

int main()
{
	HashTable table(10);
	table.add(3, 6);
	table.add(4, 3);
	table.add(1, 1);
	table.add(9, 2);
	table.add(2, 3);
	table.add(5, 5);
	table.add(7, 4);
	table.add(15, 4); 
	table.add(14, 4);
	table.add(25, 4);
	table.add(16, 5);
	table.printTable();
	table.remove(25);
	table.printTable();
	table.clear();
	std::cout << "dell" << std::endl;
	table.printTable();

	/*HashTableTester tester(true);
	tester.test(3);*/
}
