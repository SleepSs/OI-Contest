#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
// e stands for element
int e[N], ne[N];

int head, idx;

void init()
{
    head = -1;
    idx = 0;
}

void insert_before_head(int x)
{
    // 第一步 把head绑到自己后面
    ne[idx] = head;
    // 第二步 让自己成为head
    head = idx;
    
    e[idx] = x;
    idx ++;
}


// 在第k个插入的数后面插入
void insert(int k, int x)
{   
    // 第一步 把k的后面绑到自己后面
    ne[idx] = ne[k];
    // 第二步 自己绑到k后面
    ne[k] = idx;
    
    e[idx] = x;
    idx ++;
}

// 删除第k个插入的数后面的一个数
void del(int k)
{
    ne[k] = ne[ne[k]];
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
        char OP;
        cin >> OP;
        int x, k;
        switch(OP)
        // 注意， 第k个插入数的下标是k-1
        {
            case 'H': cin >> x; insert_before_head(x);break;
            case 'I': cin >> k >> x; insert(k-1, x);break;
            case 'D': 
            {
                cin >> k; 
                // 需要对删除头节点做特殊处理
                if (!k) head = ne[head];
                else del(k-1);
            }
        }
    }
    // i的更新规则不是++
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
}