#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10, M = 2*N;
int d[N];
int h[N], e[M], ne[M], idx;
queue<int> q; 
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


int bfs()
{

    // 防止弱智情况
    if (n == 1) return 0;
    // 从1号点开始走
    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        int dis = d[node];
        for (int i = h[node]; i != -1; i = ne[i])
        {
            int son = e[i];
            if (son == n) return dis + 1;
            if (d[son] == -1)
            {
                d[son] = dis + 1;
                q.push(son);
            }
        }
    }
    
    return -1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(h, -1, sizeof h);


    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    memset(d, -1, sizeof d);
    cout << bfs() << endl;
}