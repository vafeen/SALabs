#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node() : next(nullptr) {}
    Node(T elem) : next(nullptr), data(elem) {}
};

    // 1)	Линейные однонаправленные списки БЕЗ заглавного звена:
    namespace myList
{
    // 1.	Инициализация списка (создание пустого списка).
    template <class T>
    void init(Node<T> * &head)
    {
        head = nullptr;
    }

    // 2.	Проверка на пустоту.
    template <class T>
    bool isEmpty(Node<T> * &head)
    {
        return head == nullptr;
    }

    // 3.Добавление элемента в список:
    // 	в начало списка (в голову списка);
    template <class T>
    void AddToHead(Node<T> * &head, T elem)
    {
        Node<T> *p = new Node<T>;
        p->data = elem;
        p->next = head;
        head = p;
    }

    // 	после заданного элемента (заданный элемент определяется указателем).
    template <class T>
    void AddAfterNode(Node<T> * &pNode, T elem)
    {
        Node<T> *p = new Node<T>;
        p->data = elem;
        p->next = pNode->next;
        pNode->next = p;
    }

    // 4.	Удаление элемента из списка:
    // 	из начала списка (из головы списка);
    template <class T>
    void DeleteFromHead(Node<T> * &head)
    {
        Node<T> *p = head;
        head = head->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }

    // 	после заданного элемента (заданный элемент определяется указателем).
    template <class T>
    void DeleteAfterNode(Node<T> * &pNode)
    {
        Node<T> *p = pNode->next;
        pNode->next = p->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }

    // поиск места для списка
    template <class T>
    Node<T> *Search(Node<T> * head, T elem)
    {
        Node<T> *p = head;
        while (p->next && p->next->data <= elem)
        {
            p = p->next;
        }
        return p;
    }

    // 5.	Создание списка:
    // 	в прямом порядке;
    template <class T>
    void CreateListInDirect(Node<T> * &head, vector<T> elems)
    {
        AddToHead(head, elems[0]);
        Node<T> *tail = head;
        for (size_t i = 1; i < elems.size(); ++i)
        {
            AddAfterNode(tail, elems[i]);
            tail = tail->next;
        }
    }

    // 	в обратном порядке;
    template <class T>
    void CreateReversedList(Node<T> * &head, vector<T> elems)
    {

        for (size_t i = 0; i < elems.size(); ++i)
        {
            AddToHead(head, elems[i]);
        }
    }

    // 	упорядоченно.
    template <class T>
    void CreateNormalList(Node<T> * &head, std::vector<T> elems)
    {
        for (size_t i = 0; i < elems.size(); ++i)
        {
            T elem = elems[i];
            if (head == nullptr)
                AddToHead(head, elem);
            else
            {
                if (elem <= head->data)
                    AddToHead(head, elem);
                if (elem > head->data)
                {
                    Node<T> *searched = nullptr;
                    searched = Search(head, elem);
                    AddAfterNode(searched, elem);
                }
            }
        }
    }

    // 6.	Печать списка.
    template <class T>
    void PrintList(Node<T> * head)
    {
        Node<T> *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 3)	Рекурсивная печать списка (без заглавного звена)
    template <class T>
    void PrintListRecurse(Node<T> * head)
    {
        if (head)
        {
            cout << head->data << " ";
            PrintListRecurse(head->next);
        }
    }

    // 4)	Рекурсивная функция суммы элементов списка (без заглавного звена)
    template <class T>
    T SumResult(Node<T> * head)
    {
        if (!head)
            return 0;
        return head->data + SumResult(head->next);
    }

    // 7.	Уничтожение списка.
    template <class T>
    void ClearList(Node<T> * &head)
    {
        while (!isEmpty(head))
            DeleteFromHead(head);
    }
}

// 2)	Линейные однонаправленные списки С заглавным звеном:
namespace listWithMain
{
    template <class T>
    void init(Node<T> *&head)
    {
        head = new Node<T>;
        head->next = nullptr;
    }

    template <class T>
    bool isEmpty(Node<T> *&head)
    {
        return head->next == nullptr;
    }

    template <class T>
    void AddAfterNode(Node<T> *&pNode, T elem)
    {
        Node<T> *p = new Node<T>;
        p->data = elem;
        p->next = pNode->next;
        pNode->next = p;
    }

    template <class T>
    void DeleteAfterNode(Node<T> *&pNode)
    {
        Node<T> *p = pNode->next;
        pNode->next = p->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }

    template <class T>
    void CreateNormalList(Node<T> *&head)
    {
        int count;
        cout << "List duration?\n";
        cin >> count;
        T elem;
        cout << "Input elements:\n";
        for (int i = 0; i < count; ++i)
        {
            cin >> elem;
            if (head->next == nullptr)
                AddAfterNode(head, elem);
            else
            {
                if (elem <= head->next->data)
                    AddAfterNode(head, elem);
                if (elem > head->next->data)
                    AddAfterNode(Search(head->next, elem), elem);
            }
        }
    }

