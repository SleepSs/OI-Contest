#include <iostream>

using namespace std;
#define LL long long
const int N = 1e5 + 10;
int a[N], b[N];
void insert(int l, int r, int num)
{
    b[l] += num;
    b[r+1] -= num;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 初始化差分数列b 等价于b[i] = a[i] - a[i-1]
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);
    
    while (m--)
    {
        int l, r, num;
        cin >> l >> r >> num;
        insert(l, r, num);
    }
    // 最后用b[i]算一遍操作后的前缀和数列
    for (int i = 1; i <= n; i++) cout << (b[i] += b[i-1]) << ' ';
}