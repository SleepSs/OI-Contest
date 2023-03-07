#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
int n;
const int N = 10;
char board[N][N];

/*
    把对角线映射成一个截距
    即 y = x + dg 和 y = -x + udg
    dg = (y - x) + n [-n, n] ---> [0, 2n]
    udg = y + x  [0, 2n]
*/

bool row[N], col[N], dg[2*N], udg[2*N];

// 按行dfs
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++) puts(board[i]);// 2D to 1D 直接输出一行所有字符
        puts(""); // 换行
        return;
    }
    else
    {
        // 遍历第u行的列
        for (int i = 0; i < n; i++)
        {
            if (!col[i] && !dg[i - u + n] && !udg[i + u])
            {
                col[i] = dg[i - u + n] = udg[i + u] = true;
                board[u][i] = 'Q';
                dfs(u + 1);
                board[u][i] = '.';
                col[i] = dg[i - u + n] = udg[i + u] = false;
            }
        }
        return;
    }
}

void dfs_enum(int x, int y, int qs)
{
    if (x == n) {x = 0; y++;}
    if (y == n)
    {
        if (qs == n)
        {
            for (int i = 0; i < n; i ++) puts(board[i]);// 2D to 1D 直接输出一行所有字符
            puts(""); // 换行
        }
        return;
    }

    dfs_enum(x + 1, y, qs);
    
    if (!row[x] && !col[y] && !dg[n - x + y] && !udg[x + y]){
        row[x] = col[y] = dg[y - x + n] = udg[x + y] = true;
        board[x][y] = 'Q';
        dfs_enum(x + 1, y, qs + 1);
        board[x][y] = '.';
        row[x] = col[y] = dg[y - x + n] = udg[x + y] = false;}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }
    dfs(0);


}