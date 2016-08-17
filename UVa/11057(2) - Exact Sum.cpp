#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n, price[10001];

    while (scanf("%d", &n) !=EOF)
    {
        int diff = 1e9, a, b, money;
        for (int i = 0; i < n; i++)
            scanf("%d", &price[i]);
        scanf("%d", &money);

        sort(price, price + n);
        for (int i = 0; i < n - 1 && money >= price[i]; i++)
        {
            int* p = find(price + i, price + n, money - price[i]);//看有沒有另一個數可以讓它們相加等於 money
            if (p == price + n)
                continue;
            else
            {
                if (*p - price[i] < diff)
                {
                    a = price[i];
                    b = *p;
                    diff = b - a;
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }

    return 0;
}