#include<cstdio>
#define N 1000 

int getNum(char *str);
int LIS(int *seq, int size, int *lis);//O(n^2)
int main()
{
    int n, i, missle[N], lis[N];
    char str[10];
    bool first = true;

    scanf("%d", &n);
    getchar();
    getchar();

    while (n--)
    {
        if (first)
            first = false;
        else
            putchar('\n');
        i = 0;
        while (gets(str) && str[0])
            missle[i++] = getNum(str);

        int len = LIS(missle, i, lis);
        printf("Max hits: %d\n", len);
        for (i = 0; i < len; i++)
            printf("%d\n", lis[i]);
    }

    return 0;
}
int getNum(char *str)
{
    char c;
    int num = 0;

    for (int i = 0; str[i]; i++)
        num = num * 10 + str[i] - '0';

    return num;
}
int LIS(int *seq, int size, int *lis)
{
    int length[N], i, prev[N] = {};

    for (i = 0; i < size; i++)
        length[i] = 1;

    for (i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (seq[j]>seq[i])
                if (length[i] + 1 > length[j])
                {
        length[j] = length[i] + 1;
        prev[j] = i;
                }

    //最長的LIS長度
    int max = 0,last;
    for (i = 0; i < size; i++)
        if (max < length[i])
        {
        max = length[i];
        last = i;
        }

    //求出LIS
    for (i = max - 1; i >= 0; i--)
    {
        lis[i] = seq[last];
        last = prev[last];
    }

    return max;
}

