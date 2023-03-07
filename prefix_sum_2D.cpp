#include <iostream>

using namespace std;
#define LL long long
const int N = 1010;
// a和S都是二维数组
int a[N][N];
int S[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
        }
    }
    while (q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1] << endl;
    }
}

// #include <iostream>

// using namespace std;
// #define LL long long
// // 用x,y的max即可，不需要用N
// const int N = 5010;
// // a和S都是二维数组
// int S[N][N];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n, m, q, r, T;
//     cin >> T >> r;
//     // 防止out of bound
//     r = min(r, 5001);
//     // 减少计算量
//     n = r, m = r;
//     for (int i =0; i < T; i++)
//     {
//         int x, y;
//         cin >> x >> y >> q;
//         // 要先自增再录入 用+= 
//         S[++x][++y] += q;
//         m = max(m, y), n = max(n, x);
//     }
//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= m; j++){
//             S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + S[i][j];
//         }
//     }
//     int res = 0;
//     for (int i = r; i <= n; i++){
//         for (int j = r; j <= m; j++){
//             // 一个R-1 * R-1 范围内的所有价值（不带边界）
//             res = max(res, S[i][j] - S[i-r][j] - S[i][j-r] + S[i-r][j-r]);
//         }
//     }
//     cout << res;
// }