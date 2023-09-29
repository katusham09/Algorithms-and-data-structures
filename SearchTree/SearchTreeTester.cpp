#include "SearchTree.h"

#include "SearchTreeTester.h"

SearchTreeTester::SearchTreeTester(const bool useConsoleOutput)
    : BinaryTreeTester(useConsoleOutput)
{}

BinaryTree* SearchTreeTester::allocateTree()
{
    return new SearchTree;
}

void SearchTreeTester::check_addAndCount(const BinaryTree& tree, const int size)
{
    BinaryTreeTester::check_addAndCount(tree, size);
    assert(isSearchTree(tree));
}

void SearchTreeTester::check_remove(const BinaryTree& tree, const int size)
{
    BinaryTreeTester::check_remove(tree, size);
    assert(isSearchTree(tree));
}

void SearchTreeTester::check_clear(const BinaryTree& tree, const int size)
{
    BinaryTreeTester::check_clear(tree, size);
    assert(isSearchTree(tree));
}