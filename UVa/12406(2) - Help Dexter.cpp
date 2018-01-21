//UVa: 0.010
#include <cstdio>
#include <vector>
typedef long long LL;

struct node
{
    LL n;
    int len;
    node(LL _n, int _len) : n(_n), len(_len) {}
};
LL ans[2][18][18] = {};
std::vector<node> vec;
int main()
{
    //freopen("test.out", "w", stdout);
    //freopen("test.in", "r", stdin);

    vec.push_back(node(2, 1));
    vec.push_back(node(1, 1));
    //dfs
    while (vec.size())
    {
        node back = vec.back();
        for (int i = 1; i <= 17; i++)
        {
            if (back.n % (1 << i) == 0)
            {
                if (ans[0][back.len][i])
                    ans[1][back.len][i] = back.n; //max
                else
                    ans[0][back.len][i] = back.n; //min
            }
            else
                break;
        }
        vec.pop_back();

        if (back.len <= 17)
        {
            vec.push_back(node(back.n * 10 + 2, back.len + 1));
            vec.push_back(node(back.n * 10 + 1, back.len + 1));
        }
    }

    int Case;
    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int len, power;
        scanf("%d%d", &len, &power);

        printf("Case %d:", c);
        if (ans[0][len][power])
        {
            if (ans[1][len][power])
                printf(" %lld %lld\n", ans[0][len][power], ans[1][len][power]);
            else
                printf(" %lld\n", ans[0][len][power]);
        }
        else
            puts(" impossible");
    }

    return 0;
}