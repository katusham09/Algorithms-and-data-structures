#include "HashTable.h"
#include <iostream>
#include <iomanip>

HashTable::HashTable()
{
    setSize(0);
    setCapacity(10);
    setHashFunction(new HashFunction());
}

HashTable::HashTable(int size)
{
    setSize(0);
    setCapacity(size);
    setHashFunction(new HashFunction());
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
            Node* previousNode = node;
       
            node = node->getNextNode();
            delete previousNode;
            
        }
    }
    for (int i = 0; i < m_capacity; i++)
    {
        m_nodes[i] = nullptr;
    }
    setSize(0);
}

void HashTable::add(int key, int value)
{
    int hash = m_hashFunction->getHash(key, m_capacity);
    Node* addNode = new Node(key, value);

    if (m_nodes[hash] == nullptr)
    {
        m_nodes[hash] = addNode;
    }
    else
    {
        Node* temp = m_nodes[hash];
        while (temp->getNextNode())
        {
            temp = temp->getNextNode();
        }
        temp->setNextNode(addNode);
    }
    m_size++;
}

bool HashTable::remove(int key)
{
    int hash = m_hashFunction->getHash(key, m_capacity);
    Node* temp = m_nodes[hash];
    Node* parent = nullptr;

    while (temp != nullptr)
    {
        if (temp->getKey() == key)
        {
            if (parent)
            {
                parent->setNextNode(temp->getNextNode());
                delete temp;
            }
            else
            {
                Node* nextNode = temp->getNextNode();
                delete temp;
                m_nodes[hash] = nextNode;
            }
            m_size--;
            return true;
        }
        parent = temp;
        temp = temp->getNextNode();
    }
    return false;
}

bool HashTable::contains(int key)
{
    int hash = m_hashFunction->getHash(key, m_capacity);
    Node* temp = m_nodes[hash];

    while (temp)
    {
        if (temp->getKey() == key)
        {
            return true;
        }

        temp = temp->getNextNode();
    }

    return false;
}

void HashTable::printTable() const
{
    std::cout << "Hash" << std::setw(18) << "(Key, Value)" << std::setw(26) << "(_table[i], _next)" << std::endl;
    for (int i = 0; i < m_capacity; i++) {
        std::cout << "Hash " << i << ":" << std::setw(4);
        Node* current = m_nodes[i];
        if (current != nullptr) {
            std::cout << std::setw(4) << "(" << current->getKey() << ", " << current->getValue() << ")";
            std::cout << std::setw(9) << "(" << current << ", " << current->getNextNode() << ") ";
            while (current->getNextNode())
            {
                current = current->getNextNode();
                std::cout << std::setw(4) << "(" << current->getKey() << ", " << current->getValue() << ")";
                std::cout << std::setw(9) << "(" << current << ", " << current->getNextNode() << ") ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void HashTable::copyTable(const HashTable& copy)
{
    clear();
    setSize(copy.m_size);
    setCapacity(copy.m_capacity);
    setHashFunction(copy.m_hashFunction->clone());

    for (Node* node : copy.nodes())
    {
        add(node->getKey(), node->getValue());
    }
}

HashTable& HashTable::operator=(const HashTable& copy)
{
    if (this != &copy)
    {
        delete m_hashFunction;
        copyTable(copy);
    }
    return *this;
}

int& HashTable::operator[](int key)
{
    if (contains(key))
    {
        throw "No key in table";
    }

    int hash = m_hashFunction->getHash(key, m_capacity);
    Node* temp = m_nodes[hash];

    while (temp)
    {
        if (temp->getKey() == key)
        {
            return temp->GetAdressValue();
        }

        temp = temp->getNextNode();
    }

}