#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 105;
bool maze[N][N];
int walked[N][N];
queue<pii> q; 
int n,m;

int bfs()
{
    memset(walked, -1, sizeof walked);
    // 这两步很重要
    walked[1][1] = 0;
    q.push({1,1});
    // 一种聪明的不用写四行的方法
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        pii p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i ++)
        {
            if (maze[x + dx[i]][y + dy[i]] && walked[x + dx[i]][y + dy[i]] == -1)
            {
                walked[x + dx[i]][y + dy[i]] = walked[x][y] + 1;
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }
    return walked[n][m];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int n, m;
    cin >> n >> m;
    // 防止边界问题从1开始吧
    // false不可走 true可走
    int x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            if (x) maze[i][j] = false;
            else maze[i][j] = true;
        }

    cout << bfs() << endl;
}