    template <class T>
    Node<T> *Search(Node<T> *head, T elem)
    {
        Node<T> *p = head;
        while (p->next && p->next->data <= elem)
        {
            p = p->next;
        }
        return p;
    }

    template <class T>
    void PrintList(Node<T> *head)
    {
        Node<T> *p = head->next;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    template <class T>
    void ClearList(Node<T> *&head)
    {
        while (!isEmpty(head))
            DeleteAfterNode(head);
    }

    // 3)	Рекурсивная печать списка (с заглавным звеном)
    template <class T>
    void PrintListRecurse(Node<T> *head)
    {
        if (head->next)
        {
            cout << head->next->data << " ";
            PrintListRecurse(head->next);
        }
    }

    // 4)	Рекурсивная функция суммы элементов списка (с заглавным звеном)
    template <class T>
    T SumResult(Node<T> *head)
    {
        if (!head->next)
            return 0;
        return head->next->data + SumResult(head->next);
    }
}

// 5)	Двунаправленные списки:
template <class T>
class Node_d
{
public:
    T data;
    Node_d<T> *next;
    Node_d<T> *prev;
    Node_d(T elem)
    {
        data = elem;
        next = nullptr;
        prev = nullptr;
    }
};

namespace doublyList
{
    // 1.	Инициализация списка (создание первого элемента списка).
    template <class T>
    void Init(Node_d<T> *&head, Node_d<T> *&tail)
    {
        head = tail = nullptr;
    }

    // 2.	Проверка на пустоту.
    template <class T>
    bool IsEmpty(Node_d<T> *head)
    {
        return head == nullptr;
    }

    // 3.	Добавление элемента в список:
    // 	после заданного элемента (заданный элемент определяется указателем).
    template <class T>
    void AddAfterNode(Node_d<T> *pNode, T elem, Node_d<T> *&tail)
    {
        Node_d<T> *p = new Node_d<T>(elem);
        p->next = pNode->next;
        pNode->next = p;
        p->prev = pNode;
        if (pNode == tail)
            tail = p;
        else
            p->next->prev = p;
    }

    // 	перед заданным элементом (заданный элемент определяется указателем)
    template <class T>
    void AddBeforeNode(Node_d<T> *pNode, T elem, Node_d<T> *&head)
    {
        Node_d<T> *p = new Node_d<T>(elem);
        p->prev = pNode->prev;
        pNode->prev = p;
        p->next = pNode;
        if (head == pNode)
            head = p;
        else
            p->prev->next = p;
    }

    //     4.	Удаление элемента из списка:
    // 	после заданного элемента (заданный элемент определяется указателем).
    template <class T>
    void DeleteAfterNode(Node_d<T> *pNode, Node_d<T> *&tail)
    {
        Node_d<T> *p = pNode->next;
        if (p != tail)
        {
            pNode->next = p->next;
            p->next->prev = pNode;
        }
        else
        {
            tail = pNode;
        }
        p->next = p->prev = nullptr;
        delete p;
        p = nullptr;
    }

    // 	перед заданным элементом (заданный элемент определяется указателем).
    template <class T>
    void DeleteBeforeNode(Node_d<T> *pNode, Node_d<T> *&head)
    {
        Node_d<T> *p = pNode->prev;
        if (p != head)
        {
            pNode->prev = p->prev;
            p->prev->next = pNode;
        }
        else
        {
            head = pNode;
        }
        p->next = p->prev = nullptr;
        delete p;
        p = nullptr;
    }

    //     5.	Создание списка:
    // 	в прямом порядке;
    template <class T>
    void CreateListInDirect(Node_d<T> *&head, Node_d<T> *&tail)
    {
        int count;
        cout << "List duration?\n";
        cin >> count;
        T elem;
        cout << "Input elements:\n";
        cin >> elem;
        head = new Node_d<T>(elem);
        Node_d<T> *p = head;
        tail = head;
        for (int i = 1; i < count; ++i)
        {
            cin >> elem;
            AddAfterNode(p, elem, tail);
            p = p->next;
        }
    }

    // 	в обратном порядке;
    template <class T>
    void CreateReversedList(Node_d<T> *&head, Node_d<T> *&tail)
    {
        int count;
        cout << "List duration?\n";
        cin >> count;
        T elem;
        cout << "Input elements:\n";
        cin >> elem;
        tail = new Node_d<T>(elem);
        Node_d<T> *p = tail;
        head = tail;
        for (int i = 1; i < count; ++i)
        {
            cin >> elem;
            AddBeforeNode(p, elem, head);
            p = p->prev;
        }
    }

    // 	упорядоченно.
    template <class T>
    void CreateNormalList(Node_d<T> *&head, Node_d<T> *&tail)
    {
        int count;
        cout << "List duration?\n";
        cin >> count;
        T elem;
        cout << "Input elements:\n";
        for (int i = 0; i < count; ++i)
        {
            cin >> elem;
            if (head == nullptr)
            {
                head = new Node_d<T>(elem);
                tail = head;
            }
            else
            {
                if (elem <= head->data)
                    AddBeforeNode(head, elem, head);
                if (elem > head->data)
                    AddAfterNode(Search(head, elem), elem, tail);
            }
        }
    }

