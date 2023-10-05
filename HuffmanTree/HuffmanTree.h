#pragma once
#include <string>

class HuffmanTree
{
public:
    class Node;

    HuffmanTree() { m_root = nullptr; }
    ~HuffmanTree();
    void deleteHuffmanTree(Node* node);
    void build(const std::string& text);
    double encode(const std::string& text, std::string& encodedText);
    bool decode(const std::string& encodedText, std::string& decodedText) const;

private:
    Node* m_root = nullptr;
};

class HuffmanTree::Node
{
public:
    Node()
    {
        m_frequency = 0;
        m_left = nullptr;
        m_right = nullptr;
    }

    ~Node() = default;

    int getFrequency() 
    {
        return m_frequency;
    }

    Node* getLeft()
    {
        return m_left;
    }

    Node* getRight()
    {
        return m_right;
    }

    void setLeft(Node* left)
    {
        m_left = left;
    }

    void setRight(Node* right)
    {
        m_right = right;
    }
private:
    Node* m_left = nullptr;
    Node* m_right = nullptr;
    int m_frequency;
    std::string m_symbols;
};