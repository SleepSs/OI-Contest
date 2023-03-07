#include <iostream>

using namespace std;

const int N = 110;

int w[N][N], v[N][N], f[N], n, m, s[N];

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i]; // i组内物品个数
        for (int j = 1; j <= s[i]; j++) cin >> v[i][j] >> w[i][j];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= s[i]; k++)
            {
                if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
            }
        }
    }
    
    cout << f[m];
}