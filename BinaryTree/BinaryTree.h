#pragma once
#include <iostream>
#include <vector>

class BinaryTree
{
public:
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
private:
    Node* m_root;

public:
    BinaryTree();
    BinaryTree(const BinaryTree& copy);
    Node* copyTree(Node* root);
    ~BinaryTree();
    void deleteTree(Node* root);
    void cleanTree();
    void cleanSubTree(Node* root);
    bool isEmpty(Node* root);
    int height(Node* root) const;
    int height() const;
    Node* getRoot();
    int getNumberNodes(Node* root) const; 
    int getNumberNodes() const;
    Node* addNode(Node* root, int key);
    Node* addNode(int key);
    void deleteNode(Node* node);
    bool deleteNode(int key);
    std::vector<int> getTreeKeys();
    void getTreeKeys(Node* root, std::vector<int>& treeKeys);
    void printHorizontal(Node* root, int marginLeft, int levelSpacing) const;
    void printHorizontal(int marginLeft, int Space) const;
    Node* searchNodeKLP(Node* root, int key);
    BinaryTree& operator = (const BinaryTree& other);
    Node* findParent(Node* node, Node* temp);
};