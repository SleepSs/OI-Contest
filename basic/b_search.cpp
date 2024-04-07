
// 男左女右，l+1时mid也+1
// 右半区符合， 左半区不符合
int bsearch_1(int l, int r)
{
    // 没有等于
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
// 左半区符合，右半区不符合
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        // 使Mid 向上取整
        int mid = l + r + 1>> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
