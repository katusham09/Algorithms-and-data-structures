#include <iostream>
#include <string>
#include <vector>

class HashTable
{
    class Node
    {
    private:
        int m_key;
        int m_value;
        Node* m_next;

    public:
        Node(int key, int value)
        {
            setKey(key);
            setValue(value);
            setNextNode(nullptr);
        }
        ~Node() = default;

        int getKey()
        {
            return m_key;
        }

        int getValue()
        {
            return m_value;
        }

        Node* getNextNode()
        {
            return m_next;
        }

        void setKey(int key)
        {
            m_key = key;
        }

        void setValue(int value)
        {
            m_value = value;
        }

        void setNextNode(Node* next)
        {
            m_next = next;
        }

        int& GetAdressValue() 
        {
            return m_value; 
        }
    };

public:
    HashTable();
    HashTable(int size);
    HashTable(const HashTable& copy);

    ~HashTable();

    void add(int key, int value);
    void printTable() const;
    void clear();
    void copyTable(const HashTable& copy);
    HashTable& operator=(const HashTable& copy);
    int& operator[](int key);
    void remove(int key);

    int getSize() { return m_size; }
    std::vector<Node*> getNodes() { return m_nodes; }
    int getCapacity() { return m_capacity; }
    std::vector<Node*> nodes() const
    {
        std::vector<Node*> nodes;

        for (Node* node : m_nodes) 
        {
             while (node)
             {
                 nodes.push_back(node);
                 node = node->getNextNode();
             }
        }
        return nodes;
    }

private:
    std::vector<Node*> m_nodes;
    int m_size;
    int m_capacity;
    HashFunction* m_hashFunction;

    void setSize(int newSize) 
    { 
        m_size = newSize; 
    }

    void setCapacity(int newCapacity) 
    {
        m_capacity = newCapacity; 
    }

    void setHashFunction(HashFunction* hashFunction) 
    {
        m_hashFunction = hashFunction; 
    }
};

class HashFunction
{
public:
    int getHash(int key, int size)
    {
        const int c = 18 % 5;
        const int d = 18 % 7;
        int hash = key % size;
        for (int i = 1;; i++)
        {
            hash = (hash + c * i + d * i * i) % size;
            if (hash < size)
                return hash;
        }
    }
    ~HashFunction() = default;
    HashFunction* clone() 
    {
        return new HashFunction(*this);
    }
};