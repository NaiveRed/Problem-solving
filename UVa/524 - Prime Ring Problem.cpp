#include<cstdio>
#define N 17

bool notPrime[32] = { true, true };
void backtracking(int n, int count);
int main()
{
    int i, j;
    for (i = 2; i < 32; i++)
        if (!notPrime[i])
            for (j = i + i; j < 32; j += i)
                notPrime[j] = true;

    int n,Case=0;
 
    while (scanf("%d", &n) != EOF)
    {
        if (Case)
            putchar('\n');
        printf("Case %d:\n", ++Case);

        backtracking(n, 0);
    }

    return 0;
}
void backtracking(int n, int count)
{
    static bool isVisit[N];
    static int sol[N];
    int i;

    if (!count)//init
    {
        for (i = 0; i <= n; i++)
            sol[i] = isVisit[i] = 0;
        sol[1] = 1;
        isVisit[1] = true;
        count++;
    }
    else if (count == n)
    {
        if (!notPrime[1 + sol[count]])//確認頭+尾是質數
        {
            putchar('1');
            for (i = 2; i <= n; i++)
                printf(" %d", sol[i]);
            putchar('\n');
        }

        return;
    }

    for (i = 2; i <= n; i++)
    {
        if (!isVisit[i] && !notPrime[i + sol[count]])
        {
            isVisit[i] = true;
            sol[count + 1] = i;
            backtracking(n, count + 1);
            isVisit[i] = false;
        }
    }

}