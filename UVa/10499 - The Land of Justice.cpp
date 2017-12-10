#include <cstdio>

int main()
{
    long long n;
    while (scanf("%lld", &n) && n >= 0)    
        printf("%lld%%\n", n != 1 ? 25 * n : 0);
    return 0;
}