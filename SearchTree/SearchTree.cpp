#include "SearchTree.h"

SearchTree::SearchTree()
{
    m_root = nullptr;
}

BinaryTree::Node *SearchTree::addNode(Node* root, int key)
{
    if (!root) {
        root = new Node(key);
    }
    else if (key < root->getKey()) {
        root->setLeftChild(addNode(root->getLeftChild(), key));
    }
    else {
        root->setRightChild(addNode(root->getRightChild(), key));
    }

    return root;
}

int SearchTree::getMinKey(Node* root)
{
    if (root->getLeftChild() != nullptr)
        return getMinKey(root->getLeftChild());
    else
        return root->getKey();
}

int SearchTree::getMaxKey(Node* root)
{
    if (root->getRightChild() != nullptr)
        return getMaxKey(root->getRightChild());
    else
        return root->getKey();
}

BinaryTree::Node* SearchTree::searchNode(Node* root, int key)
{
    if (root == nullptr || root->getKey() == key)
        return root;

    if (root->getKey() < key)
        return searchNode(root->getRightChild(), key);

    else
        return searchNode(root->getLeftChild(), key);
}
