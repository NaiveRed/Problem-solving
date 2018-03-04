#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;
#define N 200000

int g[N], amount[N];
inline void init(int id)
{
    g[id] = id;
    amount[id] = 1;
}
inline int find(int x)
{
    return x == g[x] ? x : (g[x] = find(g[x]));
}
inline int Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return amount[a];

    //小的團體併入大的
    if (amount[a] > amount[b])
    {
        g[b] = a;
        amount[a] += amount[b];
        //amount[b] = 0;
        return amount[a];
    }
    else
    {
        g[a] = b;
        amount[b] += amount[a];
        //amount[a] = 0;
        return amount[b];
    }
}
inline void get_name(char *s)
{
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != ' ' && c != EOF)
        s[i++] = c;
    s[i] = '\0';
}
int main()
{
    int Case;
    scanf("%d ", &Case);
    char c_str1[21], c_str2[21];
    while (Case--)
    {
        int n, idx = -1;
        unordered_map<string, int> map;
        scanf("%d ", &n);

        while (n--)
        {
            int id1 = -1, id2 = -1;
            get_name(c_str1);
            get_name(c_str2);
            string str1(c_str1), str2(c_str2);

            if (!map.count(str1))
            {
                id1 = map[str1] = ++idx;
                init(id1);
            }
            else
                id1 = map[str1];

            if (!map.count(str2))
            {
                id2 = map[str2] = ++idx;
                init(id2);
            }
            else
                id2 = map[str2];

            printf("%d\n", Union(id1, id2));
        }
    }

    return 0;
}