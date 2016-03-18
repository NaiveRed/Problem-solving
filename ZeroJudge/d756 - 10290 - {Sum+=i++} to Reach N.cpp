#include<cstdio>
#include<cmath>
#define N 30000001
#define M 2000000
typedef long long LL;

bool sieve[N] = { true, true };
LL prime[M];
int main()
{
    int  count = 0, i, s = sqrt(N);
    //get prime
    for (i = 2; i < s; i++)
    {
        if (!sieve[i])
        {
            for (int k = (N - 1) / i; k >= i; k--)
                if (!sieve[k])
                    sieve[k*i] = true;
        }
    }

    for (i = 2; i < N; i++)
        if (!sieve[i])
            prime[count++] = i;

    //input
    LL n;
    while (scanf("%lld", &n) != EOF)
    {
        if (!n)
            puts("1");
        else
        {
            //判斷是否可從 0 開始加
            bool haveZero = false;
            LL Sqrt = (LL)sqrt(n << 1);
            if (Sqrt*(Sqrt + 1) == n << 1)
                haveZero = true;

            while (!(n & 1))
                n >>= 1;
            
            //因數分解
            int sum = 1, idx = 1;//從 3 開始
            while (n != 1 && n >= prime[idx] * prime[idx] && idx < count)
            {
                int temp = 1;
                while (!(n%prime[idx]))
                {
                    temp++;
                    n /= prime[idx];
                }
                sum *= temp;
                idx++;
            }
            
            //如果還有剩下沒除完的數，就是質數
            if (n != 1)
                sum <<= 1;

            printf("%d\n", sum + (haveZero ? 1 : 0));
        }
    }

    return 0;
}
