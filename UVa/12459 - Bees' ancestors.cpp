#include <cstdio>
/*
fibonacci number

M:male, F:female

Both male and female need a mom: F(n) = F(n-1) + M(n-1)  
Only female need a dad: M(n) = F(n-1)  
F(n) = F(n-1) + F(n-2)

n generation:
M(n) + F(n) = F(n-1) + F(n)
*/
int main()
{
    long long fib[81] = {1, 1};
    int n;
    for (int i = 2; i < 81; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    while (scanf("%d", &n) && n)    
        printf("%lld\n",fib[n]);
    
    return 0;
}