//disjoint-set array
#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;
#define N 200000

int g[N], amount[N];
inline void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i] = i;
        amount[i] = 1;
    }
}
inline int find(int x)
{
    return g[x];
}
inline int Union(int a, int b, int idx)
{
    if (g[a] == g[b])
        return amount[g[a]];

    int des = g[b], tar = g[a];
    if (amount[g[a]] > amount[g[b]])
    {
        des = g[a];
        tar = g[b];
    }

    for (int i = 0; i <= idx; i++)
        if (g[i] == tar)
            g[i] = des;

    amount[des] += amount[tar];
    amount[tar] = 0;

    return amount[des];
}
int main()
{    
    int Case;
    scanf("%d", &Case);
    char c_str1[21], c_str2[21];
    while (Case--)
    {
        int n, idx = -1;
        unordered_map<string, int> map;
        scanf("%d", &n);
        init(n << 1);
        while (n--)
        {
            int id1 = -1, id2 = -1;
            scanf("%s%s", c_str1, c_str2);
            string str1(c_str1), str2(c_str2);

            if (!map.count(str1))
                id1 = map[str1] = ++idx;
            else
                id1 = map[str1];
            if (!map.count(str2))
                id2 = map[str2] = ++idx;
            else
                id2 = map[str2];

            printf("%d\n", Union(id1, id2, idx));
        }
    }

    return 0;
}