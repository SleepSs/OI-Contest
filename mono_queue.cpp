#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e6 + 10;
int a[N], q[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // 最小值
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {   
        // 先判断是否为空在取元素
        // 关于为什么+1 用k等于1的情况判断 q[hh] < i 是一定的(因为是i+1和i的关系)
        if (hh <= tt && q[hh] < i - k + 1) hh ++;
        // 带等于号 因为现在存的是i 虽然值相同也得pop
        // 另外 这是个双向队列
        while (hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    cout << '\n';
    
    // 最大值
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {   
        if (hh <= tt && q[hh] < i - k + 1) hh ++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
}