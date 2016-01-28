/*
磚塊長為2，寬為1，所以
總長為 n :
1. n-1 的加上直的放
2. n-2 的加上橫的放
也就是費式數列。
*/
#include<cstdio>

int main()
{
    long long fib[51] = {1,1};
    
    //fibonacci
    for (int i = 2; i < 51; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int n;
    while (scanf("%d", &n) && n)
        printf("%lld\n", fib[n]);
    
    return 0;
}
