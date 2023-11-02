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
Tree *buildTree(string formula, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    if (start == end)
    {
        Tree *node = new Tree();
        node->data = formula[start];
        node->left = nullptr;
        node->right = nullptr;
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
        return buildTree(formula, start + 1, end - 1);
    }
    return nullptr;
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
int stoi(char symbol)
{
    int sym = symbol;
    if (sym >= 48 && sym <= 57)
        return sym - 48;
    return 0;
}
int s4et(Tree *tree)
{
    if (tree)
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
}

int main()
{
    ifstream filer("formula.txt");
    Tree *tree = nullptr;
    // vector<char> terminal = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string formula = "((5+5)*((3*5)+(5*5)))";//числа [0;9]
    tree = buildTree(formula, 0, formula.length() - 1);
    printTree(tree, "");

    cout << "\n\n\n"
         << s4et(tree) << "\n";
    pau;
    return 0;
}