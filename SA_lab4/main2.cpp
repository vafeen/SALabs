// #include <iostream>
// #include <string>

// using namespace std;

// struct Tree
// {
//     char data;
//     Tree *left;
//     Tree *right;
// };

// void printTree(Tree *tree, string tab)
// {
//     if (tree != nullptr)
//     {
//         string new_tab = tab + "  ";
//         cout << tab << tree->data << '\n';
//         printTree(tree->left, new_tab);
//         printTree(tree->right, new_tab);
//     }
// }
// int main()
// {
//     string formula = "((5-5)+(7*(6+5)))";
//     Tree *root = buildTree(formula, 0, formula.length() - 1);

//     printTree(root, "");
//     system("pause");
//     // do something with the tree
//     return 0;
// }