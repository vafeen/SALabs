#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Tree
{
public:
    char data;
    Tree *left;
    Tree *right;
    Tree(char _data) : left(nullptr), right(nullptr), data(_data) {}
    Tree() : left(nullptr), right(nullptr) {}
    ~Tree()
    {
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
    }
};
class Node
{
public:
    Tree *data;
    Node *next;
    Node(Tree *elem) : data(elem), next(nullptr) {}
};
class Charstack
{
    struct Node
    {
        char data;
        Node *next;
    };
    Node *top;

public:
    Charstack() : top(nullptr) {}
    ~Charstack()
    {
        clear();
    }
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(char elem)
    {
        Node *p = new Node;
        p->data = elem;
        p->next = top;
        top = p;
    }
    void pop()
    {
        Node *p = top;
        top = top->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }
    char peek()
    {
        return top->data;
    }
};
class Tstack
{
    struct Node
    {
        Tree *data;
        Node *next;
    };
    Node *top;

public:
    Tstack() : top(nullptr) {}
    ~Tstack()
    {
        clear();
    }
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(Tree *elem)
    {
        Node *p = new Node;
        p->data = elem;
        p->next = top;
        top = p;
    }
    void pop()
    {
        Node *p = top;
        top = top->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }
    Tree *peek()
    {
        return top->data;
    }
};

class TQueue
{

    Node *head;
    Node *tail;

public:
    TQueue() : head(nullptr), tail(nullptr) {}
    ~TQueue()
    {
        clear();
    }
    void clear()
    {
        while (!isEmpty())
            DeltoQueue();
    }
    bool isEmpty()
    {
        return head == nullptr;
    }

    void AddtoQueue(Tree *elem)
    {
        if (tail == nullptr && head == nullptr)
        {
            head = new Node(elem);
            tail = head;
        }
        else
        {
            Node *p = new Node(elem);
            tail->next = p;
            tail = p;
        }
    }

    Tree *peek()
    {
        return head->data;
    }
    void DeltoQueue()
    {
        Node *p = head;
        head = head->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }
};

void setTree(Tree *&head, char data)
{
    head->data = data;
}

// 1. Создание пустого бинарного дерев
void init(Tree *&root);
// 2. Создание бинарного дерева, содержащего один узел по заданному элементу
void init(Tree *&root, char elem);
// 3. Создание бинарного дерева по заданному корню и двум бинарным поддеревьям этого корня
void init(Tree *&root, char elem, Tree *lesftSubTree, Tree *rightSubtree);
// 4. Удаление бинарного дерева
void destroyTree(Tree *&root);
// 5. Проверка на пустоту
// 6. Определение или изменение данных, записанных в корне бинарного дерева
// 7. Присоединение к корню дерева левого или правого дочернего узла
// 8. Присоединение к корню дерева левого или правого поддерева
bool attachLeftSubTree(Tree *root, Tree *subtree, bool leftIsNullAndRightIsOne);
// 9. Отсоединение от корня дерева левого или правого поддерева
// в leftSubtree кидаем дерево, которое отсоединяем
void detachLeftSubtree(Tree *root, Tree *&leftSubtree);
Tree *detachLeftSubtree(Tree *root);
// 10. Получение корня левого или правого поддерева
void copyLeftSubtree(Tree *root, Tree *&newLeftRoot);
Tree *copyLeftSubtree(Tree *root);
// 11. Создание копии дерева
// рекурсия
void copyTree(Tree *root, Tree *&newRoot);

bool attachLeftSubTree(Tree *root, Tree *subtree, bool leftIsNullAndRightIsOne);

// 1. Создание пустого бинарного дерев
void init(Tree *&root)
{
    root = nullptr;
}

