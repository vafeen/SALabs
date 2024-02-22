#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    char symbol;
    vector<TrieNode *> children;
    void printTrie(int tabs = 0)
    {

        // Вывод символа и уровня этого узла
        for (int i = 0; i < tabs; i++)
        {
            cout << "---";
        }
        cout << symbol << '\n';

        // рекурсивно вызываем вывод детей
        for (size_t i = 0; i < children.size(); ++i)
        {
            children[i]->printTrie(tabs + 1);
        }
    }
};

class Trie
{
    TrieNode *root;

    int countWordsHelper(TrieNode *current)
    {
        int count = 0;
        if (current->children.size() == 0)
        {
            count++;
            return count;
        }
        for (TrieNode *child : current->children)
        {
            count += countWordsHelper(child);
        }
        return count;
    }

public:
    Trie()
    {
        root = new TrieNode();
        root->symbol = ' ';
    }

    void printTrie()
    {
        root->printTrie();
    }

    // Функция добавления слова в Trie-дерево.
    void addWord(string word)
    {
        TrieNode *current = root; // Устанавливаем указатель на корень Trie-дерева.

        // Проходим по каждому символу в слове.
        for (char c : word)
        {
            bool found = false; // Флаг, указывающий наличие символа в дочерних узлах текущего узла.

            // Проверяем все дочерние узлы текущего узла.
            for (TrieNode *child : current->children)
            {
                // Если найден дочерний узел с символом c,
                // перемещаем указатель на него и устанавливаем флаг found в true.
                if (child->symbol == c)
                {
                    current = child;
                    found = true;
                    break;
                }
            }

            // Если символ c не найден среди дочерних узлов текущего узла,
            // создаем новый узел с символом c и добавляем его в дочерние узлы текущего узла.
            if (!found)
            {
                TrieNode *newNode = new TrieNode();
                newNode->symbol = c;
                current->children.push_back(newNode);
                current = newNode;
            }
        }
    }
    // Функция предназначена для поиска заданного слова в trie-дереве.
    bool searchWord(string word)
    {
        TrieNode *current = root; // Устанавливаем текущую вершину в корневую вершину дерева.
        for (char c : word)       // Проходим по каждому символу в заданном слове.
        {
            bool found = false;                       // Индикатор нахождения символа в дочерних вершинах текущей вершины.
            for (TrieNode *child : current->children) // Проходим по каждому дочернему узлу текущей вершины.
            {
                if (child->symbol == c) // Если символ в дочерней вершине совпадает с текущим символом слова,
                {
                    current = child; // обновляем текущую вершину до этой дочерней вершины.
                    found = true;    // Устанавливаем индикатор нахождения в true.
                    break;           // Выходим из цикла, так как символ найден.
                }
            }
            if (!found) // Если символ не найден в дочерних вершинах текущей вершины,
            {
                return false; // возвращаем false, так как слово не найдено в дереве.
            }
        }
        return true; // Если прошли по всем символам и все символы найдены в дереве, возвращаем true.
    }
    int countWordsStartingWith(string prefix)
    {
        TrieNode *current = root; // Текущий узел, начиная с корневого

        // Перебираем символы префикса
        for (char c : prefix)
        {
            bool found = false;

            // Ищем среди дочерних узлов текущего узла тот, у которого символ совпадает с текущим символом префикса
            for (TrieNode *child : current->children)
            {
                if (child->symbol == c)
                {
                    current = child; // Переходим к найденному дочернему узлу
                    found = true;
                    break;
                }
            }

            // Если не найден дочерний узел с требуемым символом, значит нет слов в дереве с таким префиксом, возвращаем 0
            if (!found)
            {
                return 0;
            }
        }

        // Вызываем вспомогательную функцию, которая рекурсивно подсчитывает количество слов, начинающихся с текущего узла
        return countWordsHelper(current);
    }
};
