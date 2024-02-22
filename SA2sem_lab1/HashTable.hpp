#pragma once
#include <vector>
#include <list>
#include <algorithm>

#include "AllDatStructures.hpp"
using namespace std;

enum class StatusTable
{
    FULL,
    EMPTY,
    DELETED
};

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
        StatusTable status;

        Data(StatusTable _status = StatusTable::EMPTY)
        {
            status = _status;
        }
        Data(string _key, hashValue _value, StatusTable _status)
        {
            key = _key;
            value = _value;
            status = _status;
        }
    };

    Node<Data> **table;

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
    Node<Data> **createTable(int size)
    {
        Node<Data> **result = new Node<Data> *[size];
        for (size_t i = 0; i < size; ++i)
        {
            result[i] = new Node<Data>;
        }
        return result;
    }

    void insert(string key, hashValue value)
    {
        int index = hash(key);
        if (table[index]->data.status == StatusTable::EMPTY || table[index]->data.status == StatusTable::DELETED)
        {
            table[index]->data.key = key;
            table[index]->data.value = value;
            table[index]->data.status = StatusTable::FULL;
        }
        else
        {
            Node<Data> *p = table[index];
            while (p->next != nullptr)
            {
                p = p->next;
            }
            Node<Data> *ins = new Node<Data>;
            ins->data.key = key;
            ins->data.value = value;
            ins->data.status = StatusTable::FULL;
            p->next = ins;
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
                if (p->next != nullptr)
                {
                    Node<Data> *del = p;
                    table[index] = del->next;
                    delete del;
                }
                else
                {
                    p->data.status = StatusTable::DELETED;
                }
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
            table[i] = new Node<Data>;
        }
    }

    int getSize() { return HashTable<hashValue>::tableSize; }

    bool isEmpty()
    {
        bool empty = true;
        for (size_t i = 0; i < HashTable<hashValue>::tableSize; ++i)
        {
            if (table[i]->data.status == StatusTable::FULL)
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
        if (table[index]->data.status == StatusTable::FULL)
        {
            Node<Data> *p = table[index];
            while (p != nullptr)
            {
                if (p->data.key == key && p->data.status == StatusTable::FULL)
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
            cout << "\n";
        }
        cout << "\n";
    }

protected:
    int summa(string key)
    {
        int sum = 0;
        for (size_t i = 0; i < key.size(); ++i)
        {
            int x = key[i];
            sum += x;
        }
        return sum;
    }
    int Gorner(int x)
    {
        int result = 5 * x + 6 * x * x;
        return result % HashTable<hashValue>::tableSize;
    }
    int hash(string key)
    {
        return Gorner(summa(key));
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

class Student
{
};
