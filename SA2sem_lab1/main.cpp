#include "HashTable.hpp"

int main()
{
    MyHashTable<int> table(10);

    table.insert("123", 123);
    
    table.insert("130", 124);
    
    table.insert("125", 123);
    
    table.insert("136", 124);
    
    table.insert("133", 124);
    
    table.print();
    system("pause");
}