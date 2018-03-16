/*
長度 n 的 =  (n-1 的全部後面都接上 0) + (n-1 以 0 結尾的接上 1)
n-1 以 0 結尾的 = n-2 的數量
*/
#include <cstdio>

int main()
{
    long long fib[51] = {1, 2};
    for (int i = 2; i < 51; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int n;
        scanf("%d", &n);
        printf("Scenario #%d:\n%lld\n\n", t, fib[n]);
    }

    return 0;
}