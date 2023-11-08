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

bool HuffmanTree::build(const std::string& textFileName)
{
    deleteHuffmanTree(m_root);

    char symbols;
    std::ifstream file(textFileName);
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

    for (auto it = frequency.begin(); it != frequency.end(); it++) 
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

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
    std::string encodedChar = encode(m_root, ch, "");
    if (m_root != nullptr && encodedChar.size() == 0)
        encodedChar = "0";
    return encodedChar;
}

std::string HuffmanTree::encode(Node* root, char ch, std::string Code)
{   
    if (!root)
    {
        return;
    }

    if (!root->getLeft() && !root->getRight())
    {
        return Code;
    }

    if (root->getLeft())
    {
        std::set<char> tempLeft = root->getLeft()->getSymbols();
        if (tempLeft.find(ch) != tempLeft.end())
            return encode(root->getLeft(), ch, Code + "0");
        else
            return encode(root->getRight(), ch, Code + "1");
    }
}

double HuffmanTree::encode(const std::string& textFileName, const std::string& encodedTextFileName)
{
    if (m_root == nullptr)
    {
        build(textFileName);
    }

    if (m_root == nullptr)
    {
        return 0;
    }
    std::ifstream file1(textFileName);
    std::ofstream file2(encodedTextFileName);
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
}

bool HuffmanTree::decode(const std::string& encodedTextFileName, const std::string& decodedTextFileName) const
{
    char symbols;
    std::ifstream file1(encodedTextFileName);
    std::ofstream file2(decodedTextFileName);
    if (!file1.is_open() || !file2.is_open())
    {
        return false;
    }

    Node* temp = m_root;

    while (file1.get(symbols))
    {
        if (symbols == '0' && temp->getLeft())
        {
            temp = temp->getLeft();
        }
        else
            if (temp->getRight())
            {
                temp = temp->getRight();
            }

        if (!temp->getLeft() && !temp->getRight())
        {
            std::set<char> tempTemp = temp->getSymbols();
            std::set<char>::iterator it;
            it = tempTemp.begin();
            file2 << *it;
            temp = m_root;
        }
    }
    file1.close();
    file2.close();
    return true;
}