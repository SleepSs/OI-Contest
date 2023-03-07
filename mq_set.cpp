int p[(int)1e5 + 10];


(1)朴素并查集：

    int p[N]; //存储每个点的祖宗节点

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);


(2)维护size的并查集：

    int p[N], size[N];
    //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    // 合并a和b所在的两个集合：
    if (find(a) != find(b))
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);

    int get_sz(int x) {return size[find(x)];} // 记得是根的sz


(3)维护到祖宗节点距离的并查集：

// #include <iostream>
// #include <algorithm>
// #include <vector>

// #define LL long long

// using namespace std;

// typedef vector<int> vi;
// typedef pair<int, int> pii;

// const int N = 1e5 + 10;
// int p[N], d[N];

// // 并查集插入法
// // 同余 种类相同
// // 1 底下的吃上面的
// // 2 离根近的吃底下的


// int find(int x)
// {
//     if (p[x] == x) return x;
//     int u = p[x]; // 旧的父节点
//     p[x] = find(p[x]); // 新的父节点为根 （同时这步也更新了旧父节点的距离）
//     d[x] += d[u]; // 更新本节点距离
//     return p[x]; // 返回根节点
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) p[i] = i;
    
//     int res = 0;
//     int x, y, op;
//     while (m--)
//     {
//         cin >> op >> x >> y;
//         if (y > n || x > n) res++;
//         else
//         {
//             int px = find(x), py = find(y);
//             // 判断x与y同类
//             // 1. x与y在同一颗树时，距离之差不是三的倍数，为假
//             // 2. x与y不在同一颗树下，肯定成立
//             if (op == 1)
//             {
//                 if (px == py && (d[x] - d[y]) % 3) res ++;
//                 else if (px != py) // 只有xy不在一棵树上判断，别写成else
//                 {
//                     // x被连根拔起，而不仅是分支
//                     // 想想为什么
//                     p[px] = py; 
//                     // d[px] + d[x] - d[y] % 3 == 0
//                     d[px] = d[y] - d[x]; 
//                 }
//             }
//             // 判断x吃y
//             // 1. 在同一棵树下，距离差余1可吃(我们认为底下的能吃上面的)
//             // 2. 不在同一颗树下，肯定成立，同时将
//             else
//             {
//                 // C的余符号会根据被除数变化，python不会
//                 // 所以都放在一边算吧
//                 // 式子是 (d[x] - d[y] -1) % 3 != 0 的简写
//                 if (px == py && (d[x] - d[y] - 1) % 3) res++;
//                 else if (px != py)
//                 {
//                     p[px] = py;
//                     d[px] = d[y] - d[x] + 1; 
//                 }
//             }
//         }

//     }
//     cout << res;
    


// }