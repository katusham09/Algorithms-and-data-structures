#pragma once
#include "C:\Users\katus\source\repos\ÀèÑÄ\BinaryTree\BinaryTreeTester.h"

class SearchTreeTester : public BinaryTreeTester
{
public:
    SearchTreeTester(const bool useConsoleOutput);
    ~SearchTreeTester() = default;

protected:
    BinaryTree* allocateTree() override;
    void deallocateTree(BinaryTree* tree) override;
    void check_addAndCount(const BinaryTree& tree, const int size) override;
    void check_remove(const BinaryTree& tree, const int size) override;
    void check_clear(const BinaryTree& tree, const int size) override;
    //ToDo: check_clear() override
    //ToDo: check_assign() override

private:
    bool isSearchTree(const BinaryTree* tree)
    {
        std::vector<int> keys;

        getKeysLnr(keys, tree->getRoot());

        for (int i = 1; i < keys.size(); i++)
        {
            if (keys[i] <= keys[i - 1])
            {
                return false;
            }
        }

        return true;
    }

    void getKeysLnr(std::vector<int>& keys, BinaryTree::Node* node)
    {
        if (!node)
        {
            return;
        }

        getKeysLnr(keys, node->getLeftChild());
        keys.push_back(node->getKey());
        getKeysLnr(keys, node->setRightChild());
    }
};