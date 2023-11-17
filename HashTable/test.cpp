#include "test.h"
#include <assert.h>

HashTableTester::HashTableTester(const bool useConsoleOutput)
	: m_useConsoleOutput(useConsoleOutput)
{}

void HashTableTester::test(int maxSize)
{
	srand(time(NULL));
	max_size = maxSize;
	addAndClear();
	search();
	remove();
	assign();
}

void HashTableTester::addAndClear()
{
	HashTable table(max_size);
	for (int i = 0; i < max_size; i++)
	{
		table.add(rand() % 100, rand() % 100);
	}
	checkAdd(table, table.getCapacity());

	table.clear();
	checkDestructor(table);

	std::cout << "HashTableTester::addAndDestructor ended. Press any key to continue..." << std::endl;
	getchar();
}

void HashTableTester::checkAdd(HashTable table, int capacity)
{
	int count = 0;
	for (int i = 0; i < max_size; i++)
	{
		if (table.nodes()[i])
		{
			count++;
		}
	}
	assert(count == capacity);
}

void HashTableTester::checkDestructor(HashTable table)
{
	assert(table.getSize() == 0);
}

void HashTableTester::search()
{
	HashTable table(max_size);
	for (int i = 0; i < max_size; i++)
	{
		table.add(i, rand() % 100);
	}

	for (int i = 0; i < max_size; i++)
	{
		assert(table.contains(i) == true);
	}
	std::cout << "HashTableTester::search ended. Press any key to continue..." << std::endl;
	getchar();

}

void HashTableTester::remove()
{
	HashTable table(max_size);

	for (int i = 0; i < max_size; i++)
		table.add(i, rand() % 100);

	for (int i = 0; i < max_size; i++)
	{
		assert(table.remove(i) == true);
		assert(table.contains(i) == false);
	}

	for (int i = 0; i < max_size; i++)
		assert(table.getNodes()[i] == nullptr);

	for (int i = 0; i < max_size; i++)
		table.add(i, rand() % 100);

	assert(table.remove(table.getNodes()[max_size - 1]->getKey()) == true);
	assert(table.remove(table.getNodes()[max_size / 2]->getKey()) == true);
	assert(table.remove(table.getNodes()[0]->getKey()) == true);

	std::cout << "HashTableTester::remove ended. Press any key to continue..." << std::endl;
	getchar();
}

void HashTableTester::assign()
{
	HashTable table1(max_size);
	for (int i = 0; i < max_size; i++)
		table1.add(rand() % 100, rand() % 100);

	HashTable table2 = table1;

	assert(table1.nodes().size() == table2.nodes().size());


	for (int i = 0; i < table1.nodes().size(); i++)
	{
		if (table1.nodes()[i])
		{
			assert(table1.nodes()[i]->getKey() == table2.nodes()[i]->getKey());
			assert(table1.nodes()[i]->getValue() == table2.nodes()[i]->getValue());
		}
		else
			assert(table1.nodes()[i] == table2.nodes()[i]);
	}

	table1.clear();
	table2.clear();

	for (int i = 0; i < max_size; i++)
		table1.add(rand() % 300, rand() % 500);

	table2 = table1;


	assert(table1.nodes().size() == table2.nodes().size());


	for (int i = 0; i < table1.nodes().size(); i++)
	{
		if (table1.nodes()[i])
		{
			assert(table1.nodes()[i]->getKey() == table2.nodes()[i]->getKey());
			assert(table1.nodes()[i]->getValue() == table2.nodes()[i]->getValue());
		}
		else
			assert(table1.nodes()[i] == table2.nodes()[i]);
	}
	std::cout << "HashTableTester::assign ended. Press any key to continue..." << std::endl;
	getchar();
}