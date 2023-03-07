#include <iostream>
#include <vector>
using namespace std;


const int N = 1e6 + 10;

vector<int> mul(vector<int>& A, int b)
{
    vector<int> C;
    int t = 0;
    // 把两个循环放在一块了，省略了为t开循环的麻烦
    for(int i = 0; i<A.size() || t; i++)
    {
        if (i < A.size()) t+= A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    // 可能乘0
    while(C.back() == 0 && C.size() != 1) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    vector<int>C = mul(A, b);
    for (int i = C.size() - 1; i >=0; i--) cout << C[i];
}
