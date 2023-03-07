#include <iostream>
#include <algorithm>
#include <vector>

#define ULL unsigned long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10, base = 131;
ULL h[N], p[N];
char s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    // string s; 用max(size(string)) = 65535 乖乖用数组吧
    cin >> n >> m >> s + 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i-1] * base;
        h[i] = h[i-1] * base + s[i];
        
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ULL res1 = h[r1] - h[l1-1] * p[r1-l1+1];
        ULL res2 = h[r2] - h[l2-1] * p[r2-l2+1];
        // cout << res1 <<' ' <<res2 << endl;
        if (h[r1] - h[l1-1] * p[r1-l1+1] == h[r2] - h[l2-1] * p[r2-l2+1]) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    


}