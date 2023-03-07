#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int q[N], hh, tt = -1;

void push(int x)
{
    q[++tt] = x;
}

void pop()
{
    hh ++;
}

bool isEmpty()
{
    return hh > tt; // 不要用== 当空的时候不相等
}

int query()
{
    return q[hh];
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    // for (int i = 0; i < n; i++) cin >> a[i];
    
    while (n--)
    {
        string OP;
        cin >> OP;
        int x;
        if (OP == "push")
        {
            cin >> x;
            push(x);
        }
        else if (OP == "pop")
        {
            pop();
        }
        else if (OP == "query")
        {
            cout << query() << endl;
        }
        else if (OP == "empty")
        {
            isEmpty()?cout << "YES":cout << "NO";
            cout << endl;
        }
    }


}