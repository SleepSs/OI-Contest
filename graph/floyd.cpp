#include <iostream>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int M[N][N];

int m, n, k;

void floyd()
{
    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (M[i][t] == INF) continue; // 剪枝
            for (int j = 1; j <= n; j++)
            {
                M[i][j] = min(M[i][j], M[i][t] + M[t][j]);
            }
        }
    }
}



int main()
{
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            if (i == j) M[i][j] = 0;
            else M[i][j] = INF;
        }
        

    while (m--)
    {
        int a, b, c; // 写里面不费性能
        cin >> a >> b >> c;
        M[a][b] = min(M[a][b], c);
    }
    
    floyd();
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        M[a][b] < INF/2?cout << M[a][b]:cout << "impossible";
        cout << endl;
    }
}