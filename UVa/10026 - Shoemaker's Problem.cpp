#include<cstdio>
#include<algorithm>

struct Shoe
{
    int id, d, p;
    float cp;
}shoe[1001];

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &shoe[i].d, &shoe[i].p);
            shoe[i].cp = (float)shoe[i].p / shoe[i].d;
            shoe[i].id = i;
        }
        std::sort(shoe + 1, shoe + n + 1,
            [](const Shoe& a, const Shoe& b)->bool
        {
            if (a.cp == b.cp)
                return a.id < b.id;
            else return a.cp > b.cp;
        });

        for (int i = 1; i < n; i++)
            printf("%d ", shoe[i].id);
        printf("%d\n", shoe[n].id);
        if (Case)
            putchar('\n');
    }

    return 0;
}