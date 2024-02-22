#include "trees.hpp"

#define pau system("pause")

// Функция для проверки, является ли символ символом из заданного вектора
bool symbolIs(const vector<char> &what, char symbol)
{
    for (size_t i = 0; i < what.size(); i++)
        if (symbol == what[i])
            return 1; // Возвращаем true, если символ найден в векторе
    return 0;         // Возвращаем false, если символ не найден в векторе
}

// Функция для построения дерева на основе заданной формулы
Tree *buildTree(string formula, int start, int end)
{
    // Условие выхода из рекурсии
    if (start > end)
    {
        return nullptr;
    }
    if (start == end)
    {
        // Создание нового узла для символа в формуле
        Tree *node = new Tree();
        node->data = formula[start];
        // node->left = nullptr;
        // node->right = nullptr;
        return node;
    }
    int count = 0;
    int i = start;
    while (i <= end)
    {
        if (formula[i] == '(')
        {
            count++;
        }
        else if (formula[i] == ')')
        {
            count--;
        }
        else if (count == 0 && (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/'))
        {
            // Создание нового узла для арифметической операции
            Tree *node = new Tree();
            node->data = formula[i];
            node->left = buildTree(formula, start, i - 1);
            node->right = buildTree(formula, i + 1, end);
            return node;
        }
        i++;
    }
    if (formula[start] == '(' && formula[end] == ')')
    {
        // Игнорирование скобок и построение дерева внутри них
        return buildTree(formula, start + 1, end - 1);
    }
    return nullptr;
}

// Функция для вывода дерева в консоль
void printTree(Tree *root, int indent = 0)
{
    if (root == nullptr)
    {
        return;
    }
    size_t tab = 4;
    // вывод правого поддерева
    printTree(root->right, indent + tab);
    // вывод узла
    cout << string(indent, ' ') << root->data << '\n';
    // вывод левого поддерева
    printTree(root->left, indent + tab);
}

// Функция для перевода символа-цифры в число
int stoi(char symbol)
{
    int sym = symbol;
    if (sym >= 48 && sym <= 57)
        return sym - 48;
    return 0;
}

// Функция для вычисления значения выражения, представленного деревом
int s4et(Tree *tree)
{
    if (tree)
    {
        vector<char> terminal = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        if (symbolIs(terminal, tree->data))
            return stoi(tree->data); // Если узел содержит цифру, возвращаем его значение

        switch (tree->data)
        {
        case '+':
            return s4et(tree->left) + s4et(tree->right); // Для операции сложения, рекурсивно вызываем значение левого и правого поддеревьев
            break;
        case '-':
            return s4et(tree->left) - s4et(tree->right); // Для операции вычитания, рекурсивно вызываем значение левого и правого поддеревьев
            break;
        case '*':
            return s4et(tree->left) * s4et(tree->right); // Для операции умножения, рекурсивно вызываем значение левого и правого поддеревьев
            break;
        }
    }
    return 0;
}

int main()
{
    ifstream filer("formula.txt");
    string formula;
    while (getline(filer, formula))
    {
        cout << "\n\n\nFORMULA =  " << formula << "\n";
        Tree *tree = buildTree(formula, 0, formula.length() - 1);
        printTree(tree, 0);
        cout << "\nResult = "
             << s4et(tree);
    }
    cout << "\n\n\n\n\n\n";
    pau;
    return 0;
}