    template <class T>
    Node_d<T> *Search(Node_d<T> *head, T elem)
    {
        Node_d<T> *p = head;
        while (p->next && p->next->data <= elem)
        {
            p = p->next;
        }
        return p;
    }

    // 6.	Печать списка в прямом
    template <class T>
    void PrintList(Node_d<T> *head)
    {
        Node_d<T> *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 6.	Печать списка в обратном направлении.
    template <class T>
    void PrintListInReverse(Node_d<T> *tail)
    {
        Node_d<T> *p = tail;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }

    // 7.	Уничтожение списка.
    template <class T>
    void ClearList(Node_d<T> *&head, Node_d<T> *&tail)
    {
        while (tail != head)
        {
            DeleteAfterNode(head, tail);
        }
        Node_d<T> *p = head;
        p->next = p->prev = nullptr;
        delete p;
        p = nullptr;
    }

    template <class T>
    void DeleteCurrentNode(Node_d<T> *&pNode, Node_d<T> *&head, Node_d<T> *&tail)
    {
        Node_d<T> *p = pNode;
        if (p != head)
            p->prev->next = p->next;
        else
            head = p->next;
        if (p != tail)
            p->next->prev = p->prev;
        else
            tail = p->prev;
        p->next = nullptr;
        p->prev = nullptr;
        delete p;
        p = nullptr;
    }

    template <class T>
    void ClearList2(Node_d<T> *&head, Node_d<T> *&tail)
    {
        while (!IsEmpty(head))
        {
            DeleteCurrentNode(head, head, tail);
        }
    }
}

// 6)	Двунаправленные кольцевые списки с заглавным звеном:
namespace doublyListWithMain
{
    // 1.	Инициализация списка (создание первого элемента списка).
    template <class T>
    void Init(Node_d<T> *&head)
    {
        head = new Node_d<T>;
        head->next = head;
        head->prev = head;
    }

    // 2.	Проверка на пустоту.
    template <class T>
    bool IsEmpty(Node_d<T> *head)
    {
        return head->next == head;
    }

    // 3.	Добавление элемента в список:.
    // 	после заданного элемента (заданный элемент определяется указателем).
    template <class T>
    void AddAfterNode(Node_d<T> *pNode, T elem)
    {
        Node_d<T> *p = new Node_d<T>;
        p->data = elem;
        p->next = pNode->next;
        pNode->next = p;
        p->prev = pNode;
        p->next->prev = p;
    }

    // 	перед заданным элементом (заданный элемент определяется указателем)
    template <class T>
    void AddBeforeNode(Node_d<T> *pNode, T elem)
    {
        Node_d<T> *p = new Node_d<T>;
        p->data = elem;
        p->prev = pNode->prev;
        pNode->prev = p;
        p->next = pNode;
        p->prev->next = p;
    }

    //     4.	Удаление элемента из списка:
    // 	после заданного элемента (заданный элемент определяется указателем).
    template <class T>
    void DeleteAfterNode(Node_d<T> *pNode, Node_d<T> *&head)
    {
        Node_d<T> *p = pNode->next;
        pNode->next = p->next;
        p->next->prev = pNode;
        if (head == p)
        {
            head = pNode->next;
        }
        p->next = p->prev = nullptr;
        delete p;
        p = nullptr;
    }

    // 	перед заданным элементом (заданный элемент определяется указателем).
    template <class T>
    void DeleteBeforeNode(Node_d<T> *pNode, Node_d<T> *&head)
    {
        Node_d<T> *p = pNode->prev;
        pNode->prev = p->prev;
        p->prev->next = pNode;
        if (head == p)
        {
            head = pNode;
        }
        p->next = p->prev = nullptr;
        delete p;
        p = nullptr;
    }

    // 	текущего элемента.
    template <class T>
    void DeleteCurrentNode(Node_d<T> *&pNode, Node_d<T> *&head)
    {
        Node_d<T> *p = pNode;
        if (p == head)
            head = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = nullptr;
        p->prev = nullptr;
        delete p;
        p = nullptr;
    }

    //     5.	Создание списка:
    // 	в прямом порядке;
    template <class T>
    void CreateListInDirect(Node_d<T> *&head)
    {
        int count;
        cout << "List duration?\n";
        cin >> count;
        T elem;
        cout << "Input elements:\n";
        Node_d<T> *p = head;
        for (int i = 0; i < count; ++i)
        {
            cin >> elem;
            AddAfterNode(p, elem);
            p = p->next;
        }
    }

    // 	в обратном порядке;
    template <class T>
    void CreateReversedList(Node_d<T> *&head)
    {
        int count;
        cout << "List duration?\n";
        cin >> count;
        T elem;
        cout << "Input elements:\n";
        Node_d<T> *p = head;
        for (int i = 0; i < count; ++i)
        {
            cin >> elem;
            AddBeforeNode(p, elem);
            p = p->prev;
        }
    }

