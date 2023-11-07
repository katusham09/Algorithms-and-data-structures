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


bool HuffmanTree::build(const std::string& text)
{
    deleteHuffmanTree(m_root);

    char symbols;
    std::ifstream file(text);
    if (!file.is_open())
    {
        return false;
    }

    std::list<Node*> nodes;
    std::unordered_map<char, int> frequency;
    while (file.get(symbols))
    {
        frequency[symbols]++;
    }
    file.close();


    for (auto pair : frequency)
    {
        nodes.push_back(new Node(pair.first, pair.second, nullptr, nullptr));
    }
    
    nodes.sort([](Node* left, Node* right) {
        return left->getFrequency() < right->getFrequency();
    });

    while (nodes.size() > 1)
    {
        Node* subTreeRoot = nullptr;

        Node* left = nodes.front(); 
        nodes.pop_front();

        Node* right = nodes.front();	
        nodes.pop_front();

        int sum = left->getFrequency() + right->getFrequency();

        std::set<char> temp;
        std::set<char> leftTemp = left->getSymbols();
        std::set<char> rightTemp = right->getSymbols();

        temp.insert(leftTemp.begin(), leftTemp.end());
        temp.insert(rightTemp.begin(), rightTemp.end());

        subTreeRoot = new Node(temp, sum, left, right);

        std::list<Node*>::iterator seeker = nodes.begin();
        while (seeker != nodes.end() && (*seeker)->getFrequency() <= subTreeRoot->getFrequency())
        {
            seeker++;
        }
        nodes.insert(seeker, subTreeRoot);
    }

    m_root = nodes.front();
    nodes.pop_front();
    return true;
}

std::string HuffmanTree::encode(char ch)
{
    std::string encodedChar;
    encode(m_root, ch, "", encodedChar);
    if (m_root != nullptr && encodedChar.size() == 0)
        encodedChar += "0";
    return encodedChar;
}

void HuffmanTree::encode(Node* root, char ch, std::string Code, std::string& encodedChar)
{   
    if (!root)
    {
        return;
    }

    if (!root->getLeft() && !root->getRight())
    {
        encodedChar = Code;
    }

    if (root->getLeft())
    {
        std::set<char> tempLeft = root->getLeft()->getSymbols();
        if (tempLeft.find(ch) != tempLeft.end())
            encode(root->getLeft(), ch, Code + "0", encodedChar);
        else
            encode(root->getRight(), ch, Code + "1", encodedChar);
    }
}

double HuffmanTree::encode(const std::string& text, std::string& encodedText)
{
    build(text);

    if (m_root == nullptr)
    {
        return 0;
    }
    std::ifstream file1(text);
    std::ofstream file2(encodedText);
    if (!file1.is_open() || !file2.is_open())
    {
        return -1;
    }

    double textSize = 0;
    double encodedTextSize = 0;
    char symbols;

    while (file1.get(symbols))
    {
        textSize++;
        std::string str = encode(symbols);
        file2 << str;
        encodedTextSize += str.size();
    }

    double compression = (textSize * 8) / encodedTextSize;

    file1.close();
    file2.close();
    return compression;
    return 2;
}
