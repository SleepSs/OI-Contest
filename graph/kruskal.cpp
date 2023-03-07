#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
int n, m, cnt, res;

const int N = 2 * 1e5 + 10;
int p[N];

struct Edge{
    int a, b, w;
    bool operator < (const Edge& E) const
    {
        return w < E.w;
    }
}Edges[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


void kruskal()
{
    // 数组指针开始与结束
    sort(Edges, Edges + m);
    
    for (int i = 0; i < m; i++)
    {
        int a = Edges[i].a, b = Edges[i].b;
        a = find(a), b = find(b);
        if (a != b)
        {
            res += Edges[i].w;
            p[a] = b;
            cnt ++;
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edges[i].a = a, Edges[i].b = b, Edges[i].w = c;
    }
    
    // 初始化并查集
    for (int i = 0; i < m; i++)
    {
        p[i] = i;
    }
    kruskal();
    
    if (cnt < n - 1) cout << "impossible";
    else cout << res;

}