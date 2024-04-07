#include <iostream>
using namespace std;
inline double cubic(double f) {return f*f*f;}
int main()
{
    double d;
    cin >> d;
    // 注意，范围不是-d,d如果d<1，则求出的根可能大于d，所以最好是max{1, d}
    double l = -10000, r = 10000;
    // 范围判断要改
    while (r - l > 10e-8)
    {
        double mid = (l + r) / 2;
        // 这里就不用10e-8了，直接是小于，不然精度可能有影响
        if (cubic(mid) < d) l = mid;
        else r = mid;
    }
    printf("%.6f", l);
    return 0;
}
