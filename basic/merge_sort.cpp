
void merge_sort(int q[], int l, int r)
{   // basecase 只有一个数时
    if (l >= r) return;
    // mid 变成了位置，而不再是数
    int mid = l + r >> 1;
    // 先递归，再归并
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
  
    int t = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        tmp[t++] = q[i] <= q[j]?q[i++]:q[j++];
    }   
    // 这两个肯定只会有一个能运行
    while (i <= mid) tmp[t++] = q[i++];
    while (j <= r) tmp[t++] = q[j++];
    // 把结果放回原数列
    for (int i = l,j = 0;i <= r; i++, j++) q[i] = tmp[j];
}
