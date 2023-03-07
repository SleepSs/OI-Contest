#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
// 第一个元素在1
int stk[N], tt;

void push(int x) {stk[++ tt] = x;}
int pop() {return stk[tt--];}
bool isEmpty() {return tt == 0;}
int query() {return stk[tt];}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (!isEmpty() && query() >= x) pop();
        if (!isEmpty()) cout << query() << ' ';
        else cout << -1 << ' ';
        // 一定要push
        push(x);
    }


}