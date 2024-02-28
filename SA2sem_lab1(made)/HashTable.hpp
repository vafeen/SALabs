#pragma once
#include <vector>
#include <list>
#include <algorithm>

#include "AllDatStructures.hpp"
using namespace std;

size_t findNumber(size_t size);

template <class hashValue>
class HashTable
{

public:
    virtual void insert(string key, hashValue value) = 0;
    virtual bool remove(string key) = 0;
    virtual bool find(string key) = 0;

    virtual void clear() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual hashValue *get(string key) = 0;
    virtual void print() = 0;

protected:
    virtual int hash(string key) = 0;
    size_t tableSize;
};

template <class hashValue>
class MyHashTable : public HashTable<hashValue>
{
    struct Data
    {
        string key;
        hashValue value;
    };

    Node<Data> **table;

    size_t zapolneno = 0;

public:
    MyHashTable(int _tableSize)
    {
        HashTable<hashValue>::tableSize = _tableSize;
        table = createTable(_tableSize);
    }
    ~MyHashTable()
    {
        for (size_t i = 0; i < HashTable<hashValue>::tableSize; ++i)
        {
            myList::ClearList(table[i]);
        }
        delete[] table;
    }
    Node<Data> **createTable(size_t size)
    {
        Node<Data> **result = new Node<Data> *[size];
        for (size_t i = 0; i < size; ++i)
        {
            result[i] = nullptr;
        }
        return result;
    }

    void insert(string key, hashValue value)
    {
        Node<Data> *ins = new Node<Data>;
        ins->data.key = key;
        ins->data.value = value;
        int index = hash(key);
        if (table[index] == nullptr)
        {
            table[index] = ins;
        }
        else
        {
            ins->next = table[index];
            table[index] = ins;
        }
        zapolneno += 1;
        if (HashTable<hashValue>::tableSize / 2 == zapolneno)
        {
            tableResize();
        }
    }
    bool remove(string key)
    {
        if (get(key) != nullptr)
        {
            int index = hash(key);
            Node<Data> *p = table[index];
            if (p != nullptr && p->data.key == key)
            {

                Node<Data> *del = p;
                table[index] = del->next;
                delete del;
                zapolneno -= 1;
                return true;
            }
            else
            {
                while (p->next != nullptr)
                {
                    if (p->next->data.key == key)
                    {
                        Node<Data> *del = p->next;
                        p->next = del->next;
                        delete del;
                        zapolneno -= 1;
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool find(string key)
    {
        return get(key) == nullptr;
    }

    void clear()
    {
        for (size_t i = 0; i < HashTable<hashValue>::tableSize; ++i)
        {
            myList::ClearList(table[i]);
            table[i] = nullptr;
        }
    }

    int getSize() { return HashTable<hashValue>::tableSize; }

    bool isEmpty()
    {
        bool empty = true;
        for (size_t i = 0; i < HashTable<hashValue>::tableSize; ++i)
        {
            if (table[i] != nullptr)
            {
                empty = false;
            }
        }
        return empty;
    }
    string isEmptyString()
    {
        if (isEmpty())
        {
            return "isEmpty";
        }
        else
        {
            return "isNotEMpty";
        }
    }

    hashValue *get(string key)
    {
        int index = hash(key);
        if (table[index] != nullptr)
        {
            Node<Data> *p = table[index];
            while (p != nullptr)
            {
                if (p->data.key == key)
                {
                    return &p->data.value;
                }
                p = p->next;
            }
        }
        return nullptr;
    }

    void print()
    {
        cout << "\n";
        for (size_t i = 0; i < HashTable<hashValue>::tableSize; ++i)
        {
            Node<Data> *p = table[i];
            while (p != nullptr)
            {
                cout << "{" << p->data.key << "-" << p->data.value << "}, ";
                p = p->next;
            }
            if (table[i] == nullptr)
            {
                cout << "null";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void tableResize()
    {
        int newSize = findNumber(HashTable<hashValue>::tableSize);
        Node<Data> **new_table = table;
        table = createTable(newSize);

        for (size_t i = 0; i < HashTable<hashValue>::tableSize; ++i)
        {
            Node<Data> *p = new_table[i];
            while (p != nullptr)
            {
                insert(p->data.key, p->data.value);
                p = p->next;
            }
        }
    }

protected:
    int Gorner(string key)
    {
        size_t size = key.size();
        int result = 0;
        int p = 3;
        for (size_t i = 0; i < size; ++i)
        {
            int x = key[size - 1 - i];
            result += x;
            result *= p;
        }
        return result;
    }
    int hash(string key)
    {
        return Gorner(key) % HashTable<hashValue>::tableSize;
    }
    // void insert(string key, hashValue value)
    // {
    //     int index = hash(key);
    //     vector<tdata> l = cells[index];

    //     // if(cells[index])
    //     if (iterator == l.end())
    //     {
    //         l.push_back(elem);
    //         tdata elem;
    //         elem.key = key;
    //         elem.value = value;
    //         myList<tdata>::iterator i = find_if(
    //             l.begin(),
    //             l.end(),
    //             [key](tdata &data)
    //             { return if (data.key == key); });
    //     }
    //     else
    //     {
    //         i.value = value;
    //     }
    // }
};

bool isSimple(int number)
{
    bool isSimpleNUmber = true;
    for (size_t i = 2; i < number / 2 + 1; ++i)
    {
        if (number % i == 0)
        {
            isSimpleNUmber = false;
        }
    }
    return isSimpleNUmber;
}

size_t findNumber(size_t size)
{
    size_t x = size;
    bool simpleFound = false;
    while (simpleFound)
    {
        x += 1;
        if (isSimple(x))
        {
            return x;
        }
    }
}