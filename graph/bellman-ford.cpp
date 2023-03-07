#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
int n, m, k;
const int N = 1e4 + 10;

struct{
    int a, b, c;
}edges[N];


int d[N], bk[N];

int bf()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(bk, d, sizeof d);
        for (int j = 0; j < m; j++)
        {
            d[edges[j].b] = min(d[edges[j].b], bk[edges[j].a] + edges[j].c);
        }
    }
    
    if (d[n] >  0x3f3f3f3f / 2) return -0x3f3f3f3f;
    return d[n];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edges[i].a = a, edges[i].b = b, edges[i].c = c; 
    }
    int ans = bf();
    if (ans == -0x3f3f3f3f) cout << "impossible";
    else cout << ans;

}