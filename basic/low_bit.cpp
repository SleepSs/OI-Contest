#include <iostream>

using namespace std;
#define LL long long
const int N = 1e5 + 10;
int a[N];
// 返回的是最后一位1及其后面的所有值，这个1前面的部分都会被省略
inline int lowbit(int x) {return x & -x;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {   
        int cnt = 0;
        while(a[i])
        {
            a[i] -= lowbit(a[i]);
            cnt ++;
        }
        cout << cnt << ' ';
    }
}