    // 	упорядоченно.
    template <class T>
    void CreateNormalList(Node_d<T> *&head)
    {
        int count;
        cout << "List duration?\n";
        cin >> count;
        T elem;
        cout << "Input elements:\n";
        for (int i = 0; i < count; ++i)
        {
            cin >> elem;
            if (head->next == head)
                AddAfterNode(head, elem);
            else
            {
                if (elem <= head->next->data)
                    AddAfterNode(head, elem);
                if (elem > head->next->data)
                    AddAfterNode(Search(head->next, elem), elem);
            }
        }
    }

    template <class T>
    Node_d<T> *Search(Node_d<T> *head, T elem)
    {
        Node_d<T> *p = head;
        while (p->next && p->next->data <= elem)
        {
            p = p->next;
        }
        return p;
    }

    // 6.	Печать списка в прямом
    template <class T>
    void PrintList(Node_d<T> *head)
    {
        Node_d<T> *p = head->next;
        while (p != head)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 6.	Печать списка в  обратном направлении.
    template <class T>
    void PrintListInReverse(Node_d<T> *head)
    {
        Node_d<T> *p = head->prev;
        while (p != head)
        {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }

    // 7.	Уничтожение списка
    template <class T>
    void ClearList(Node_d<T> *&head)
    {
        while (!IsEmpty(head))
        {
            DeleteCurrentNode(head, head);
        }
    }
}

// 7)	Реализация стека на основе массива:
template <class T>
class Astack
{
public:
    T *astack;
    int size;
    int top;
};

namespace masStack
{
    // 1.	Создание пустого стека (инициализация)
    template <class T>
    void Init(Astack<T> &stack, int num)
    {
        stack.size = num;
        stack.astack = new T[num];
        stack.top = -1;
    }

    // 2.	Уничтожение стека
    template <class T>
    void ClearStack(Astack<T> &stack)
    {
        stack.top = -1;
        delete[] stack.astack;
    }

    // 3.	Проверка стека на пустоту
    template <class T>
    bool IsEmpty(Astack<T> stack)
    {
        return stack.top < 0;
    }

    // 4.	Добавление элемента в стек
    template <class T>
    void Push(Astack<T> &stack, T elem)
    {
        if (stack.top + 1 < stack.size)
        {
            stack.top++;
            stack.astack[stack.top] = elem;
        }
    }

    // 5.	Удаление элемента из стека
    template <class T>
    void Pop(Astack<T> &stack)
    {
        if (!IsEmpty(stack))
            stack.top--;
    }

    // 6.	Извлечение элемента из стека
    template <class T>
    T Peek(Astack<T> stack)
    {
        return stack.astack[stack.top];
    }

    // Вывод стека)
    template <class T>
    void PrintStack(Astack<T> stack)
    {
        if (!IsEmpty(stack))
        {
            for (int i = 0; i <= stack.top; ++i)
            {
                cout << stack.astack[i] << " ";
            }
        }
    }
}

// 8)	Реализация стека на основе списка:
template <class T>
struct Tstack
{
    Node<T> *top;
};

namespace listStack
{
    // 1.	Создание пустого стека (инициализация)
    template <class T>
    void Init(Tstack<T> &stack)
    {
        stack.top = nullptr;
    }

    // 2.	Уничтожение стека
    template <class T>
    void ClearStack(Tstack<T> &stack)
    {
        while (!IsEmpty(stack))
        {
            Pop(stack);
        }
    }

    // 3.	Проверка стека на пустоту
    template <class T>
    bool IsEmpty(Tstack<T> stack)
    {
        return stack.top == nullptr;
    }

    // 4.	Добавление элемента в стек
    template <class T>
    void Push(Tstack<T> &stack, T elem)
    {
        Node<T> *p = new Node<T>;
        p->data = elem;
        p->next = stack.top;
        stack.top = p;
    }

    // 5.	Удаление элемента из стека
    template <class T>
    void Pop(Tstack<T> &stack)
    {
        Node<T> *p = stack.top;
        stack.top = stack.top->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }

    // 6.	Извлечение элемента из стека
    template <class T>
    T Peek(Tstack<T> stack)
    {
        if (!IsEmpty(stack))
            return stack.top->data;
    }

    //  Вывод стека)
    template <class T>
    void PrintStack(Tstack<T> stack)
    {
        Node<T> *p = stack.top;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

    // 9)	Применение стека: проверка баланса скобок.
    template <class T>
    bool IsCorrect(string str)
    {
        Tstack<T> stack;
        Init(stack);
        bool result = true;
        int i = 0;
        while (result && i != str.length())
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                Push(stack, str[i]);
            else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
            {
                if (!(IsEmpty(stack) || (str[i] == ')') ^ (stack.top->data == '(') || (str[i] == '}') ^ (stack.top->data == '{') || (str[i] == ']') ^ (stack.top->data == '[')))
                {
                    Pop(stack);
                }
                else
                    result = false;
            }
            ++i;
        }
        return result && IsEmpty(stack);
    }

    int prec(char c)
    {
        if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    // 10)	Применение стека: преобразование формулы из инфиксной в постфиксную запись
    template <class T>
    string InfixToPostfix(string str)
    {
        Tstack<T> stack;
        Init(stack);
        string result;
        for (int i = 0; i < str.length(); ++i)
        {
            char c = str[i];
            if (c == '(')
                Push(stack, c);
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                while (!IsEmpty(stack) && prec(c) <= prec(stack.top->data) && c != '(')
                {
                    result += stack.top->data;
                    Pop(stack);
                }
                Push(stack, c);
            }
            else if (c == ')')
            {
                while (stack.top->data != '(')
                {
                    result += stack.top->data;
                    Pop(stack);
                }
                Pop(stack);
            }
            else
                result += c;
        }
        while (!IsEmpty(stack))
        {
            result += stack.top->data;
            Pop(stack);
        }
        ClearStack(stack);
        return result;
    }

    // 11)	Применение стека: вычисление значения формулы
    template <class T>
    int CalculatePostfixFormula(string str)
    {
        Tstack<T> stack;
        Init(stack);
        int stRes = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            char c = str[i];
            if (c >= '0' && c <= '9')
            {
                Push(stack, c);
            }
            else
            {
                int result = 0;
                int oper1 = Peek(stack) - '0';
                Pop(stack);
                int oper2 = Peek(stack) - '0';
                Pop(stack);
                switch (c)
                {
                case '+':
                    result = oper1 + oper2;
                    Push(stack, result + '0');
                    break;
                case '-':
                    result = oper2 - oper1;
                    Push(stack, result + '0');
                    break;
                case '*':
                    result = oper1 * oper2;
                    Push(stack, result + '0');
                    break;
                case '/':
                    result = oper2 / oper1;
                    Push(stack, result + '0');
                    break;
                default:
                    break;
                }
            }
        }
        stRes = stack.top->data - '0';
        ClearStack(stack);
        return stRes;
    }

}

// 12)	Реализация очереди с помощью циклического массива:
template <class T>
class AQueue
{
    T *queue;
    int size, head, tail;
};

namespace masQueue
{
    // 1.	Инициализация очереди.
    template <class T>
    void Init(AQueue<T> &q, int size_)
    {
        q.size = size_;
        q.queue = new T[q.size];
        q.head = 0;
        q.tail = -1;
    }

