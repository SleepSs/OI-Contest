#include <iostream>

using namespace std;
#define LL long long 
int n;

int Euler(int x)
{
    LL res = x;
    for (int i = 2; i <= x / i; i ++)
    {
        if (x % i == 0)
        {
            res = res / i * (i-1); // 等于*(1 - 1/i) 防止overflow
            while (x % i == 0) x /= i;
        }
    }
    
    if (x > 1) res = res / x * (x - 1);
    return res;
}


int main()
{
    cin >> n;
    while (n --)
    {
        int x;
        cin >> x;
        cout << Euler(x) << endl;
    }
}