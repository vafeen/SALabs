#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100; // Максимальное количество элементов
const int MAX_R = 10;  // Максимальный размер сочетания

vector<int> A(MAX_R);   // Вектор для хранения текущего сочетания
vector<int> dop(MAX_N); // Вспомогательный вектор для подсчета повторений

vector<vector<int>> result = {};
void Sochet_BP(int k, int l, int r, int n)
{
    if (k == r + 1)
    {
        vector<int> res = {};
        for (int i = l; i <= r; ++i)
        {
            cout << A[i] << " ";
            res.push_back(A[i]);
        }
        result.push_back(res);
        cout << endl;
    }
    else
    {
        int t;
        if (k <= l)
            t = l;
        else
            t = A[k - l] + l;

        for (int y = t; y <= n; ++y)
        {
            if (dop[y] > 0)
            {
                A[k] = y;
                dop[y] -= 1;
                Sochet_BP(k + 1, l, r, n);
                dop[y]++;
            }
        }
    }
}

int main()
{
    int n = 3; // Количество элементов
    int r = 2; // Размер сочетания

    for (int i = 1; i <= n; ++i)
    {
        dop[i] = r;
    }

    Sochet_BP(1, 1, r, n);

    system("pause");
    return 0;
}
