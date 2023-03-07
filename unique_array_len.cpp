#include <iostream>

using namespace std;
#define LL long long
const int N = 1e5 + 10;
int a[N];
// 不要开S[10, 20 ,30...]都会爆
int S[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    // 这道题的check是设计的最巧妙的部分
    for (int i = 0, j = 0; i < n; i++)
    {   
        S[a[i]] ++;
        // 它不需要加入j < i 因为check条件暗含了这一点
        // 记得这个条件是a[i]而非a[j]
        while (S[a[i]] > 1)
        {
            // 减去时能保证a[j]里至少是1
            S[a[j]] --;
            j ++;
        }
        // max居然是自带的函数
        res = max(res, i - j + 1);
    }
    cout << res;
}
