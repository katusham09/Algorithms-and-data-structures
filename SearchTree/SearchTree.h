#pragma once
#include "C:\Users\katus\source\repos\ÀèÑÄ\BinaryTree\BinaryTree.h"

class SearchTree : public BinaryTree
{
public:
	SearchTree();
	~SearchTree() override = default;
	using BinaryTree::Node;
	Node* addNode(Node* root, int key) override;
	int getMinKey(Node* root);
	int getMaxKey(Node* root);
	void deleteNode(Node* root, int key);
	bool deleteNode(int key) override;
	Node* searchNode(Node* root, int key);
	Node* searchNode(int key);
	static SearchTree buildOptimalTree(const std::vector<int>& keys,
		const std::vector<int>& keysFrequences,
		const std::vector<int>& nonKeysFrequences);
};
