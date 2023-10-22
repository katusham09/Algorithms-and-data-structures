#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
    m_root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree& copy)
{
    if (copy.m_root)
        m_root = copyTree(copy.m_root);
    else
        m_root = nullptr;
}


BinaryTree::Node* BinaryTree::copyTree(Node* root)
{
    Node* root_copy;
    if (root == nullptr) {
        return nullptr;
    }
    root_copy = new Node(*root);
    if (root->getLeftChild() != nullptr)
        root_copy->setLeftChild(copyTree(root->getLeftChild()));
    else
        root_copy->setLeftChild(nullptr);

    if (root->getRightChild() != nullptr)
        root_copy->setRightChild(copyTree(root->getRightChild()));
    else
        root_copy->setRightChild(nullptr);
    return root_copy;
}


BinaryTree::~BinaryTree()
{
    deleteTree(m_root);
}

void BinaryTree::deleteTree(Node* root)
{
    if (root)
    {
        deleteTree(root->getLeftChild());
        deleteTree(root->getRightChild());
        delete root;
    }
}


BinaryTree::Node* BinaryTree::getRoot()
{
    return m_root;
}

void BinaryTree::cleanSubTree(Node* root)
{
    if (root == nullptr)
        return;

    cleanSubTree(root->getLeftChild());
    cleanSubTree(root->getRightChild());
    root->setLeftChild(nullptr);
    root->setRightChild(nullptr);
}

void BinaryTree::cleanTree()
{
    cleanSubTree(m_root);
    m_root = nullptr;
}

bool BinaryTree::isEmpty(Node* root)
{
    if (root == nullptr)
        return true;
    return false;
}


int BinaryTree::height(Node* root) const
{
    if (root == nullptr)
        return 0;
    return 1 + std::max(height(root->getLeftChild()), height(root->getRightChild()));
}

int BinaryTree::height() const
{
    return height(m_root);
}


int BinaryTree::getNumberNodes(Node* root) const
{
    if (root == nullptr)
        return 0;
    return getNumberNodes(root->getLeftChild()) + getNumberNodes(root->getRightChild()) + 1;
}

int BinaryTree::getNumberNodes() const
{
   return getNumberNodes(m_root);
}


BinaryTree::Node* BinaryTree::addNode(Node* root, int key)
{
    if (!root)
        root = new Node(key);
    else if (rand() & 2)
        root->setLeftChild(addNode(root->getLeftChild(), key));
    else
        root->setRightChild(addNode(root->getRightChild(), key));

    return root;
}

BinaryTree::Node* BinaryTree::addNode(int key)
{
    m_root = addNode(m_root, key);
    return m_root;
}


void BinaryTree::printHorizontal(Node* root, int marginLeft, int levelSpacing) const
{
    if (root == nullptr)
        return;
    printHorizontal(root->getRightChild(), marginLeft + levelSpacing, levelSpacing);
    std::cout << std::string(marginLeft, ' ') << root->getKey() << std::endl;
    printHorizontal(root->getLeftChild(), marginLeft + levelSpacing, levelSpacing);
}

void BinaryTree::printHorizontal(int marginLeft, int levelSpacing) const
{
    printHorizontal(m_root, marginLeft, levelSpacing);
}

std::vector<int> BinaryTree::getTreeKeys() const
{
    std::vector<int> treeKeys;
    getTreeKeys(m_root, treeKeys);
    return treeKeys;
}

void BinaryTree::getTreeKeys(Node* root, std::vector<int>& treeKeys) const
{
    if (!root)
        return;
    getTreeKeys(root->getLeftChild(), treeKeys);
    treeKeys.push_back(root->getKey());
    getTreeKeys(root->getRightChild(), treeKeys);
}


BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
    if (this == &other)
        return *this;
    deleteTree(m_root);
    m_root = copyTree(other.m_root);
    return *this;
}

BinaryTree::Node* BinaryTree::findParent(Node* node, Node* temp)
{
    if (node == m_root || temp == nullptr)
        return nullptr;

    if (temp->getLeftChild() == node || temp->getRightChild() == node)
        return temp;

    Node* parent = findParent(node, temp->getLeftChild());
    if (parent != nullptr)
        return parent;

    parent = findParent(node, temp->getRightChild());
    return parent;
}

void BinaryTree::deleteNode(Node* node)
{

    Node* parent = findParent(node, m_root);
    if (parent == nullptr && node != m_root)
    {
        return;
    }

    Node* replace = nullptr;

    if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr)
        replace = nullptr;
    else if (node->getLeftChild() == nullptr && node->getRightChild() != nullptr)
        replace = node->getRightChild();
    else if (node->getRightChild() == nullptr && node->getLeftChild() != nullptr)
        replace = node->getLeftChild();

    else {
        Node* temp = node->getRightChild();
        while (temp->getLeftChild() != nullptr)
            temp = temp->getLeftChild();
        replace = temp;

        Node* tempParent = findParent(temp, m_root);
        if (tempParent != node)
        {
            tempParent->setLeftChild(replace->getRightChild());
            replace->setRightChild(node->getRightChild());
        }
        replace->setLeftChild(node->getLeftChild());
    }

    if (parent != nullptr)
    {
        if (parent->getLeftChild() == node)
            parent->setLeftChild(replace);
        else
            parent->setRightChild(replace);
        delete node;
    }
    else
    {
        delete m_root;
        m_root = replace;
    }

}


BinaryTree::Node* BinaryTree::searchNodeKLP(Node* root, int key)
{
    if (!root || root->getKey() == key)
        return root;
    Node* subTreeSearchResult = searchNodeKLP(root->getLeftChild(), key);
    if (!subTreeSearchResult)
        subTreeSearchResult = searchNodeKLP(root->getRightChild(), key);
    return subTreeSearchResult;
}

bool BinaryTree::deleteNode(int key)
{
    Node* node = searchNodeKLP(m_root, key);
    if (!node)
        return false;

    deleteNode(node);
    return true;
}
