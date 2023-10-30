#include "trees.hpp"
#include <vector>

using namespace std;
#define pau system("pause")
bool symbolIs(const vector<char> &what, char symbol)
{
    for (size_t i = 0; i < what.size(); i++)
        if (symbol == what[i])
            return 1;
    return 0;
}



Tree *read(ifstream &filer)
{
    char symbol;
    filer >> symbol; // считываем вторую (
    filer >> symbol; // считываем первое число
    Tree *tree = nullptr;
    init(tree, '0');           // кидаем в голову ноль вместо знака
    init(tree->left, symbol);  // кидаем в левое поддерево число
    filer >> symbol;           // считываем знак
    setTree(tree, symbol);     // кидаем в голову знак
    filer >> symbol;           // считываем второе число
    init(tree->right, symbol); // кидаем его в правую часть
    filer >> symbol;           // считываем )
    return tree;
}

int stoi(char x)
{
    switch (x)
    {

    case '0':
    {
        return 0;
        break;
    }
    case '1':
    {
        return 1;
        break;
    }
    case '2':
    {
        return 2;
        break;
    }
    case '3':
    {
        return 3;
        break;
    }
    case '4':
    {
        return 4;
        break;
    }
    case '5':
    {
        return 5;
        break;
    }
    case '6':
    {
        return 6;
        break;
    }
    case '7':
    {
        return 7;
        break;
    }
    case '8':
    {
        return 8;
        break;
    }
    case '9':
    {
        return 9;
        break;
    }
    }
}

void printTree(Tree *tree, string tab)
{
    if (tree != nullptr)
    {
        string new_tab = tab + "  ";
        cout << tab << tree->data << '\n';
        printTree(tree->left, new_tab);
        printTree(tree->right, new_tab);
    }
}

int s4et(Tree *tree)
{
    vector<char> terminal = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (symbolIs(terminal, tree->data))
        return stoi(tree->data);

    switch (tree->data)
    {
    case '+':
        return s4et(tree->left) + s4et(tree->right);
        break;
    case '-':
        return s4et(tree->left) - s4et(tree->right);
        break;
    case '*':
        return s4et(tree->left) * s4et(tree->right);
        break;
    }
}

int main()
{
    ifstream filer("formula.txt");
    Charstack stack;
    Tree *tree = nullptr;
    char symbol;
    vector<char> znak = {'+', '-', '*'};
    vector<char> terminal = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    filer >> symbol;               // считать (
    Tree *lefttree = read(filer);  // считать левую часть формулы
    filer >> symbol;               // считать знак
    Tree *righttree = read(filer); // считать правую часть формулы

    init(tree, symbol, lefttree, righttree);
    filer >> symbol; // считать )
    printTree(tree, "");
    int x = s4et(tree);
    cout << x;

    pau;
    return 0;
}