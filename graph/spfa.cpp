#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int N = 1.5 * 1e5 + 10;

int m, n;
// w idx -> dis
int h[N], e[N], ne[N], w[N], d[N], idx;
bool st[N];



void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa()
{
    
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    queue<int> heap;
    
    // 按pair第一个元素排序，所以距离在前，点名在后
    heap.push(1);
    
    while(!heap.empty())
    {
        auto p = heap.front();
        heap.pop();
        st[p] = false;
        

        
        // 遍历所有通路
        for (int i = h[p]; i != -1; i = ne[i])
        {
            // 记住i只是idx 没有任何用处
            int son_id = e[i];
            
            //  注意这里是w[i]
            if (d[son_id] > d[p] + w[i])
            {
                d[son_id] = d[p] + w[i];
                if (!st[son_id])
                {
                heap.push(son_id);
                st[son_id] = true;
                    
                }
            }
        }
    }
    
    if (d[n] > 0x3f3f3f3f / 2) return -0x3f3f3f3f;
    return d[n];
    
}




int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        // 有重边也不要紧，堆会pop最小的
        add(a, b, c);
    }
    
    int ans = spfa();
    if (ans == -0x3f3f3f3f) cout << "impossible";
    else cout << ans;
    
}