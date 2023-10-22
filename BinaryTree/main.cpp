#include "BinaryTree.h"
#include "BinaryTreeTester.h"

int main()
{
    /*BinaryTree tree;
    for (int i = 15; i > 0; i--)
    {
        tree.addNode(i);
    }
    tree.printHorizontal(4, 4);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    tree.deleteNode(9);
    tree.printHorizontal(4, 4);*/

    BinaryTreeTester tester(true);

    tester.test(5);


    return 0;
}