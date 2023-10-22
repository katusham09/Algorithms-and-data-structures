#include "HuffmanTree.h"

HuffmanTree::~HuffmanTree()
{
	deleteHuffmanTree(m_root);
}

void HuffmanTree::deleteHuffmanTree(Node* node)
{
	if (node)
	{
		deleteHuffmanTree(node->getLeft());
		deleteHuffmanTree(node->getRight());
		delete node;
	}
}


void HuffmanTree::build(const std::string& text)
{
    deleteHuffmanTree(m_root);

    std::list<Node*> nodes;
    std::unordered_map<char, int> frequency;
    for (char const& ch: text)
    {
        frequency[ch]++;
    }

    for (auto pair : frequency)
    {
        nodes.push_back(new Node(pair.first, pair.second, nullptr, nullptr));
    }
    
    nodes.sort([](Node* left, Node* right)
        {
            return left->getFrequency() < right->getFrequency();
        });

    while (nodes.size() > 1)
    {
        Node* subTreeRoot = nullptr;

        Node* left = nodes.front(); nodes.pop_front();
        Node* right = nodes.front();	nodes.pop_front();
        int sum = left->getFrequency() + right->getFrequency();

        std::set<char> temp;
        std::set<char> leftTemp = left->GetSet();
        std::set<char> rightTemp = right->GetSet();
        temp.insert(leftTemp.begin(), leftTemp.end());
        temp.insert(rightTemp.begin(), rightTemp.end());

        subTreeRoot = new Node(temp, sum, left, right);

        std::list<Node*>::iterator seeker = nodes.begin();
        while (seeker != nodes.end() && (*seeker)->GetFreq() <= subTreeRoot->GetFreq())           seeker++;
        nodes.insert(seeker, subTreeRoot);
    }

    // корень дерева - оставшаяся последняя нода
    m_root = nodes.front();
    nodes.pop_front();
    return true;
}

double HuffmanTree::encode(const std::string& text, std::string& encodedText)
{

}