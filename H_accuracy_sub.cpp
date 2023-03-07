#include <iostream>
#include <vector>
using namespace std;
// vector有size()，方便倒叙输出

const int N = 1e6 + 10;
bool cmp(vector<int>& A, vector<int>& B)
{
    if (A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size()-1; i>=0;i--) 
    {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i<A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t+10)%10);
        t = t < 0?1:0;
    }
    // 最后t里剩东西，进位

    while (C.back() == 0 && C.size() != 1) C.pop_back();
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    // 先存到string里
    cin >> a >> b;
    // 切记是size-1, >==
    // 记得-'0'
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    if (cmp(A, B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >=0; i--) cout << C[i];
    }
    else
    {
        auto C = sub(B, A);
        cout << '-';
        for (int i = C.size() - 1; i >=0; i--) cout << C[i];
    }
}

