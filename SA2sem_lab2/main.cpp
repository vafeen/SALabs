#include <windows.h>
#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;

void printCombinations(const std::vector<ull> &arr, int mask)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (mask & (1 << i))
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void allCombinations(const std::vector<ull> &arr)
{
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        printCombinations(arr, mask);
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    ull m = 1000;
    vector<ull> dels = {2, 3, 4, 5};

    allCombinations(dels);
    system("pause");
    return 0;
}