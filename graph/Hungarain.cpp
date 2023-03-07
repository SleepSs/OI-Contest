#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
int n1, m, n2;

const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
// 永久性存储n2中的元素配对的n1元素
int match[N];
// TMP 每次搜索时确定是否被占用
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool Hungarian(int x)
{
    // 寻找n1的联通点
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        // j 在这轮没被用过
        if (!st[j])
        {
            // 避免循环查找
            st[j] = true;
            // 给现任找备胎
            if (!match[j] || Hungarian(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        // b不需要与通联，我们一直单向搜索，所以用单向图即可
        add(a, b);
    }
    
    int res = 0;
    // 记住了 用h存储的点都从1开始遍历
    for (int i = 1; i <= n1; i++)
    {
        memset(st, 0, sizeof st);
        
        if (Hungarian(i)) res ++;
        // 没找到也不用break 只是一个单身
    }
    cout << res;
}