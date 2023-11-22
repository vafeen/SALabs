#include <iostream>
// #include "trie-trees.hpp"
#include "tree.hpp"
using namespace std;

int main()
{
    TrieNode *root = new TrieNode; // Создание корневого узла
    root->symbol = '\0';           // Корневой символ

    // Добавление слов в дерево
    addWord(root, "apple");
    addWord(root, "banana");
    addWord(root, "car");
    addWord(root, "cat");

    // Поиск слов в дереве
    // cout << "Search 'apple': " << (searchWord(root, "apple") ? "found" : "not found") << endl;
    // cout << "Search 'banana': " << (searchWord(root, "banana") ? "found" : "not found") << endl;
    // cout << "Search 'car': " << (searchWord(root, "car") ? "found" : "not found") << endl;
    // cout << "Search 'cat': " << (searchWord(root, "cat") ? "found" : "not found") << endl;
    // cout << "Search 'dog': " << (searchWord(root, "dog") ? "found" : "not found") << endl;
    printTrie(root);
    system("pause");
    return 0;
}