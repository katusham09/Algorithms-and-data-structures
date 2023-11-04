#include "BinaryTreeTester.h"

BinaryTreeTester::BinaryTreeTester(const bool useConsoleOutput)
    : m_useConsoleOutput(useConsoleOutput)
{}

void BinaryTreeTester::test(const int size)
{
    m_maxSize = size;
    addAndCount();
    destructor();
    remove();
    clear();
    assign();
    height();
}

BinaryTree* BinaryTreeTester::allocateTree()
{
    return new BinaryTree;
}

void BinaryTreeTester::deallocateTree(BinaryTree* tree)
{
    delete tree;
}

void BinaryTreeTester::addAndCount()
{
    BinaryTree* tree = allocateTree();
    check_addAndCount(*tree, 0);

    for (int i = 0; i < m_maxSize; ++i) {
        tree->addNode(i);
        check_addAndCount(*tree, i + 1);
    }

    deallocateTree(tree);
}

void BinaryTreeTester::check_addAndCount(const BinaryTree &tree, const int size)
{
    assert(tree.getNumberNodes() == size);
}

void BinaryTreeTester::destructor()
{
    const int runsCount = 200;
    for (int i = 0; i < runsCount; i++)
    {
        BinaryTree* tree = allocateTree();
        for (int i = 0; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        deallocateTree(tree);
    }
    std::cout << "BinaryTreeTester::destructor ended. Press any key to continue..." << std::endl;
    std::getchar();

}

void BinaryTreeTester::remove()
{
    int invalidKey = -1;
    std::vector<int> nodeKeys;

    BinaryTree* tree = allocateTree();
    tree->deleteNode(invalidKey);
    check_remove(*tree, nodeKeys.size());

    for (int i = 0; i < m_maxSize; ++i) {
        nodeKeys.push_back(i);
        tree->addNode(i);
    }

    while (!nodeKeys.empty()) {
        int removedNodeIndex = rand() % nodeKeys.size();

        tree->deleteNode(invalidKey);
        check_remove(*tree, nodeKeys.size());

        tree->deleteNode(nodeKeys[removedNodeIndex]);
        nodeKeys.erase(nodeKeys.begin() + removedNodeIndex);
        check_remove(*tree, nodeKeys.size());
        if (m_useConsoleOutput)
            tree->printHorizontal(4, 4);
    }
    if (m_useConsoleOutput)
        tree->printHorizontal(4, 4);
    tree->deleteNode(invalidKey);
    check_remove(*tree, nodeKeys.size());
    deallocateTree(tree);
}

void BinaryTreeTester::check_remove(const BinaryTree &tree, const int size)
{
    assert(tree.getNumberNodes() == size);
}

void BinaryTreeTester::clear()
{
    BinaryTree* tree = allocateTree();
    for (int i = 0; i < 200; i++)
    {
        for (int i = 0; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        tree->cleanTree();
        check_clear(*tree, 0);
    }
    deallocateTree(tree);
    std::cout << "BinaryTreeTester::clear ended. Press any key to continue..." << std::endl;
    std::getchar();
}

void BinaryTreeTester::check_clear(const BinaryTree &tree, const int size)
{
    assert(tree.getNumberNodes() == size);
}

//void BinaryTreeTester::assign()
//{
//    BinaryTree tree1;
//
//    for (int i = 0; i < m_maxSize; ++i) {
//        tree1.addNode(i);
//    }
//
//    BinaryTree tree2 = tree1;
//
//    std::vector<int> getKeysTree1 = tree1.getTreeKeys();
//    std::vector<int> getKeysTree2 = tree2.getTreeKeys();
//
//    std::vector<const BinaryTree::Node*> tree1Nodes = treeNodes(&tree1);
//    std::vector<const BinaryTree::Node*> tree2Nodes = treeNodes(&tree2);
//
//    check_assign(getKeysTree1, getKeysTree2, tree1Nodes, tree2Nodes);
//
//    tree1 = tree2;
//
//    getKeysTree1 = tree1.getTreeKeys();
//    getKeysTree2 = tree2.getTreeKeys();
//
//    tree1Nodes = treeNodes(&tree1);
//    tree2Nodes = treeNodes(&tree2);
//
//    check_assign(getKeysTree1, getKeysTree2, tree1Nodes, tree2Nodes);
//
//    std::cout << "BinaryTreeTester::assign ended. Press any key to continue..." << std::endl;
//    std::getchar();
//}

void BinaryTreeTester::assign()
{
    BinaryTree* tree1 = allocateTree();

    for (int i = 0; i < m_maxSize; ++i) {
        tree1->addNode(i);
    }

    BinaryTree* tree2 = allocateTree();
    *tree2 = *tree1;

    std::vector<int> getKeysTree1 = tree1->getTreeKeys();
    std::vector<int> getKeysTree2 = tree2->getTreeKeys();

    std::vector<const BinaryTree::Node*> tree1Nodes = treeNodes(tree1);
    std::vector<const BinaryTree::Node*> tree2Nodes = treeNodes(tree2);

    check_assign(getKeysTree1, getKeysTree2, tree1Nodes, tree2Nodes);

    *tree1 = *tree2;

    getKeysTree1 = tree1->getTreeKeys();
    getKeysTree2 = tree2->getTreeKeys();

    tree1Nodes = treeNodes(tree1);
    tree2Nodes = treeNodes(tree2);

    check_assign(getKeysTree1, getKeysTree2, tree1Nodes, tree2Nodes);

    deallocateTree(tree1);
    deallocateTree(tree2);

    std::cout << "BinaryTreeTester::assign ended. Press any key to continue..." << std::endl;
    std::getchar();
}

void BinaryTreeTester::check_assign(std::vector<int> getKeysTree1, std::vector<int> getKeysTree2, const std::vector<const BinaryTree::Node*> tree1Nodes, const std::vector<const BinaryTree::Node*> tree2Nodes)
{
    for (int i = 0; i < tree1Nodes.size(); i++)
    {
        assert(tree1Nodes[i] != tree2Nodes[i]);
    }

    for (int i = 0; i < tree1Nodes.size(); i++)
    {
        assert(getKeysTree1[i] == getKeysTree2[i]);
    }
}

std::vector<const BinaryTree::Node*> BinaryTreeTester::treeNodes(BinaryTree *tree)
{
    std::vector<const BinaryTree::Node*> nodes;

    std::vector<const BinaryTree::Node*> nodesToProcess;
    nodesToProcess.push_back(tree->getRoot());
    while (!nodesToProcess.empty()) {
        const BinaryTree::Node* node = nodesToProcess.front();
        if (node != nullptr) {
            nodesToProcess.push_back(node->getLeftChild());
            nodesToProcess.push_back(node->getRightChild());
            nodes.push_back(node);
        }
        nodesToProcess.erase(nodesToProcess.begin());
    }

    return nodes;
}

void BinaryTreeTester::height()
{
    height_trivialCases();
    height_longOnlyLeftSubtree();
    height_longOnlyRightSubtree();
    height_longOnlyLeftAndRightSubtrees();
    height_longRandomZigzagSubtrees();
}

void BinaryTreeTester::check_height(const BinaryTree& tree, const int height)
{
    assert(tree.height() == height);
}

void BinaryTreeTester::height_trivialCases()
{
    BinaryTree tree;
    check_height(tree, 0);
    tree.addNode(0);
    check_height(tree, 1);
}

void BinaryTreeTester::height_longOnlyLeftSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setLeftChild(new BinaryTree::Node(i));
        runner = runner->getLeftChild();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyRightSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* runner = longTree.getRoot();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setRightChild(new BinaryTree::Node(i));
        runner = runner->getRightChild();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyLeftAndRightSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* leftRunner = longTree.getRoot();
    BinaryTree::Node* rightRunner = longTree.getRoot();
    for (int i = 1; i < m_maxSize / 2; ++i) {
        leftRunner->setLeftChild(new BinaryTree::Node(i));
        leftRunner = leftRunner->getLeftChild();
        check_height(longTree, i + 1);


        rightRunner->setRightChild(new BinaryTree::Node(i));
        rightRunner = rightRunner->getRightChild();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longRandomZigzagSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* leftRunner = longTree.getRoot();
    BinaryTree::Node* rightRunner = longTree.getRoot();

    leftRunner->setLeftChild(new BinaryTree::Node(1));
    leftRunner = leftRunner->getLeftChild();
    rightRunner->setRightChild(new BinaryTree::Node(1));
    rightRunner = rightRunner->getRightChild();

    for (int i = 2; i < m_maxSize / 2; ++i) {
        if (rand() % 2 == 0)
        {
            leftRunner->setLeftChild(new BinaryTree::Node(i));
            leftRunner = leftRunner->getLeftChild();
        }
        else
        {
            leftRunner->setRightChild(new BinaryTree::Node(i));
            leftRunner = leftRunner->getRightChild();
        }
        check_height(longTree, i + 1);

        if (rand() % 2 == 0)
        {
            rightRunner->setLeftChild(new BinaryTree::Node(i));
            rightRunner = rightRunner->getLeftChild();
        }
        else
        {
            rightRunner->setRightChild(new BinaryTree::Node(i));
            rightRunner = rightRunner->getRightChild();
        }
        check_height(longTree, i + 1);
    }
}