#include <iostream>
#include <algorithm>

using namespace std;

void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )//i <= x / i:防止越界，速度大于 i < sqrt(x)
        if (x % i == 0)//i为底数
        {
            int s = 0;//s为指数
            while (x % i == 0) x /= i, s ++ ; // 如果除之后不再符合 < sqrt(x) 则剩余一定是质数
            cout << i << ' ' << s << endl;//输出
        }
    if (x > 1) cout << x << ' ' << 1 << endl;//如果x还有剩余，单独处理
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        divide(x);
    }

    return 0;
}
