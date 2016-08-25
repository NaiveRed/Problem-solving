//https://en.wikipedia.org/wiki/Pythagorean_triple#The_Platonic_sequence
#include<cstdio>

int main()
{
    long long n;
    scanf("%I64d", &n);

    if (n < 3)
        puts("-1");
    else if (n & 1)
        printf("%I64d %I64d\n", n*n / 2, n*n / 2 + 1);
    else
    {
        n >>= 1;
        printf("%I64d %I64d\n", n*n - 1, n*n + 1);
    }

    return 0;
}