#include <cstdio>
#include <utility>
#include <algorithm>
#include <unordered_map>
#define N 200001
using namespace std;

struct data
{
    int id, skill;
    bool operator<(const data &a) const
    {
        return skill > a.skill;
    }
} r[N];
inline bool gt(const int &a, const int &b)
{
    return a > b;
}
int bs_upper_bound(int L, int R, int val, bool (*comp)(const int &, const int &))
{
    while (L < R)
    {
        int M = (L + R) >> 1;
        if (!comp(val, r[M].skill))
            L = M + 1;
        else
            R = M;
    }
    return L;
}
int main()
{

    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i)
    {
        r[i].id = i + 1;
        scanf("%d", &r[i].skill);
    }

    //decreasing
    std::sort(r, r + n);

    unordered_map<int, int> pos; //[id] = pos
    for (int i = 0; i < n; ++i)
        pos[r[i].id] = i;

    int mentor[N] = {}, x, y;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d", &x, &y);

        if (r[pos[y]].skill < r[pos[x]].skill) //x can be y's mentor but they are in a quarrel
            --mentor[x];
        else if (r[pos[x]].skill < r[pos[y]].skill) //y can be x's mentor but they are in a quarrel
            --mentor[y];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        //從第一個小於 r[i] 的後面有幾個，也都能讓 r[i] 當 mentor
        mentor[r[i].id] += n - bs_upper_bound(0, n, r[i].skill, gt);
        //mentor[r[i].id] += n - (upper_bound(r, r + n, r[i]) - r);
    }

    for (int i = 1; i < n; ++i)
        printf("%d ", mentor[i]);
    printf("%d\n", mentor[n]);

    return 0;
}