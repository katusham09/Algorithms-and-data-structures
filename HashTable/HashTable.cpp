#include "HashTable.h"
#include <iostream>

HashTable::HashTable()
{
    setSize(0);
    setCapacity(10);
    setHashFunction(new HashFunction());
    m_nodes.resize(m_capacity, nullptr);
}

HashTable::HashTable(int size)
{
    setSize(0);
    setCapacity(size);
    setHashFunction(new HashFunction());
    m_nodes.resize(m_capacity, nullptr);
}

HashTable::HashTable(const HashTable& copy)
{
    setSize(0);
    setCapacity(copy.m_capacity);
    setHashFunction(copy.m_hashFunction->clone());
    copyTable(copy);
}

HashTable::~HashTable()
{
    clear();
    delete m_hashFunction;
}

void HashTable::clear()
{
    for (Node* node : m_nodes)
    {
        while (node)
        {
            delete node;
            node = node->getNextNode();
        }
    }
    setSize(0);
}

void HashTable::add(int key, int value)
{
    int hash = m_hashFunction->getHash(key, m_capacity);
    Node* addNode = new Node(key, value);
    if (m_nodes[hash] == nullptr)
    {
        m_nodes[hash] == addNode;
        m_size++;
    }
    else
    {
        while (m_nodes[hash]->getNextNode() != nullptr)
        {
            m_nodes[hash] = m_nodes[hash]->getNextNode();
        }
        m_nodes[hash] -> setNextNode(addNode);
        m_size++;
    }
}

void HashTable::remove(int key)
{
    int hash = m_hashFunction->getHash(key, m_capacity);
    Node* temp = m_nodes[hash];
    Node* parent = nullptr;
    while (temp != nullptr)
    {
        if (temp->getKey() == key && temp->getNextNode() == nullptr)
        {
            delete temp;
            return;
        }

        if (temp->getKey() == key)
        {


        }
    }
}