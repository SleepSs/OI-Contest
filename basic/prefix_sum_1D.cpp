#include <iostream>

using namespace std;
#define LL long long
const int N = 1e6 + 10;
int a[N];
int S[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) S[i] = S[i-1] + a[i];
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << S[r] - S[l-1] << endl;
    }
}
