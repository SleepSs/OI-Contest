#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int N = 1e6 + 10;

vector<int> div(vector<int>& A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for(int i = A.size() -1; i>=0; i--)
    {
        r = r*10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    // 可能有前导0
    reverse(C.begin(), C.end());
    while(C.back() == 0 && C.size() != 1) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b, r;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    vector<int>C = div(A, b, r);
    for (int i = C.size() - 1; i >=0; i--) cout << C[i];
    cout << endl << r;
}
