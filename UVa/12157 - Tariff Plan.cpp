#include <cstdio>

int main()
{    
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int n, dur[20];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &dur[i]);
        int mile = 0, juice = 0;
        for (int i = 0; i < n; ++i)
        {
            mile += (1 + dur[i] / 30) * 10;
            juice += (1 + dur[i] / 60) * 15;
        }

        if (mile > juice)
            printf("Case %d: Juice %d\n", t, juice);
        else if (mile < juice)
            printf("Case %d: Mile %d\n", t, mile);
        else
            printf("Case %d: Mile Juice %d\n", t, mile);
    }

    return 0;
}