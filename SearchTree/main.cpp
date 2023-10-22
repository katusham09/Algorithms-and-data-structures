#include "SearchTree.h"
#include "SearchTreeTester.h"
#include <iostream>


int main()
{	
	/*srand(time(0));
	int tmp[10];
	for (int i = 0; i < 10; i++)
	{
		tmp[i] = 1 + rand() % 100;
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << tmp[i] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	SearchTree tree;
	for (int i = 0; i < 10; i++)
	{
		tree.addNode(tmp[i]);
	}
	tree.printHorizontal(2, 3);

	int key;
	std::cout << "Enter key  ";
	std::cin >> key;

	tree.deleteNode(key);
	tree.printHorizontal(2, 5);*/

	SearchTreeTester tester(true);

	tester.test(5);
}