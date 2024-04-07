// // N ~= 2*n 且 为质数
int null = 0x3f3f3f3f;
// memset(h, 0x3f, N); 按字节set 所以每个字节都是3f 合起来就是Null
// int find(int x)
// {
//     int k = (x % N + N) % N;
    
//     while (h[k] != null && h[k] != x)
//     {
//         k ++;
//         if (k == N) k = 0; // 暗示表从0开始
//     }
    
//     return k;
// }


// const int N = 100003; // 大于N的最小质数
// // 拉链的头 拉链的元素 拉链下一个元素的位置
// int h[N], e[N], ne[N], idx;

// int k = (x % N + N) % N; // 防止x为负数
// e[idx] = x;
// ne[idx] = h[k];
// h[k] = idx ++;
 
