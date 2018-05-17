#include <cstdio>
#include <algorithm>
#define N 101

struct exam
{
    int id, s, d, c;
    bool operator<(const exam &a) const
    {
        return d < a.d;
    }
} E[N];
int main()
{
    int n, m;
    int day[N] = {};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &E[i].s, &E[i].d, &E[i].c);
        E[i].id = i + 1;
        day[E[i].d] = m + 1;
    }

    //sort by exam day
    std::sort(E, E + m);

    int finish = 0;
    for (int d = 1; d <= n && finish < m; ++d)
    {
        if (day[d]) //exam
            continue;
        if (E[finish].d < d)
            break;

        for (int i = finish; i < m; ++i)
        {
            if (E[i].s <= d && E[i].c) //already published
            {
                day[d] = E[i].id;

                --E[i].c;

                while (!E[finish].c && finish < m)
                    ++finish;

                break;
            }
        }
    }

    if (finish != m)
        puts("-1");
    else
    {
        for (int i = 1; i < n; ++i)
            printf("%d ", day[i]);
        printf("%d\n", day[n]);
    }

    return 0;
}