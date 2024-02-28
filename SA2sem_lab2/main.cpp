#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;


vector<int> Combinations(const std::vector<int> &arr, int mask)
{
    vector<int> result = {};
    for (int i = 0; i < arr.size(); ++i)
    {
        if (mask & (1 << i))
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}

vector<vector<int>> allCombinations(const std::vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> result = {};
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        result.push_back(Combinations(arr, mask));
    }
    return result;
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

// Примеры:
// 100 {2, 5 }
// 100 - 100/2 - 100/5 + 100/(2*5) = 40

// 1000 {2,3,4}
//  1000 - 1000/2 - 1000/3 - 1000/4 + 1000/2*3 + 1000/2*4 + 1000/3*4 - 1000/2*3*4

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int M = 1000;

    vector<int> dels = {2, 3, 4};

    int result = 0;

    vector<vector<int>> comb = allCombinations(dels);
    // printt(comb);
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
        cout << "res_i =" << res_i << '\n';
        result += res_i;
        cout << "result =" << result << '\n';
    }

    cout << result << '\n';
    system("pause");
    return 0;
}