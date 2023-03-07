#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= v[i]; j -- ) // 从大到小枚举可以保证更新时右值没有被计算
        // 恒等式被删除
        // 判断条件被移到for循环内
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}

// naive 版
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 1010;

// int n, m;
// int v[N], w[N];
// int f[N][N];

// int main()
// {
//     cin >> n >> m;

//     for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

//     for (int i = 1; i <= n; i ++ )
//         for (int j = 0; j <= m; j ++ )
//         {
//             f[i][j] = f[i-1][j];
//             if (j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
//         }
//     cout << f[n][m] << endl;

//     return 0;
// }
