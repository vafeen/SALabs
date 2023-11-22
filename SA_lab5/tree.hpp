#include <iostream>
using namespace std;

// Структура узла дерева
class TrieNode
{
public:
    char symbol;       // Символ узла
    TrieNode *next;    // Указатель на первого потомка узла
    TrieNode *sibling; // Указатель на следующего соседа узла
    TrieNode(){
        next = nullptr; 
        sibling = nullptr; 
    }
};

// Функция для добавления слова в дерево
void addWord(TrieNode *root, string word)
{
    TrieNode *current = root; // Текущий узел

    // Перебор всех символов в слове
    for (int i = 0; word[i] != '\0'; i++)
    {
        char symbol = word[i];

        // Поиск среди потомков текущего узла
        TrieNode *child = current->next;
        TrieNode *prevChild = nullptr;

        while (child != nullptr && child->symbol != symbol)
        {
            prevChild = child;
            child = child->sibling;
        }

        // Если символ не найден среди потомков, создаем новый узел
        if (child == nullptr)
        {
            TrieNode *newNode = new TrieNode;
            newNode->symbol = symbol;
            newNode->next = nullptr;
            newNode->sibling = nullptr;

            // Добавляем новый узел в список потомков текущего узла
            if (prevChild == nullptr)
            {
                current->next = newNode;
            }
            else
            {
                prevChild->sibling = newNode;
            }

            // Переходим к новому узлу
            current = newNode;
        }
        else
        {
            // Переходим к существующему узлу
            current = child;
        }
    }
}
void printTrie(TrieNode *root, int level = 0)
{
    if (root == nullptr)
    {
        return;
    }

    // Выводим символ и уровень текущего узла
    for (int i = 0; i < level; i++)
    {
        std::cout << "---";
    }
    std::cout << root->symbol << std::endl;

    // Рекурсивно выводим всех детей текущего узла
    printTrie(root->next, level + 1);

    // Рекурсивно выводим всех соседей текущего узла
    printTrie(root->sibling, level);
}
// Функция для поиска слова в дереве
bool searchWord(TrieNode *root, string word)
{
    TrieNode *current = root; // Текущий узел

    // Перебор всех символов в слове
    for (int i = 0; word[i] != '\0'; i++)
    {
        char symbol = word[i];

        // Поиск среди потомков текущего узла
        TrieNode *child = current->next;

        while (child != nullptr && child->symbol != symbol)
        {
            child = child->sibling;
        }

        // Если символ не найден, слово не принадлежит дереву
        if (child == nullptr)
        {
            return false;
        }

        // Переходим к существующему узлу
        current = child;
    }

    // Если все символы слова найдены, слово принадлежит дереву
    return true;
}
