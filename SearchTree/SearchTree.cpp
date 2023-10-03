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

BinaryTree::Node* SearchTree::addNode(int key)
{
    m_root = addNode(m_root, key);
    return m_root;
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

BinaryTree::Node* SearchTree::searchNode(int key)
{
    return searchNode(m_root, key);
}

void SearchTree::deleteNode(Node* node, int key)
{
    Node* parent = findParent(node, m_root);
    if (parent == nullptr && node != m_root)
    {
        return;
    }

    Node* replace = nullptr;
    Node* tmp = nullptr;

    if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr)
    {
        replace = nullptr;
    }

    else if (node->getLeftChild() == nullptr && node->getRightChild() != nullptr)
    {
        replace = node->getRightChild();
    }

    else if (node->getRightChild() == nullptr && node->getLeftChild() != nullptr)
    {
        replace = node->getLeftChild();
    }

    else
    {
        tmp = node->getRightChild();
        while (tmp->getLeftChild() != nullptr)
        {
            tmp = tmp->getLeftChild();
        }
        replace = tmp;

        Node* tmpParent = findParent(tmp, m_root);
        if (tmpParent != node)
        {
            tmpParent->setLeftChild(replace->getRightChild());
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

bool SearchTree::deleteNode(int key)
{
    Node* node = searchNode(key);
    if (!node)
        return false;
    deleteNode(node, key);
    return true;
}