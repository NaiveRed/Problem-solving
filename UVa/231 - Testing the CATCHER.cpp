#include<cstdio>
#include<algorithm>
#define N 1000

int LIS(int *seq, int size);
int main()
{
    int missile[N], n, Case = 1;

    while (scanf("%d", &missile[0]) && missile[0] != -1)
    {
        n = 1;
        while (scanf("%d", &missile[n]) && missile[n] != -1)
            n++;

        if (Case > 1)
            putchar('\n');
        printf("Test #%d:\n", Case++);
        printf("  maximum possible interceptions: %d\n", LIS(missile, n));
    }

    return 0;
}
int LIS(int *seq, int size)
{
    int length[N], i;
    std::fill(length, length + size, 1);

    //LIS
    for (i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
            if (seq[j] <= seq[i])
                if (length[i] + 1>length[j])
                    length[j] = length[i] + 1;
    }

    //最長的LIS長度
    int max = 0;
    for (i = 0; i < size; i++)
        if (max < length[i])
            max = length[i];

    return max;
}