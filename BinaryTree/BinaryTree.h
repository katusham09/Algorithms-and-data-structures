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

        Node* getLeftChild() const
        {
            return m_leftChild;
        }

        Node* getRightChild() const
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
protected:
    Node* m_root;

public:
    BinaryTree();
    BinaryTree(const BinaryTree& copy);
    Node* copyTree(Node* root);
    virtual ~BinaryTree();
    void deleteTree(Node* root);
    void cleanTree();
    void cleanSubTree(Node* root);
    bool isEmpty(Node* root);
    int height(Node* root) const;
    int height() const;
    Node* getRoot();
    int getNumberNodes(Node* root) const; 
    int getNumberNodes() const;
    virtual Node* addNode(Node* root, int key);
    virtual Node* addNode(int key);
    virtual void deleteNode(Node* node);
    virtual bool deleteNode(int key);
    std::vector<int> getTreeKeys() const;
    void getTreeKeys(Node* root, std::vector<int>& treeKeys) const;
    void printHorizontal(Node* root, int marginLeft, int levelSpacing) const;
    void printHorizontal(int marginLeft, int Space) const;
    Node* searchNodeKLP(Node* root, int key);
    BinaryTree& operator = (const BinaryTree& other);
    Node* findParent(Node* node, Node* temp);
};