#include<cstdio>
#include<climits>
#define N 46341//sqrt(INT_MAX)

bool sieve[N];
int prime[5000];
int getPrime()
{
    int count = 0;
    for (int i = 2; i < N; i++)
    {
        if (!sieve[i])
        {
            prime[count++] = i;
            for (int j = i + i; j < N; j += i)
                sieve[j] = true;
        }
    }

    return count;
}
inline int gcd(int a, int b)
{
    while (b)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }

    return a;
}
int main()
{
    int m = getPrime();
    int n;
    while (scanf("%d", &n) && n)
    {
        int ans = 0, temp = n;
        
        if (n == INT_MIN)//-2147483648
        {
            puts("31");
            continue;
        }
        else if (n < 0)
            n *= -1;

        //计だ秆
        for (int i = 0; i < m&&n >= prime[i] * prime[i]; i++)
        {
            int count = 0;
            while (!(n%prime[i]))
            {
                count++;
                n /= prime[i];
            }

            if (count)
                if (!ans)
                    ans = count;
                else
                    ans = gcd(ans, count);
        }

        if (n != 1)//临Τ逞碞琌借计ㄤ计 1
            ans = 1;

        if (temp < 0)//璽计矪瞶
            while (!(ans & 1))
                ans /= 2;

        printf("%d\n", ans);
    }

    return 0;
}