#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
int n, m;

const int N = 1e3 + 10;
int f[N][N];
char a[N], b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> a + 1 >> b + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            if (a[i] == b[j]) f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j]);
        }

    cout << f[n][m];
}