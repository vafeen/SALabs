// #include <windows.h>
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> A = {1, 2, 3};
// vector<int> dop = {1, 1, 1};
// int n = A.size();
// int r = 3;

// void Sochet_BP(int k = 0)
// {
//     if (k == r)
//     {
//         for (int i = 0; i < r; ++i)
//         {
//             cout << A[i] << " ";
//         }
//         cout << endl;
//     }
//     else
//     {
//         for (int y = k ? A[k - 1] + 1 : 0; y < n; ++y)
//         {
//             if (dop[y] > 0)
//             {
//                 A[k] = y;
//                 dop[y]--;
//                 Sochet_BP(k + 1);
//                 dop[y]++;
//             }
//         }
//     }
// }

// int main()
// {
//     dop = {1, 1, 1};
//     Sochet_BP(1);

//     system("pause");
//     system("pause");
//     system("pause");
//     system("pause");
//     system("pause");
//     system("pause");
//     system("pause");
//     system("pause");
// }