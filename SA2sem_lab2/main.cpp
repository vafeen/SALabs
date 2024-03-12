#include <iostream>
#include <vector>

using namespace std;

vector<int> A = {};   // Вектор для хранения текущего сочетания
vector<int> dop = {}; // Вспомогательный вектор для подсчета повторений

vector<vector<int>> combinations = {};

void Sochet_BP(int k, int r, int n)
{
    if (k == r + 1)
    {
        vector<int> res = {}; // массив для одной комбинации
        for (int i = 1; i <= r; ++i)
        {
            // cout << A[i] << " ";
            res.push_back(A[i]);
        }
        combinations.push_back(res); // добавление комбинации в общий массив комбинаций
        // cout << endl;
    }
    else
    {
        int t;
        if (k <= 1)
            t = 1;
        else
            t = A[k - 1] + 1;

        for (int y = t; y <= n; ++y)
        {
            if (dop[y] > 0)
            {
                A[k] = y;
                dop[y] -= 1;
                Sochet_BP(k + 1, r, n);
                dop[y]++;
            }
        }
    }
}

// функция, которая из пустого массива генерирует двумерный массив комбинаций для 3 типа:
// {{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
// сначала 1/3 - 1,2,3,
// потом  2/3 - 1-2, 2-3, 1-3
// потом 3/3 - 1-2-3
void genericMassivSochet(int n)
{
    // r - размер сочетания
    for (int r = 1; r <= n; r++)
    {
        dop.resize(n);
        A.resize(n);
        for (int i = 1; i <= n; ++i)
        {
            dop[i] = 1;
        }

        Sochet_BP(1, r, n);
    }
}

// вспомогательная функция: продукт
int prod(vector<int> vec, vector<int> vecOfIndexes)
{
    int result = 1;
    for (size_t i = 0; i < vecOfIndexes.size(); i++)
    {
        result *= vec[vecOfIndexes[i] - 1];
    }
    return result;
}

// вспомогательная функция: вывод одномерного вектора
void print(vector<int> dels)
{
    for (size_t i = 0; i < dels.size(); ++i)
    {
        cout << dels[i] << ' ';
    }
}

// вспомогательная функция: вывод двумерного вектора
void printt(vector<vector<int>> dels)
{
    for (size_t i = 0; i < dels.size(); ++i)
    {
        for (size_t j = 0; j < dels[i].size(); ++j)
        {
            cout << dels[i][j] << ' ';
        }
        cout << '\n';
    }
}

// функция подсчета количества делителей по формуле вулючения и исключения
int FormulaIncludeExclude(vector<int> dels, int M)
{
    int result = M;
    for (size_t i = 0; i < combinations.size(); ++i)
    {
        size_t size = combinations[i].size();
        int res_i;
        if (size % 2 != 0)
        {
            res_i = -M / prod(dels, combinations[i]);
        }
        else
        {
            res_i = +M / prod(dels, combinations[i]);
        }
        // cout << "res_i =" << res_i << '\n';
        result += res_i;
        // cout << "combinations =" << combinations << '\n';
    }
    return result;
}

// // Примеры:
// // 100 {2, 5}
// // 100 - 100/2 - 100/5 + 100/(2*5) = 40

// // 100 {2, 3, 4}
// // 24

// // 1000 {2, 3, 4}
// //  1000 - 1000/2 - 1000/3 - 1000/4 + 1000/2*3 + 1000/2*4 + 1000/3*4 - 1000/2*3*4 = 250

int main()
{
    int M = 1000;
    vector<int> dels = {2, 3, 4};
    int n = dels.size(); // Количество элементов

    // генерация тех самых сочетаний  {{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
    genericMassivSochet(n);

    // printt(combinations);

    cout << FormulaIncludeExclude(dels, M) << "\n\n\n";

    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    return 0;
}
