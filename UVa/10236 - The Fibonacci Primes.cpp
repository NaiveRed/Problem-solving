#include<cstdio>
#include<cmath>
#define MAX 300000
#define N 250000
#define M 22001

bool sieve[MAX];
int prime[M];
void getPrime();

double fib[N] = { 0, 1 };
void getFibPrime();
int main()
{
    getPrime();
    getFibPrime();
    int n;

    /*
    fibonacci  index 借计fib[index] 穦琌借计碞琌 fibonacci prime
    Τㄇ疭猵硂娩⊿Τ矪瞶 index = 19 (prime[8])fib[index] 玱ぃ借计
    */
    fib[2] = 2;
    fib[3] = 3;
    while (scanf("%d", &n) != EOF)
        printf("%d\n", (int)fib[prime[n]]);
    
    return 0;
}
void getPrime()
{ 
    int s = sqrt(MAX);
    for (int i = 2; i < s; i++)
    {
        if (!sieve[i])
        {
            for (int j = i <<1; j < MAX; j += i)
                sieve[j] = true;
        }
    }

    //prime[] 眖 1 秨﹍よ獽璸衡
    int count = 1;
    for (int i = 2; i < MAX; i++)
    {
        if (!sieve[i])
            prime[count++] = i;
    }
}
void getFibPrime()
{
    //count fibonacci
    bool div = false;
    for (int i = 2; i < N; i++)
    {
        if (div)
        {
            fib[i] = fib[i - 1] + fib[i - 2] / 10;
            div = false;
        }
        else
            fib[i] = fib[i - 1] + fib[i - 2];

        //禬 9 计程癶
        if (fib[i] >= 1e9)
        {
            fib[i] /= 10;
            div = true;
        }
    }
}