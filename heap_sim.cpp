#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
/* 
    h 堆
    hp 堆的下标对应第几个插入的数
    ph 第几个插入的数对应的堆的下标
    tk 记录插入了几个数
*/
int h[N], hp[N], ph[N], sz, tk;


void swap_hp(int x, int y)
/* 
    x, y 分别是两个heap中的数的下标
*/
{
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}





// 给某个元素下降排序 直到到他应有的位置
void down(int x)
{
    int t = x;
    if (2 * x <= sz && h[t] > h[2 * x]) t = 2 * x;
    // 如果上一步t变了这一步是跟左节点比较哦
    if (2 * x + 1 <= sz && h[t] > h[2*x + 1]) t = 2 * x + 1;
    
    if (x != t)
    {
        swap_hp(x, t);
        down(t);
    }
}

void up(int x)
{
    // 垃圾等号 debug了一天
    int u;
    while ((u = x >> 1) && h[x] < h[u])
    {
        swap_hp(x, u);
        x = u;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k ,x;
    string op;
    cin >> n;

    while (n--)
    {
        cin >> op;
        if (op == "I")
        {
            cin >> x;
            hp[++sz] = ++tk, ph[tk] = sz, h[sz] = x;
            up(sz);
            // down(sz); 插入在末尾 所以不用down
        }
        else if (op == "PM") cout << h[1] << endl;
        else if (op == "DM")
        {
            // h[1] = h[sz];
            swap_hp(1, sz);
            sz--;
            down(1);
        }
        else if (op == "D")
        {
            cin >> k;
            int hidx = ph[k];
            // h[hidx] = h[sz];
            swap_hp(hidx, sz);
            sz--;
            down(hidx);
            up(hidx); // 虽然不知道为什么，但一定要up PS：没准是同级较大的数
        }
        else if (op == "C")
        {
            cin >> k >> x;
            int hidx = ph[k];
            h[hidx] = x;
            down(hidx), up(hidx); // 肯定只有一个能运行
        }
    }
}