// #include <iostream>

// using namespace std;
// const size_t d = 26;
// class TrieNode
// {
// public:
//     char symbol;
//     TrieNode *next;
//     TrieNode *sibling;
// };
// class TrieList
// {
//     TrieNode *head;
// };

// struct MasTrie
// {
//     MasTrie *alph[d];
//     bool eow;
// };


// TrieNode *createTrieNode(char symbol)
// {
//     TrieNode *newNode = new TrieNode();
//     newNode->symbol = symbol;
//     newNode->next = nullptr;
//     newNode->sibling = nullptr;
//     return newNode;
// }

// void insertTrieNode(TrieNode *root, string word)
// {
//     TrieNode *currentNode = root;
//     for (char c : word)
//     {

//         TrieNode *nextNode = currentNode->next;
//         TrieNode *prevNode = nullptr;
//         while (nextNode && nextNode->symbol != c)
//         {
//             prevNode = nextNode;
//             nextNode = nextNode->sibling;
//         }
//         if (!nextNode)
//         {
//             nextNode = createTrieNode(c);
//             if (prevNode)
//                 prevNode->sibling = nextNode;
//             else
//                 currentNode->next = nextNode;
//         }
//         currentNode = nextNode;
//     }
// }

// bool searchTrieNode(TrieNode *root, string word)
// {
//     TrieNode *currentNode = root;
//     for (char c : word)
//     {
//         TrieNode *nextNode = currentNode->next;
//         while (nextNode && nextNode->symbol != c)
//         {
//             nextNode = nextNode->sibling;
//         }
//         if (!nextNode)
//         {
//             return false;
//         }
//         currentNode = nextNode;
//     }
//     return true;
// }
// void printTrie(TrieNode *root, int level = 0)
// {
//     if (root == nullptr)
//     {
//         return;
//     }

//     // Выводим символ и уровень текущего узла
//     for (int i = 0; i < level; i++)
//     {
//         std::cout << "---";
//     }
//     std::cout << root->symbol << std::endl;

//     // Рекурсивно выводим всех детей текущего узла
//     printTrie(root->next, level + 1);

//     // Рекурсивно выводим всех соседей текущего узла
//     printTrie(root->sibling, level);
// }

// // алгоритм вставки
// // представление узла массивом
// void insert(string str, size_t i, MasTrie *root)
// {
//     if (i < str.length())
//     {
//         if (i == str.length() - 1)
//             root->eow = 1;
//         else
//         {
//             if (root->alph[str[i] - 'a'] == nullptr)
//                 root->alph[str[i] - 'a'] = new MasTrie;
//             insert(str, i + 1, root->alph[str[i] - 'a']);
//         }
//     }
// }