    // 2.	Очистка очереди
    template <class T>
    void ClearQueue(AQueue<T> &q)
    {
        delete[] q.queue;
    }

    // 3. Добавление элемента
    template <class T>
    void addToQueue(AQueue<T> &q, T elem)
    {
        if (IsFull(q) && !IsEmpty(q))
            Resize(q);
        q.tail = (q.tail + 1) % q.size;
        q.queue[q.tail] = elem;
    }

    // 4. Удаление элемента
    template <class T>
    void delToQuue(AQueue<T> &q)
    {
        if (q.head == q.tail) // один элемент в очереди
        {
            q.head = 0;
            q.tail = -1;
        }
        else
            q.head = (q.head + 1) % q.size;
    }
    // получение элемента очереди
    template <class T>
    T Peek(AQueue<T> q)
    {
        return q.queue[q.head];
    }

    // 5. Проверка на пустоту
    template <class T>
    bool IsEmpty(AQueue<T> q)
    {
        return q.tail == -1;
    }

    // проверка на полноту?????
    template <class T>
    bool IsFull(AQueue<T> q)
    {
        return (q.tail + 1) % q.size == q.head;
    }

    // изменение размера
    template <class T>
    void Resize(AQueue<T> &q)
    {
        T *tempArr = new T[q.size * 2];
        int i = 0;
        int j = q.head;
        do
        {
            tempArr[i++] = q.queue[j];
            j = (j + 1) % q.size;
        } while (j != q.head);
        q.head = 0;
        q.tail = q.size - 1;
        q.queue = tempArr;
        q.size = q.size * 2;
    }

    // вывод очереди
    template <class T>
    void PrintQueue(AQueue<T> q)
    {
        cout << q.size << endl;
        for (int i = q.head; i <= q.tail; ++i)
        {
            cout << "i: " << i << " elem: " << q.queue[i] << endl;
        }
        cout << endl;
    }

}

// 13)	Реализация очереди с помощью списка:
template <class T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
};

namespace listQueue
{
    // 1.	Инициализация очереди.
    template <class T>
    void Init(Queue<T> &q)
    {
        q.head = q.tail = nullptr;
    }

    // 2. Очистка очереди
    template <class T>
    void ClearQueue(Queue<T> &q)
    {
        while (!IsEmpty(q))
        {
            delToQueue(q);
        }
    }

    // 3. Добавление элемента
    template <class T>
    void addToQueue(Queue<T> &q, T elem)
    {
        Node<T> *p = new Node<T>;
        p->data = elem;
        p->next = nullptr;
        if (q.head == nullptr && q.tail == nullptr)
        {
            q.head = q.tail = p;
        }
        else
        {
            q.tail->next = p;
            q.tail = p;
        }
    }

