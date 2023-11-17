#pragma once
#include "HashTable.h"

class HashTableTester
{
public:

    HashTableTester(const bool useConsoleOutput);
    ~HashTableTester() = default;
    void test(int maxSize);

private:
    bool m_useConsoleOutput;
    int max_size;


    void addAndClear();
    void search();
    void checkAdd(HashTable table, int countOfItems);
    void checkDestructor(HashTable table);

    void remove();
    void assign();
};