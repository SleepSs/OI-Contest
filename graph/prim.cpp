#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
int n, m;

const int N = 500 + 10, INF = 0x3f3f3f3f;
int M[N][N], d[N];
bool st[N];

int prim()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    int res = 0;
    // 第一个点已经确定了，故只用遍历n-1次 (错误
    // 找到距离集合最近的点
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || d[t] > d[j])) t = j;
        }
        
        // 有孤立点 提前剪枝
        if (d[t] == INF) return INF;
        // 被选出的点代表着距离已经被确定了，故可以加入最终结果中
        res += d[t];
        
        st[t] = true;
        
        // 更新所有与t联通的点
        // 这个距离作为与集合的距离
        for (int j = 1; j <= n; j++)
        {
            d[j] = min(d[j], M[t][j]);
        }
        
    }
    
    return res;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    memset(M, 0x3f, sizeof M);
    while (m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 无向图！！！！！！
        M[a][b] = min(M[a][b], c);
        M[b][a] = min(M[b][a], c);
    }
    
    int ans = prim();
    // cout << ans;
    if (ans > INF / 2) cout << "impossible";
    else cout << ans;
    return 0;
}