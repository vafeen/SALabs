#include <iostream>

using namespace std;
const size_t d = 26;
struct TrieNode
{
    char symbol;
    TrieNode *child;
    TrieNode *sibling;
};
struct MasTrie
{
    MasTrie *alph[d];
    bool eow;
};

// алгоритм вставки
// представление узла массивом
void insert(string str, size_t i, MasTrie *root)
{
    if (i < str.length())
    {
        if (i == str.length() - 1)
            root->eow = 1;
        else
        {
            if (root->alph[str[i] - 'a'] == nullptr)
                root->alph[str[i] - 'a'] = new MasTrie;
            insert(str, i + 1, root->alph[str[i] - 'a']);
        }
    }
}

