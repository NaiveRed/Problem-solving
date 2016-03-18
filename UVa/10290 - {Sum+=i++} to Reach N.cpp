#include<cstdio>
#include<cmath>
#define N 1000000//1000000
#define M 400000
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
            for (int j = i * i; j < N; j += i)
                sieve[j] = true;
    }

    for (i = 2; i < N; i++)
        if (!sieve[i])
            prime[count++] = i;

    LL n;
    while (scanf("%lld", &n) != EOF)
    {
        if (!n)
            puts("1");
        else
        {
            while (!(n % 2))
                n >>= 1;
            //�]�Ƥ���
            int sum = 1, idx = 1;//�q 3 �}�l
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
            //�p�G�٦��ѤU�S�������ơA�N�O���
            if (n != 1)
                sum <<= 1;

            printf("%d\n", sum);
        }
    }

    return 0;
}