    // 4. Удаление элемента
    template <class T>
    void delToQueue(Queue<T> &q)
    {
        Node<T> *p = q.head;
        q.head = q.head->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }

    //   5. Проверка на пустоту
    template <class T>
    bool IsEmpty(Queue<T> q)
    {
        return q.head == nullptr;
    }

    //   6. Получение первого элемента
    template <class T>
    T Peek(Queue<T> q)
    {
        return q.head->data;
    }

    // Вывод
    template <class T>
    void PrintQueue(Queue<T> q)
    {
        Node<T> *p = q.head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

// 14)	Деревья. Основные определения. Применение деревьев.

// 15)	Бинарные деревья:
template <class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

namespace binTree
{
    // 1. Создание пустого бинарного дерева.
    template <class T>
    void Init(TreeNode<T> *&root)
    {
        root = nullptr;
    }

    // 2. Создание бинарного дерева, содержащего один узел, по заданному элементу.
    template <class T>
    void Init(TreeNode<T> *&root, T elem)
    {
        root = new TreeNode<T>;
        root->data = elem;
        root->left = nullptr;
        root->right = nullptr;
    }

    // 3. Создание бинарного дерева по заданному корню и двум бинарным поддеревьям этого корня.
    template <class T>
    void Init(TreeNode<T> *&root, T elem, TreeNode<T> *leftsubtree, TreeNode<T> *rightsubtree)
    {
        Init(root, elem);
        AttachLeftSubtree(root, leftsubtree);
        AttachRightSubtree(root, rightsubtree);
    }

    //     4. Удаление бинарного дерева.
    template <class T>
    void DestroyTree(TreeNode<T> *&root)
    {
        if (root != nullptr)
        {
            DestroyTree(root->left);
            DestroyTree(root->right);
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            root = nullptr;
        }
    }

    // 5. Проверка на пустоту.
    template <class T>
    bool IsEmpty(TreeNode<T> *root)
    {
        return root == nullptr;
    }

    // 6. Определение или изменение данных, записанных в корне бинарного дерева.
    template <class T>
    void SetRootData(TreeNode<T> *&root, T elem)
    {
        if (!IsEmpty(root))
            root->data = elem;
        else
            Init(root, elem);
    }

    // 7. Присоединение к корню бинарного дерева левого или правого дочернего узла.
    template <class T>
    bool AttachLeft(TreeNode<T> *&root, T elem)
    {
        bool canAttach = false;
        if (root->left == nullptr)
        {
            Init(root->left, elem);
            canAttach = true;
        }
        return canAttach;
    }

    template <class T>
    bool AttachRight(TreeNode<T> *&root, T elem)
    {
        bool canAttach = false;
        if (root->right == nullptr)
        {
            Init(root->right, elem);
            canAttach = true;
        }
        return canAttach;
    }

    // 8. Присоединение к корню бинарного дерева левого или правого поддерева.
    template <class T>
    bool AttachLeftSubtree(TreeNode<T> *root, TreeNode<T> *subtree)
    {
        bool canAttach = false;
        if (root->left == nullptr)
        {
            root->left = subtree;
            canAttach = true;
        }
        return canAttach;
    }

    template <class T>
    bool AttachRightSubtree(TreeNode<T> *root, TreeNode<T> *subtree)
    {
        bool canAttach = false;
        if (root->right == nullptr)
        {
            root->right = subtree;
            canAttach = true;
        }
        return canAttach;
    }

    // 9. Отсоединение от корня бинарного дерева левого или правого поддерева.
    template <class T>
    void DetachLeftSubtree(TreeNode<T> *root, TreeNode<T> *&leftsubtree)
    {
        leftsubtree = root->left;
        root->left = nullptr;
    }

    template <class T>
    void DetachRightSubtree(TreeNode<T> *root, TreeNode<T> *&rightsubtree)
    {
        rightsubtree = root->right;
        root->right = nullptr;
    }

    template <class T>
    TreeNode<T> *DetachLeftSubtree(TreeNode<T> *root)
    {
        TreeNode<T> *leftsubtree;
        Init(leftsubtree);
        leftsubtree = root->left;
        root->left = nullptr;
        return leftsubtree;
    }

    template <class T>
    TreeNode<T> *DetachRightSubtree(TreeNode<T> *root)
    {
        TreeNode<T> *rightsubtree;
        Init(rightsubtree);
        rightsubtree = root->right;
        root->right = nullptr;
        return rightsubtree;
    }

    // Скопировать дерево
    template <class T>
    void CopyTree(TreeNode<T> *root, TreeNode<T> *&newroot)
    {
        if (root != nullptr)
        {
            Init(newroot, root->data);
            CopyTree(root->left, newroot->left);
            CopyTree(root->right, newroot->right);
        }
    }

    // 10. Вернуть копию левого или правого поддерева корня бинарного дерева.
    template <class T>
    TreeNode<T> *GetLeftSubtree(TreeNode<T> *root)
    {
        TreeNode<T> *newroot;
        if (root == nullptr)
        {
            Init(newroot);
        }
        else
            CopyTree(root->left, newroot);
        return newroot;
    }

    template <class T>
    TreeNode<T> *GetRightSubtree(TreeNode<T> *root)
    {
        TreeNode<T> *newroot;
        if (root == nullptr)
        {
            Init(newroot);
        }
        else
            CopyTree(root->right, newroot);
        return newroot;
    }

    // 16)	Обход дерева в ширину
    // BFC - обход в ширину, DFC - обход в глубину
    template <class T>
    void BreadthFirstSearh(TreeNode<T> *root)
    {
        Queue<T> q;
        Init(q);
        addToQueue(q, root);
        while (!IsEmpty(q))
        {
            TreeNode<T> *cur = Peek(q);
            cout << cur->data << endl;
            if (cur->left)
                addToQueue(q, cur->left);
            if (cur->right)
                addToQueue(q, cur->right);
            delToQueue(q);
        }
        ClearQueue(q);
    }

    // 17)	Обход узлов бинарного дерева в глубину в прямом, обратном или симметричном порядке.
    // 1. Префиксный, прямой
    template <class T>
    void Preorder(TreeNode<T> *root)
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            Preorder(root->left);
            Preorder(root->right);
        }
    }

