#include <iostream>
// #include <algorithm>
// #include <vector>
#include <cstring>

#define LL long long

using namespace std;

// typedef vector<int> vi;
typedef pair<int, int> pii;
int n, m;

const int N = 500 + 10;
int M[N][N], d[N];
bool st[N];
int dijkstra()
{
    memset(d, 0x3f, sizeof d);
    
    d[1] = 0; 
    for (int i = 1; i < n; i++)
    {
        int t = -1;
        // 确定最短路
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || d[t] > d[j])) t = j;
        }

        // 这个点距离定了
        st[t] = true;
        
        // 遍历联通点
        for (int j = 1; j <= n; j++)
        {
            // 是从t出发哈
            d[j] = min(d[j], d[t] + M[t][j]);
        }
    }
    
    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, z;

    cin >> n >> m;
    
    memset(M, 0x3f, sizeof M);

    while(m --)
    {
        cin >> x >> y >> z;
        M[x][y] = min(M[x][y],z);
    }
    cout << dijkstra();
}


/* 稀疏图dij */

// #include <iostream>
// #include <cstring>
// #include <queue>

// using namespace std;

// typedef pair<int, int> pii;

// const int N = 1.5 * 1e5 + 10;

// int m, n;
// // w idx -> dis
// int h[N], e[N], ne[N], w[N], d[N], idx;
// bool st[N];



// void add(int a, int b, int c)
// {
//     e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
// }

// int dijkstra()
// {
    
//     memset(d, 0x3f, sizeof d);
//     d[1] = 0;
//     priority_queue<pii, vector<pii>, greater<pii>> heap;
    
//     // 按pair第一个元素排序，所以距离在前，点名在后
//     heap.push({0, 1});
    
//     while(!heap.empty())
//     {
//         auto p = heap.top();
//         heap.pop();
        
//         int distance = p.first, id = p.second;
//         if(st[id]) continue;
//         st[id] = true;
        
//         // 遍历所有通路
//         for (int i = h[id]; i != -1; i = ne[i])
//         {
//             // 记住i只是idx 没有任何用处
//             int son_id = e[i];
            
//             //  注意这里是w[i]
//             if (!st[son_id] && d[son_id] > distance + w[i])
//             {
//                 d[son_id] = distance + w[i];
//                 heap.push({d[son_id], son_id});
//             }
//         }
//     }
    
//     if (d[n] == 0x3f3f3f3f) return -1;
//     return d[n];
    
// }




// int main()
// {
//     cin >> n >> m;
//     memset(h, -1, sizeof h);
    
//     int a, b, c;
//     while (m--)
//     {
//         cin >> a >> b >> c;
//         // 有重边也不要紧，堆会pop最小的
//         add(a, b, c);
//     }
    
//     cout << dijkstra();
    
// }
