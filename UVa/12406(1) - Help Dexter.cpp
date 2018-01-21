//UVa: 0.050
#include <cstdio>
typedef long long LL;

int divisor;
LL min, max;

void dfs(int &lev, int now, LL ans)
{
    if (lev == now)
    {
        if (!(ans % divisor))
        {
            if (min)
                max = ans;
            else
                min = ans;
        }
    }
    else
    {
        dfs(lev, now + 1, ans * 10 + 1);
        dfs(lev, now + 1, ans * 10 + 2);
    }
}
int main()
{
    int Case;
    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        divisor = 1 << q; //除數
        min = max = 0;

        dfs(p, 0, 0);
        printf("Case %d:", c);
        if (min)
        {
            if (max)
                printf(" %lld %lld\n", min, max);
            else
                printf(" %lld\n", min);
        }
        else
            puts(" impossible");
    }

    return 0;
}