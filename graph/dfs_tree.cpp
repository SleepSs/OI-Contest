#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
int n, m;
/*
    变量的意义：
    h[i] node i -> idx (default -1)
    e[idx] idx -> node i
    ne[idx] idx -> next idx 
    ans 最终答案 全局变量
    res 起始为0 删掉u后，最大的节点数，（要么是某个孩子的和，要么是n-总孩子的和）要跟ans进行比较，取小的为答案
    sum u及它的孩子的总数 每次开始bfs计数为1
    
    遍历思路：
    从任何一点出发 遍历其能联通的所有点 就能遍历到所有点
    如何判断谁是它儿子/父亲 先被遍历的是儿子，后是父亲（此时st[node] = true） 
    在这道题中 父子关系并不重要
*/

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx, ans = N;
bool st[N];


int dfs(int u)
{
    /*
    node_num u
    */
    st[u] = true; // 进入bfs前，我们已经确定过u没被搜索过
    int sum = 1;
    int res = 0;
    
    for (int i = h[u]; i != -1; i = ne[i]) // 都是idx再乱传
    {
        int son = e[i];
        if (!st[son])
        {
            int ss = dfs(son);
            res = max(res, ss); // 关键
            sum += ss;
        }
    }
    
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++; // start from 0
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(h, -1, sizeof h); // 初始化
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a,b), add(b,a);
    }
    dfs(1);
    cout << ans;
}