#include <iostream>
#include <vector>
using namespace std;
// vector有size()，方便倒叙输出

const int N = 1e6 + 10;

vector<int> add(vector<int>& A, vector<int>& B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i<A.size() || i<B.size(); i++)
    {
        if (i < A.size()) t+= A[i];
        if (i < B.size()) t+= B[i];
        C.push_back(t % 10);
        // 是否进位的信息都保存在t里了
        t /= 10;
    }
    // 最后t里剩东西，进位
    if (t) C.push_back(1);
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
    vector<int>C = add(A, B);
    for (int i = C.size() - 1; i >=0; i--) cout << C[i];
}
