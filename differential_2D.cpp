#include <iostream>

using namespace std;
#define LL long long
const int N = 1010;
// a和S都是二维数组
int S[N][N];
int a[N][N];
void insert(int x1, int y1, int x2, int y2, int c)
{
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> S[i][j];
        }
    }
    // 计算差分矩阵
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            insert(i, j, i, j, S[i][j]);
        }
    }
    while (q--)
    {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    // 重新计算前缀和矩阵
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + a[i][j]; 
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << S[i][j] << ' ';
        }
        cout << endl;
    }
}