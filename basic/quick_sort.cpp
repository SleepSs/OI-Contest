void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        // do的这一下保证了即使数据完全相同也能让指针前进一步
        // 不要改成while
        // 如果要从大到小排 就把下两行符号换一下
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    // 这行注意
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
