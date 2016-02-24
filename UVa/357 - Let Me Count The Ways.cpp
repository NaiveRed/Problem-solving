#include<cstdio>
#define N 30001

int main()
{
    int price[5] = { 1, 5, 10, 25, 50 };
    long long cents[N] = { 1 };

    for (int i = 0; i < 5; i++)
        for (int j = price[i]; j < N; j++)
            cents[j] += cents[j - price[i]];

    int n;
    while (scanf("%d", &n) != EOF)
        if (cents[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", cents[n], n);

    return 0;
}