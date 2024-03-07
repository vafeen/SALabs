#include <iostream>
#include <vector>

using namespace std;

vector<int> A = {};   // Вектор для хранения текущего сочетания
vector<int> dop = {}; // Вспомогательный вектор для подсчета повторений

vector<vector<int>> result = {};
void Sochet_BP(int k, int l, int r, int n)
{
    if (k == r + 1)
    {
        vector<int> res = {};
        for (int i = l; i <= r; ++i)
        {
            // cout << A[i] << " ";
            res.push_back(A[i]);
        }
        result.push_back(res);
        // cout << endl;
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

// здесь берем 1/3 - 1,2,3, 2/3 - 1-2,2-3,1-3 , 3/3 - 1-2-3
void genericMassivSochet(int n)
{
    // r - размер сочетания
    for (int r = 1; r <= n; r++)
    {
        dop.resize(n);
        A.resize(n);
        for (int i = 1; i <= n; ++i)
        {
            dop[i] = r;
            A[i] = i;
        }

        Sochet_BP(1, 1, r, n);
    }
}

int prod(vector<int> vec)
{
    int result = 1;
    for (size_t i = 0; i < vec.size(); i++)
    {
        result *= vec[i];
    }
    return result;
}

void print(vector<int> dels)
{
    for (size_t i = 0; i < dels.size(); ++i)
    {
        cout << dels[i] << ' ';
    }
}

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

int FormulaIncludeExclude(vector<vector<int>> comb, int M)
{
    int result = 0;
    for (size_t i = 0; i < comb.size(); ++i)
    {
        size_t size = comb[i].size();
        int res_i;
        if (size % 2 != 0)
        {
            res_i = -M / prod(comb[i]);
        }
        else
        {
            res_i = M / prod(comb[i]);
        }
        // cout << "res_i =" << res_i << '\n';
        result += res_i;
        // cout << "result =" << result << '\n';
    }
    return result;
}

int main()
{
    int n = 4; // Количество элементов
    genericMassivSochet(n);

    // for (size_t i = 0; i < result.size(); ++i)
    // {
    //     for (size_t j = 0; j < result[i].size(); ++j)
    //     {
    //         cout << result[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

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
