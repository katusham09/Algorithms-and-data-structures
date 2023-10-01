#pragma once
#include "BinaryTree.h"
#include <assert.h>
#include <vector>


class BinaryTreeTester
{
public:
    BinaryTreeTester(const bool useConsoleOutput);
    ~BinaryTreeTester() = default;

    void test(const int size);

protected:
    virtual BinaryTree* allocateTree();
    virtual void check_addAndCount(const BinaryTree &tree, const int size);
    virtual void check_remove(const BinaryTree &tree, const int size);
    virtual void check_clear(const BinaryTree &tree, const int size);
    virtual void check_assign(const std::vector<const BinaryTree::Node*> tree1Nodes, const std::vector<const BinaryTree::Node*> tree2Nodes);
    virtual void check_height(const BinaryTree& tree, const int size);

private:
    void deallocateTree(BinaryTree* tree);
    void addAndCount();
    void destructor();
    void remove();
    void clear();
    void assign();
    void height();
    void height_trivialCases();
    void height_longOnlyLeftSubtree();
    void height_longOnlyRightSubtree();
    void height_longOnlyLeftAndRightSubtrees();
    void height_longRandomZigzagSubtrees();
    std::vector<const BinaryTree::Node*> treeNodes(BinaryTree *tree);

private:
    int m_maxSize;
    bool m_useConsoleOutput;
};