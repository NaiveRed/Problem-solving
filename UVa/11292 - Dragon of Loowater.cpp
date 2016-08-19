#include<cstdio>
#include<algorithm>

int main()
{
    int n, m, k[20000], d[20000];
    while (scanf("%d%d", &n, &m) && n)
    {
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &d[i]);
        for (i = 0; i < m; i++)
            scanf("%d", &k[i]);

        std::sort(d, d + n);
        std::sort(k, k + m);

        int sum = 0, j = 0;
        for (i = 0; i < n; i++)
        {
            while (j < m&&k[j] < d[i])
                j++;

            if (j == m)
                break;

            sum += k[j++];
        }

        if (i == n)
            printf("%d\n", sum);
        else
            puts("Loowater is doomed!");
    }

    return 0;
}