#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int h[N], sz;

// 给某个元素下降排序 直到到他应有的位置
void down(int x)
{
    int t = x;
    if (2 * x <= sz && h[t] > h[2 * x]) t = 2 * x;
    // 如果上一步t变了这一步是跟左节点比较哦
    if (2 * x + 1 <= sz && h[t] > h[2*x + 1]) t = 2 * x + 1;
    
    if (x != t)
    {
        swap(h[x], h[t]);
        down(t);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    sz = n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    
    // 建堆 从倒数第二层开始换
    // 这种写法的最坏复杂度最低
    for (int i = sz / 2; i; i--) down(i);
    
    while (m--)
    {
        cout << h[1] << ' ';
        // 这样看上去很浪费，为什么不直接根h[2]或者h[3]换？因为到底还是要往上移的，所以直接拿上来一个也没什么。
        h[1] = h[sz--];
        down(1);
    }
}