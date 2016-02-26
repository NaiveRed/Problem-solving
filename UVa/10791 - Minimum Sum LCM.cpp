#include<cstdio>
#define INT_MAX 2147483647
#define N 46340 //sqrt(INT_MAX)

int prime[N];
bool notPrime[N] = { true, true };
int getPrime();
int main()
{
    int Case = 0, n, p;
    p = getPrime();

    while (scanf("%d", &n) != EOF&&n)
    {
        Case++;

        if (n == INT_MAX)//2147483647 is prime
            printf("Case %d: 2147483648\n", Case);//2147483647 + 1
        else if (n == 1)
            printf("Case %d: 2\n", Case);
        else
        {
            int sum = 0, m = n;
          
            for (int i = 0; i < p&&prime[i] <= n; i++)
            {
                //質因數分解
                int count = 1;
                while (!(n%prime[i]))
                {
                    count *= prime[i];
                    n /= prime[i];
                }

                //相加各項
                if (count != 1)
                    sum += count;
            }

            if (sum == m)//本身就是質數，和為 1 + n
                sum++;
            else if (n != 1)//剩下的質數
                sum += n;

            printf("Case %d: %d\n", Case, sum);
        }
    }
    return 0;
}
int getPrime()
{
    int count = 0;
    for (int i = 2; i < N; i++)
        if (!notPrime[i])
        {
        prime[count++] = i;
        for (int j = i << 1; j < N; j += i)
            notPrime[j] = true;
        }

    return count;
}