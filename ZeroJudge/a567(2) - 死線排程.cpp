//O(n^2)
#include<cstdio>
#include<algorithm>
#define N 10001
using namespace std;

struct Item
{
    int dead, p;
}item[N];

int main()
{
    int n, i;
    bool day[N];
    while (scanf("%d", &n) != EOF)
    {
        int max = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &item[i].dead, &item[i].p);
            if (max < item[i].dead)
                max = item[i].dead;
        }
        sort(item, item + n, [](const Item& a, const Item& b)->bool
        {
            return a.p > b.p;
        });

        int sum = 0,j;
        //init
        for (i = 0; i <= n; i++)
            day[i] = false;
        for (i = 0; i < n; i++)
        {
            for (j = item[i].dead; j; j--)
                if (!day[j])
                    break;
            
            if (j)
            {
                sum += item[i].p;
                day[j] = true;
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}