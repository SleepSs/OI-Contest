#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int e[N], l[N], r[N], idx;

void init()
{
    // 0是左端点，1是右端点，避免混淆所以idx从2开始
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 某一点的右边插入，如果要左插入，则转换成前一点l[k]的右插入
void insert(int k, int x)
{
    l[idx] = k, r[idx] = r[k];
    // 这俩顺序不能反
    l[r[k]] = idx, r[k] = idx;
    e[idx] = x, idx ++;
}

// 不用为头节点操作做处理
void remove(int k)
{
    // 通用表达式
    r[l[k]] = r[k], l[r[k]] = l[k];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    
    init();
    while (n--)
    {
        string OP;
        int k, x;
        cin >> OP;
        if (OP == "L") 
        {
            cin >> x;
            insert(0, x);
        }
        else if (OP == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if (OP == "D")
        {
            cin >> k;
            remove(k+1);
        }
        else if (OP == "IL")
        {
            cin >> k >> x;
            insert(l[k+1], x);
        }
        else if (OP == "IR")
        {
            cin >> k >> x;
            insert(k+1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
}