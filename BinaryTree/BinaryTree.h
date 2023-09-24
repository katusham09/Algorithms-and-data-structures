#pragma once
#include <iostream>
#include <vector>
#include "Node.h"

class BinaryTree
{
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
    int height(Node* root);
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