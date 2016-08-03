#include<cstdio>
#define N 10
using namespace std;
struct F_t
{
    int first, second;//分子/分母
    F_t(){ first = 0; second = 0; }
    F_t(int a, int b){ first = a; second = b; }
};
struct P_t
{
    int left, right, sum;
    P_t(){ left = 0; right = 0; sum = 0; }
};
inline int gcd(int a, int b);
int main()
{
    P_t pin[N][N] = {};
    F_t dp[N][N] = {};

    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
        {
        scanf("%d%d", &pin[i][j].left, &pin[i][j].right);
        pin[i][j].sum = pin[i][j].left + pin[i][j].right;
        }

    F_t l, r;
    int a, b, g;
    dp[2][1] = F_t(pin[1][1].left, pin[1][1].sum);
    dp[2][2] = F_t(pin[1][1].right, pin[1][1].sum);
    for (i = 3; i <= n + 1; i++)
    {
        for (j = 1; j <= i; j++)
        {
            /*
            l:
            到達左上方釘子的機率 = dp[i-1][j-1]
            左上方釘子到達目前位置的機率(往右) = pin[i-1][j-1].right/pin[i-1][j-1].sum
            兩者相乘
            r:
            到達右上方釘子的機率 = dp[i-1][j-1]
            右上方釘子到達目前位置的機率(往左) = pin[i-1][j-1].left/pin[i-1][j-1].sum
            兩者相乘
            dp[i][j]:
            l 和 r 相加
            */
            l = F_t(dp[i - 1][j - 1].first*pin[i - 1][j - 1].right, dp[i - 1][j - 1].second*pin[i - 1][j - 1].sum);
            r = F_t(dp[i - 1][j].first*pin[i - 1][j].left, dp[i - 1][j].second*pin[i - 1][j].sum);
            if (!l.first)
                a = r.first, b = r.second;
            else if (!r.first)
                a = l.first, b = l.second;
            else
            {
                //通分相加
                a = l.first*r.second + r.first*l.second;//分子
                b = l.second*r.second;//分母
            }
            //約分
            g = gcd(a, b);
            if (g > 1)
                a /= g, b /= g;
            dp[i][j] = F_t(a, b);
        }
    }

    for (i = 1; i <= n + 1; i++)
        printf("%d/%d\n", dp[n + 1][i].first, dp[n + 1][i].second);

    return 0;
}
int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        a %= b;
        b = a;
        a = temp;
    }

    return a;
}