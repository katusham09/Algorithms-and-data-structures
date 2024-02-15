#include "HuffmanTree.h"
#include <algorithm>


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
    m_root = nullptr;

    std::ifstream file(textFileName);
    if (!file.is_open())
    {
        return false;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        file.close();
        return false;
    }

    // Подсчитываем частоту символов
    std::unordered_map<char, int> frequency;
    char symbol;
    while (file.get(symbol))
    {
        frequency[symbol]++;
    }
    file.close();

    // Создаем узлы для каждого символа и добавляем их в список узлов
    std::list<Node*> nodes;
    for (const auto& pair : frequency)
    {
        Node* newNode = new Node(pair.first, pair.second, nullptr, nullptr);
        newNode->setSymbols(std::set<char>{pair.first}); // Добавляем символ к узлу
        nodes.push_back(newNode);
    }
        // Сортируем список узлов по частоте
        nodes.sort([](Node* left, Node* right) {
            return left->getFrequency() < right->getFrequency();
        });

        // Строим дерево Хаффмана
        while (nodes.size() > 1)
        {
            Node* subTreeRoot = new Node();

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

            // Создаем узел с объединенными символами и частотой
            subTreeRoot->setSymbols(temp);
            subTreeRoot->setFrequency(sum);
            subTreeRoot->setLeft(left);
            subTreeRoot->setRight(right);

            // Вставляем созданный узел в список nodes
            auto seeker = std::find_if(nodes.begin(), nodes.end(), [&](Node* node) {
                return node->getFrequency() > subTreeRoot->getFrequency();
            });
            nodes.insert(seeker, subTreeRoot);
        }

        // Устанавливаем корень дерева
        m_root = nodes.front();
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
        return "";
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

    if (root->getRight())
    {
        return encode(root->getRight(), ch, Code + "1");
    }

    return "";
}

std::string HuffmanTree::encode(const std::string& textFileName, const std::string& encodedTextFileName)
{
    if (m_root == nullptr)
    {
        build(textFileName);
    }

    if (m_root == nullptr)
    {
        return "";
    }

    std::ifstream file1(textFileName);
    std::ofstream file2(encodedTextFileName);
    if (!file1.is_open() || !file2.is_open())
    {
        return "";
    }

    double textSize = 0;
    double encodedTextSize = 0;
    char symbols;
    std::string encodedText;

    while (file1.get(symbols))
    {
        textSize++;
        std::string str = encode(symbols);
        encodedText += str; // Добавляем закодированный символ к общей строке
        file2 << str;
        encodedTextSize += str.size();
    }

    file1.close();
    file2.close();

    return encodedText;
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

int HuffmanTree::height(Node* root) const
{
    if (root == nullptr)
        return 0;
    return 1 + std::max(height(root->getLeft()), height(root->getRight()));
}

int HuffmanTree::height() const
{
    return height(m_root);
}
