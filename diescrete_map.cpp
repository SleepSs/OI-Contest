#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define LL long long
typedef pair<int, int> pii; 
// 10万插入坐标 + 10万(查询对) * 2
const int N = 1e5 * 3 + 10;
// 映射表
vector<int> cord;
// 查询对
vector<pii> query, insert;
// 底层数组
int a[N];

// 获取某点映射后坐标
int find(int x)
{
    int l = 0, r = cord.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (cord[mid] >= x) r = mid;
        else l = mid + 1;
    }
    // 区间和从1开始，所以这里加1
    return r + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // 读取插入数组
    for (int i = 0; i < n; i++)
    {
        pii p;
        cin >> p.first >> p.second;
        insert.push_back(p);
        // 把坐标推入cord
        cord.push_back(p.first);
    }
    // 读取查询数组
    for (int i = 0; i < m; i++)
    {
        pii p;
        cin >> p.first >> p.second;
        query.push_back(p);
        cord.push_back(p.first);
        cord.push_back(p.second);
    }
    
    // 离散化,即先排序再去重
    sort(cord.begin(), cord.end());
    cord.erase(unique(cord.begin(), cord.end()), cord.end());
    
    // 插入
    for (auto item: insert)
    {
        int mapped = find(item.first);
        a[mapped] += item.second;
    }

    
    // 前缀和
    for (int i = 1; i <= cord.size();i ++) a[i] += a[i-1];
    
    // 查询
    for (auto item: query)
    {
        int m_x = find(item.first);
        int m_y = find(item.second);
        cout << a[m_y] - a[m_x-1] << endl; 
    }

}