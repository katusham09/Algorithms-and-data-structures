#pragma once
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <set>
#include <fstream>

class HuffmanTree
{
public:
    class Node
    {
    public:
        Node()
        {
            m_frequency = 0;
            m_left = nullptr;
            m_right = nullptr;
        }

        Node(char symbols, int frequency, Node* left, Node* right)
        {
            setSymbols(symbols);
            setFrequency(frequency);
            setLeft(left);
            setRight(right);
        }

        Node(std::set<char> temp, int freq, Node* left, Node* right)
        {
            setSymbols(temp);
            setFrequency(freq);
            setLeft(left);
            setRight(right);
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

        const std::set<char>& getSymbols() const
        {
            return m_symbols;
        }

        void setLeft(Node* left)
        {
            m_left = left;
        }

        void setRight(Node* right)
        {
            m_right = right;
        }

        void setSymbols(char symbols)
        {
            m_symbols.insert(symbols);
        }

        void setFrequency(int frequency)
        {
            m_frequency = frequency;
        }

        void setSymbols(std::set<char> temp)
        {
            m_symbols.insert(temp.begin(), temp.end());
        }

    public:
        Node* m_left = nullptr;
        Node* m_right = nullptr;
        int m_frequency;
        std::set<char> m_symbols;
    };


    HuffmanTree() { m_root = nullptr; }
    ~HuffmanTree();
    void deleteHuffmanTree(Node* node);
    bool build(const std::string& text);

    std::string encode(const std::string& text, const std::string& encodedText);
    std::string encode(Node* node, char symbols, std::string Code);
    std::string encode(char ch);


    bool decode(const std::string& encodedText, const std::string& decodedText) const;
    Node* getRoot()
    {
        return m_root;
    }
    int height(Node* root) const;
    int height() const;

public:
    Node* m_root = nullptr;
};
