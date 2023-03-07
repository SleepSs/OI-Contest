#include <iostream>
#include <vector>
using namespace std;

const int N = 2010;

typedef pair<int, int> pii;

vector<pii> goods;

int w[N],v[N], f[N], s[N], n, m;

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }
    
    
    // 压缩过程
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1;k <= s[i];k <<= 1)
        {
            s[i] -= k;
            goods.push_back({k * v[i], k * w[i]});
        }
        if (s[i]) goods.push_back({s[i] * v[i], s[i] * w[i]});
    }
    
    // 求解 
    // 取出一个bundle 看在体积不大于j情况下是否要加入这个bundle
    // 本质是弱化了货物的异质性，货物是什么不重要，只有属性重要
    // 减少了bp做选择需要的次数
    for (auto good: goods)
    {
        for (int j = m; j >= good.first; j--)
        {
            f[j] = max(f[j], f[j - good.first] + good.second);
        }
    }
    
    
    cout << f[m];
}