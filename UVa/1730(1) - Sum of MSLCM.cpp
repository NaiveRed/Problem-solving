#include <cstdio>

inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    int n;
    while ((n = read()) != 0)
    {
        //SUM(MSLCM(n)) = [SUM(i*floor(n/i))]-1
        //i = 1 ~ n
        long long ans = 0, times, R, L = 1;
        while (L <= n)
        {
            times = n / L;
            R = n / times;
            ans += times * ((L + R) * (R - L + 1) / 2);
            L = R + 1;
        }

        printf("%lld\n", ans - 1);
    }

    return 0;
}