    // 2. Постфиксный, обратный
    template <class T>
    void Postorder(TreeNode<T> *root)
    {
        if (root != nullptr)
        {
            Postorder(root->left);
            Postorder(root->right);
            cout << root->data << " ";
        }
    }

    // 3. Инфиксный, симметричный
    template <class T>
    void Inorder(TreeNode<T> *root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
    }

    // 18)	Итеративный обход дерева в глубину
    template <class T>
    void InorderIterative(TreeNode<T> *root)
    {
        Tstack<T> stack;
        Init(stack);
        bool done = false;
        TreeNode<T> *cur = root;
        while (!done)
        {
            if (cur != nullptr)
            {
                Push(stack, cur);
                cur = cur->left;
            }
            else
            {
                if (!IsEmpty(stack))
                {
                    cur = Peek(stack);
                    Pop(stack);
                    cout << cur->data << " ";
                    cur = cur->right;
                }
                else
                    done = true;
            }
        }
        ClearStack(stack);
    }
}

// 19)	Бинарное дерево поиска
namespace binSrchTree
{
    // 1. Создать пустое бинарное дерево поиска.
    template <class T>
    void Init(TreeNode<T> *&root)
    {
        root = nullptr;
    }

    template <class T>
    void Init(TreeNode<T> *&root, T elem)
    {
        root = new TreeNode<T>;
        root->data = elem;
        root->left = nullptr;
        root->right = nullptr;
    }

    // 2. Уничтожить бинарное дерево поиска.
    template <class T>
    void DestroyTree(TreeNode<T> *&root)
    {
        if (root != nullptr)
        {
            DestroyTree(root->left);
            DestroyTree(root->right);
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            root = nullptr;
        }
    }

    //     3. Определить, пусто ли бинарное дерево.
    template <class T>
    bool IsEmpty(TreeNode<T> *root)
    {
        return root == nullptr;
    }

    // 4. Вставить новый элемент в бинарное дерево поиска.
    template <class T>
    void Insert(TreeNode<T> *&root, T elem)
    {
        if (root == nullptr)
        {
            root = new TreeNode<T>;
            root->data = elem;
            root->left = nullptr;
            root->right = nullptr;
        }
        else
        {
            if (root->data > elem)
                Insert(root->left, elem);
            if (root->data < elem)
                Insert(root->right, elem);
        }
    }

    // 5. Удалить элемент из бинарного дерева поиска по заданному ключу.
    template <class T>
    void remove(TreeNode<T> *&root, T elem)
    {
        if (root != nullptr)
        {
            if (root->data == elem)
                deleteNode(root);
            else if (root->data > elem)
                remove(root->left, elem);
            else
                remove(root->right, elem);
        }
    }

    // Удалить элемент
    template <class T>
    void deleteNode(TreeNode<T> *&pNode)
    {
        if (pNode->left == nullptr && pNode->right == nullptr)
        {
            delete pNode;
            pNode = nullptr;
        }
        else if (pNode->left == nullptr || pNode->right == nullptr)
        {
            TreeNode<T> *delNode = pNode;
            if (pNode->left != nullptr)
                pNode = pNode->left;
            if (pNode->right != nullptr)
                pNode = pNode->right;
            delete delNode;
        }
        else
            pNode->data = findSuccessor(pNode->right);
    }

    template <class T>
    T findSuccessor(TreeNode<T> *&p)
    {
        TreeNode<T> *cur = p;
        TreeNode<T> *temp = nullptr;
        while (cur->left != nullptr)
        {
            temp = cur;
            cur = cur->left;
        }
        T elem = cur->data;
        TreeNode<T> *delNode = cur;
        if (temp)
            temp->left = cur->right;
        if (p->left == nullptr)
            p = temp;
        delNode->right = nullptr;
        delNode->left = nullptr;
        delete delNode;
        delNode = nullptr;
        cur = nullptr;
        return elem;
    }

