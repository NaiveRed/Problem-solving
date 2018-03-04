/*
ref: http://blog.csdn.net/mobius_strip/article/details/39890425

x = m * k + n, n is x % k
replace floor() and ceil().
if x is divisible by k, then x = p * (m) + q * (m) => (p = k, q = 0)
Otherwise, x = p * (m) + q * (m+1) = (p + q) * (m) + q => (p = k - q, q = n)
*/
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int x, k;
        scanf("%d%d", &x, &k);
        int q = x % k;
        if (q)
            printf("%d %d\n", k - q, q);
        else
            printf("0 %d\n", k);
    }

    return 0;
}