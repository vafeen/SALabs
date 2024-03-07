#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> A = {1, 2, 3};
int n = A.size();
vector<int> dop(n, 1);


void Razm_BP(int k, int r)
{
    if (k == r + 1)
    {
        for (int i = 1; i <= r; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int y = 1; y <= n; y++)
        {
            if (dop[y] > 0)
            {
                A[k] = y;
                dop[y] = dop[y] - 1;
                Razm_BP(k + 1, r);
                dop[y] = dop[y] + 1;
            }
        }
    }
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        dop[i] = 1;
    }
    //     for (int i = 0; i < A.size(); ++i)
    //     {
    // Razm_BP(1, 3);
    //     }
    Razm_BP(1, 3);
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    
}