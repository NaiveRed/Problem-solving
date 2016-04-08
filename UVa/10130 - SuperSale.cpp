#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 1000
#define MW 31

struct Object
{
    int p, w;
}object[N];

int main()
{
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int n, g, i, w;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d%d", &object[i].p, &object[i].w);
      
        int dp[MW] = {}, ans = 0;
        for (i = 0; i < n; i++)
            for (w = MW - 1; w >= object[i].w; w--)
                dp[w] = MAX(dp[w], dp[w - object[i].w] + object[i].p);
        
        scanf("%d", &g); 
        for (i = 0; i < g; i++)
        {
            scanf("%d", &w);
            ans += dp[w];
        }
        printf("%d\n", ans);
    }

    return 0;
}