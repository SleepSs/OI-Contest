#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

vector<pii> segs;

void merge(vector<pii> &segs)
{
    vector<pii> res;
    // 别忘了先sort...
    
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg: segs)
    {
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first;
        }
        // 无论st变不变， ed都得判断 所以放if外边
        ed = max(ed, seg.second);
    }
    // 如果有可能有阴间的n=0的情况
    if(st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pii p;
        cin >> p.first >> p.second;
        segs.push_back(p);
    }

    merge(segs);

    cout << segs.size();
    
}