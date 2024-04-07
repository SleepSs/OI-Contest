#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e4 + 10;

int m, n;
// w idx -> dis
int h[N], e[N], ne[N], w[N], d[N], idx, cnt[N];
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
    
    for (int i = 1 ; i <= n; i ++)
    {
        heap.push(i);
        st[i] = true;
    }
    
    while(!heap.empty())
    {
        auto p = heap.front();
        heap.pop();
        // 这个和dij是不一样的
        // 这个控制的是在不在heap中
        // 而不是搜没搜
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
                cnt[son_id] = cnt[p] + 1;
                if (cnt[son_id] >= n) return true;
                if (!st[son_id])
                {
                    heap.push(son_id);
                    // dij中不会重置state
                    st[son_id] = true;
                }
            }
        }
    }
    
    return false;
    
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
    
    if(spfa()) cout << "Yes";
    else cout << "No";
    
}