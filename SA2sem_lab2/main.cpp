// #include <windows.h>
// #include <iostream>
// #include <vector>
// using namespace std;

// int prod(vector<int> vec)
// {
//     int result = 1;
//     for (size_t i = 0; i < vec.size(); i++)
//     {
//         result *= vec[i];
//     }
//     return result;
// }

// void print(vector<int> dels)
// {
//     for (size_t i = 0; i < dels.size(); ++i)
//     {
//         cout << dels[i] << ' ';
//     }
// }
// void printt(vector<vector<int>> dels)
// {
//     for (size_t i = 0; i < dels.size(); ++i)
//     {
//         for (size_t j = 0; j < dels[i].size(); ++j)
//         {
//             cout << dels[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

// // Примеры:
// // 100 {2, 5 }
// // 100 - 100/2 - 100/5 + 100/(2*5) = 40

// // 100 {2,3,4}
// // 24

// // 1000 {2,3,4}
// //  1000 - 1000/2 - 1000/3 - 1000/4 + 1000/2*3 + 1000/2*4 + 1000/3*4 - 1000/2*3*4 = 250

// // vector<vector<int>> combinationsWithoutRepetitions(vector<int> nums)
// // {

// // }

// void sochet(int k, int n)
// {
//     int i, j, t;
//     vector<int> a(k + 1);
//     for (i = 1; i <= k; i++)
//         a[i] = i;
//     do
//     {
//         for (i = 1; i <= k; i++)
//             cout << a[i] << " ";
//         cout << endl;
//         i = k;
//         while (a[i] == n - k + i)
//             i--;
//         if (i > 0)
//         {
//             a[i]++;
//             for (j = i + 1; j <= k; j++)
//                 a[j] = a[i] + j - i;
//         }
//     } while (i > 0);
// }


// int FormulaIncludeExclude(vector<vector<int>> comb, int M)
// {
//     int result = 0;
//     for (size_t i = 0; i < comb.size(); ++i)
//     {
//         size_t size = comb[i].size();
//         int res_i;
//         if (size % 2 != 0)
//         {
//             res_i = -M / prod(comb[i]);
//         }
//         else
//         {
//             res_i = M / prod(comb[i]);
//         }
//         // cout << "res_i =" << res_i << '\n';
//         result += res_i;
//         // cout << "result =" << result << '\n';
//     }
//     return result;
// }

// // int main()
// // {
// //     SetConsoleCP(65001);
// //     SetConsoleOutputCP(65001);

// //     int M = 100;

// //     vector<int> dels = {2, 3, 4};

// //     sochet(2, 3);
// //     // vector<vector<int>> comb = allCombinations(dels);
// //     // printt(comb);

// //     system("pause");
// //     return 0;
// // }