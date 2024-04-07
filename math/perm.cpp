#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 10;
int path[N];
bool state[N];
int n;
void permutation(int u)
{   
    if (u > n)
    {
        for (int i = 1; i <= n; i ++) cout << path[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!state[i])
        {
            state[i] = true;
            path[u] = i;
            permutation(u + 1);
            state[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int n, m;
    cin >> n;
    permutation(1);
}
