#pragma once
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

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

    Node(char ch, int frequency, Node* left, Node* right)
    {
        setChar(ch);
        setFrequency(frequency);
        setLeft(left);
        setRight(right);
    }

    void setChar(char ch) 
    {
        m_symbols.push_back(ch); 
    }

    void setFrequency(int frequency)
    {
        m_frequency = frequency;
    }

private:
    Node* m_left = nullptr;
    Node* m_right = nullptr;
    int m_frequency;
    std::string m_symbols;
};