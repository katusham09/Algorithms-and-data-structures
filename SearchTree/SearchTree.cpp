#include "SearchTree.h"

BinaryTree::Node *SearchTree::addNode(Node* root, int key)
{
    if (!root) {
        root = new Node(key);
    }
    else if (key < root->key()) {
        root->setLeftChild(addNode(root->leftChild(), key));
    }
    else {
        root->setRightChild(addNode(root->rightChild(), key));
    }

    return root;
}