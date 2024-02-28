#include "HashTable.hpp"

int main()
{
    MyHashTable<int> table(10);

    table.insert("1d3", 123);
    
    table.insert("1s0", 124);
    
    table.insert("ww", 123);
    
    table.insert("136", 124);
    
    table.insert("133", 124);
    
    table.print();
    system("pause");
}