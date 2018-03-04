#include <cstdio>
#include <cmath>
#define N 18409545
#define M 1175795
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    static bool sieve[N] = {true, true}; //18409541 最後一對
    static int prime[M] = {};            //只需要到 M 個質數，就可取得 100000 對 twin primes

    //一邊輸入質數表，一邊刪掉每個數的質數倍，如此每個合數就只讀取一次!
    int count = 0;
    for (int i = 2; i < N; i++)
    {
        if (!sieve[i])
            prime[count++] = i;

        for (int j = 0; prime[j] * i < N; j++)
        {
            sieve[prime[j] * i] = true;
            if (!(i % prime[j]))
                //如果在 i 等於質數，則會在目前質數表最後一個停下;
                //如果 i 為合數，那後面的prime[j]*i可以在之後拜訪到  ex.2(prime)*4 下一個是 3(prime)*4 = 12 ，在 2(prime)*6 的時候會拜訪到
                break;
        }
    }

    //twin primes
    int idx[100000]={};
    for (int i = 0, j = 0; i < count; i++)
    {
        if (prime[i] + 2 == prime[i + 1])
            idx[j++] = i;
    }

    int s;
    while (scanf("%d", &s) != EOF)
        printf("(%d, %d)\n", prime[idx[s - 1]], prime[idx[s - 1]] + 2);

    return 0;
}