    // 20)	Бинарное дерево поиска. Поиск элемента по ключу. Рекурсивный вариант
    template <class T>
    bool search(TreeNode<T> *root, T elem)
    {
        if (root != nullptr)
        {
            if (root->data == elem)
                return true;
            else if (root->data > elem)
                return search(root->left, elem);
            else
                return search(root->right, elem);
        }
        else
            return false;
    }

    // 21)	Бинарное дерево поиска. Поиск элемента по ключу. Итеративный вариант
    template <class T>
    bool IterativeSearch(TreeNode<T> *root, T elem)
    {
        while (root != nullptr)
        {
            if (elem > root->data)
                root = root->left;
            else if (elem < root->data)
                root = root->left;
            else
                return true;
        }
        return false;
    }

    // 3. Инфиксный, симметричный вывод
    template <class T>
    void Inorder(TreeNode<T> *root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
    }
}

// 22)	Идеально сбалансированное дерево
// 23)	Построение идеально сбалансированного дерева

// 24)	AVL-деревья. Деревья Фибоначчи.
template <class T>
class avlNode
{
public:
    T data;
    int height;
    avlNode<T> *left;
    avlNode<T> *right;
    avlNode(T value)
    {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

namespace avlTree
{
    template <class T>
    int height(avlNode<T> *p)
    {
        return p ? p->height : 0;
    }

    template <class T>
    int balance(avlNode<T> *p)
    {
        return height(p->right) - height(p->left);
    }

    template <class T>
    void fixHeight(avlNode<T> *p)
    {
        int left_h = height(p->left);
        int right_h = height(p->right);
        p->height = ((right_h < left_h) ? left_h : right_h) + 1;
    }

    // 27)	Правый простые повороты
    template <class T>
    avlNode<T> *RR_rotate(avlNode<T> *p)
    {
        avlNode<T> *q = p->left;
        p->left = q->right;
        q->right = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    // 27) Левый простые повороты
    template <class T>
    avlNode<T> *LL_rotate(avlNode<T> *q)
    {
        avlNode<T> *p = q->right;
        q->right = p->left;
        p->left = q;
        fixHeight(p);
        fixHeight(q);
        return p;
    }

    template <class T>
    avlNode<T> *Balance(avlNode<T> *p)
    {
        fixHeight(p);
        if (balance(p) == 2)
        {
            if (balance(p->right) < 0)
                p->right = RR_rotate(p->right);
            return LL_rotate(p);
        }
        if (balance(p) == -2)
        {
            if (balance(p->left) > 0)
                p->left = LL_rotate(p->left);
            return RR_rotate(p);
        }
        return p;
    }

    // 29)	Вставка ключей в AVL-дерево
    template <class T>
    avlNode<T> *insert(avlNode<T> *pNode, T elem)
    {
        if (pNode == nullptr)
        {
            pNode = new avlNode<T>(elem);
            return Balance(pNode);
        }
        if (elem < pNode->data)
            pNode->left = insert(pNode->left, elem);
        if (elem > pNode->data)
            pNode->right = insert(pNode->right, elem);
        return Balance(pNode);
    }

    template <class T>
    avlNode<T> *findMin(avlNode<T> *p)
    {
        return p->left ? findMin(p->left) : p;
    }

    template <class T>
    avlNode<T> *removeMin(avlNode<T> *p)
    {
        if (p->left == nullptr)
            return p->right;
        p->left = removeMin(p->left);
        return Balance(p);
    }

    // 30)	Удаление ключей из AVL-дерева
    template <class T>
    avlNode<T> *remove(avlNode<T> *pNode, T elem)
    {
        if (!pNode)
            return nullptr;
        if (elem < pNode->data)
            pNode->left = remove(pNode->left, elem);
        else if (elem > pNode->data)
            pNode->right = remove(pNode->right, elem);
        else
        {
            avlNode<T> *q = pNode->left;
            avlNode<T> *r = pNode->right;
            delete pNode;
            if (!r)
                return q;
            avlNode<T> *minNode = findMin(r);
            minNode->right = removeMin(r);
            minNode->left = q;
            return Balance(minNode);
        }
        return Balance(pNode);
    }

    // Типо вывод
    template <class T>
    void Inorder(avlNode<T> *root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
    }

    template <class T>
    void DestroyTree(avlNode<T> *&root)
    {
        if (root != nullptr)
        {
            DestroyTree(root->left);
            DestroyTree(root->right);
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            root = nullptr;
        }
    }
}

// 25)	Вставка элемента в сбалансированное дерево. Два случая нарушения баланса
// 26)	Способы хранения информации о сбалансированности дерева
// 28)	Большой поворот
// 31)	Trie-деревья. Структура, применение, основные операции.
// 32)	Различные представления узла trie-дерева.
// 33)	Алгоритм вставки элемента в trie-дерево.
// 34)	Алгоритм удаления элемента из trie-дерева.