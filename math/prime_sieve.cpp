void get_primes(int n)
{
    for (int i = 2; i <=n; i++)
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++){ st[primes[j] * i] = true;
        if (i % primes[j] == 0) break; // primes[j]是i的最小质因子
} 
}

// void get_primes(int n)
// {
//     for (int i = 2; i <=n; i++)
//         if (!st[i]) primes[cnt ++] = i;
//         for (int j = 2 * i; j <= n; j += i) st[j] = true;
  

// }
