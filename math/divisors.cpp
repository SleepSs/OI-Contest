#include <set>
#include <iostream>

using namespace std;

// 用set避免排序与平方数重复录入的麻烦
set<int> get_divisors(int n)
{
    set<int> s;
    for (int i = 1; i <= n / i; i ++)
    {
        if (n % i == 0)
        {
            s.insert(i); s.insert(n / i);
        }
    }
    return s;
}


int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int x;
        cin >> x;
        // cout << x;
        auto s = get_divisors(x);
        for (int i : s)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}