#pragma once
#include <iostream>

class Node
{
private:
    int m_key;
    Node* m_leftChild;
    Node* m_rightChild;

public:

    ~Node() = default;

    Node()
    {
        m_key = 0;
        m_leftChild = nullptr;
        m_rightChild = nullptr;
    }

    Node(int key)
    {
        m_key = key;
        m_leftChild = nullptr;
        m_rightChild = nullptr;
    }

    int getKey()
    {
        return m_key;
    }

    Node* getLeftChild()
    {
        return m_leftChild;
    }

    Node* getRightChild()
    {
        return m_rightChild;
    }

    void setLeftChild(Node* left)
    {
        m_leftChild = left;
    }

    void setRightChild(Node* right)
    {
        m_rightChild = right;
    }
};
