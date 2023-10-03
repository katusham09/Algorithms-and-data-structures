#pragma once
#include "C:\Users\katus\source\repos\ÀèÑÄ\BinaryTree\BinaryTreeTester.h"

class SearchTreeTester : public BinaryTreeTester
{
public:
    SearchTreeTester(const bool useConsoleOutput);
    ~SearchTreeTester() = default;

protected:
    BinaryTree* allocateTree() override;
    void check_addAndCount(const BinaryTree& tree, const int size) override;
    void check_remove(const BinaryTree& tree, const int size) override;
    void check_clear(const BinaryTree& tree, const int size) override;

private:
    void isSearchTree(const BinaryTree &tree)
    {
        std::vector<int> keys = tree.getTreeKeys();
        if (keys.size() == 0)
        {
            return;
        }
        else
        {
            for (int i = 0; i < keys.size() - 1; i++)
            {
                assert(keys[i] <= keys[i + 1]);
            }
        }


    }
};