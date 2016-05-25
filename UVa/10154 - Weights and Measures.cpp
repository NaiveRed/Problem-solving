#include<cstdio>
#include<algorithm>
#define N 5610
#define INF 1e9
using namespace std;
struct Turtle
{
    int w, p;
}turtle[N];

int main()
{
    int count = 1, w, p;
    while (scanf("%d%d", &w, &p) != EOF)
    {
        turtle[count].w = w;
        turtle[count].p = p - w;
        count++;
    }

    sort(turtle + 1, turtle + count, [](const Turtle& a, const Turtle& b)
    {
        if (a.p == b.p)
            return a.w < b.w;
        return a.p < b.p;
    });

    int dp[N] = { 0 }, i, k;
    for (i = 1; i < count; i++)
        dp[i] = INF;

    //dp[1]為最上層
    for (i = 1; i < count; i++)
        for (k = i; k; k--)//由上往下，因不能重複使用數字
            if (dp[k - 1] < turtle[i].p)
                dp[k] = min(dp[k], dp[k - 1] + turtle[i].w);

    int len = count - 1;
    while (dp[len] == INF)
        len--;
    printf("%d\n", len);

    return 0;
}