// 2. Создание бинарного дерева, содержащего один узел по заданному элементу
void init(Tree *&root, char elem)
{
    root = new Tree;
    root->data = elem;
    root->left = nullptr;
    root->right = nullptr;
}
// 3. Создание бинарного дерева по заданному корню и двум бинарным поддеревьям этого корня
void init(Tree *&root, char elem, Tree *lesftSubTree, Tree *rightSubtree)
{
    init(root, elem);
    // root->left = lesftSubTree;
    // root->right = rightSubtree;
    attachLeftSubTree(root, lesftSubTree, 0);
    attachLeftSubTree(root, rightSubtree, 1);
}
// 4. Удаление бинарного дерева
void destroyTree(Tree *&root)
{
    if (root != nullptr)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        root->left = nullptr;
        root->right = nullptr;
        delete root;
        root = nullptr;
    }
}
// 5. Проверка на пустоту
bool isEmpty(Tree *root)
{
    return root == nullptr;
}
// 6. Определение или изменение данных, записанных в корне бинарного дерева
// 7. Присоединение к корню дерева левого или правого дочернего узла
// 8. Присоединение к корню дерева левого или правого поддерева
bool attachLeftSubTree(Tree *root, Tree *subtree, bool leftIsNullAndRightIsOne)
{
    bool canAttach = 0;
    if (leftIsNullAndRightIsOne)
    {
        if (root->right == nullptr)
        {
            root->right = subtree;
            canAttach = 1;
        }
    }
    else
    {
        if (root->left == nullptr)
        {
            root->left = subtree;
            canAttach = 1;
        }
    }
    return canAttach;
}
// 9. Отсоединение от корня дерева левого или правого поддерева
// в leftSubtree кидаем дерево, которое отсоединяем
void detachLeftSubtree(Tree *root, Tree *&leftSubtree)
{
    leftSubtree = root->left;
    root->left = nullptr;
}
Tree *detachLeftSubtree(Tree *root)
{
    Tree *leftSubtree;
    init(leftSubtree);
    leftSubtree = root->left;
    root->left = nullptr;
    return leftSubtree;
}
// 10. Получение корня левого или правого поддерева
void copyLeftSubtree(Tree *root, Tree *&newLeftRoot)
{
    copyTree(root->left, newLeftRoot);
}
Tree *copyLeftSubtree(Tree *root)
{
    Tree *newLeftRoot = nullptr;
    if (root->left == nullptr)
        init(newLeftRoot);
    else
        copyTree(root->left, newLeftRoot);
    return newLeftRoot;
}
// 11. Создание копии дерева
// рекурсия
void copyTree(Tree *root, Tree *&newRoot)
{
    if (root != nullptr)
    {
        // newRoot = new Tree;
        // newRoot->data = root->data;
        // newRoot->left = nullptr;
        // newRoot->right = nullptr;
        // 4 строчки эти == init(newRoot, root->data);
        init(newRoot, root->data);
        copyTree(root->left, newRoot->left);
        copyTree(root->right, newRoot->right);
    }
}

// Обход бинарного дерева

// 1. Префиксный
void preoder(Tree *root)
{
    if (root != nullptr)
    {
        cout << root->data;
        preoder(root->left);
        preoder(root->right);
    }
}

// 2. Инфиксный
void infoder(Tree *root)
{
    if (root != nullptr)
    {
        infoder(root->left);
        cout << root->data;
        infoder(root->right);
    }
}
// 3. Постфиксный
void postoder(Tree *root)
{
    if (root != nullptr)
    {
        // Правильно?
        preoder(root->left);
        preoder(root->right);
        cout << root->data;
    }
}

// Обход в ширину

// BFC - обход в ширину, DFC - обход в глубину
void breathFirstSearch(Tree *root)
{
    TQueue queue;
    queue.AddtoQueue(root);
    while (!queue.isEmpty())
    {
        Tree *cur = queue.peek();
        if (cur->left)
            queue.AddtoQueue(cur->left);
        if (cur->right)
            queue.AddtoQueue(cur->left);
        queue.DeltoQueue();
    }
}
// итеративный обход в глубину со стеком
// Порядок BAC - корень, левое, правое

// инфиксный
void inoderIrerative(Tree *root)
{
    Tstack stack;

    bool done = 0;
    Tree *cur = root;
    while (!done)
    {
        if (cur != nullptr)
        {
            stack.push(cur);
            cur = cur->left;
        }
        else if (!stack.isEmpty())
        {
            cur = stack.peek();
            stack.pop();
            cout << cur->data;
            cur = cur->right;
        }
        else
            done = 1;
    }
}

// Создание балансированного дерева
#include <fstream>
Tree *createNode(int n, ifstream &filer)
{
    if (n == 0)
        return nullptr;

    Tree *root = new Tree;
    filer >> root->data;
    root->left = createNode(n / 2, filer);
    root->right = createNode(n - n / 2, filer);

    return root;
}
void createbalanceTree(Tree *&root, const string &filename)
{
    ifstream filer(filename);
    int n;
    filer >> n;
    root = createNode(n, filer);
    filer.close();
}
