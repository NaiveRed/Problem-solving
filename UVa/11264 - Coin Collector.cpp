#include <cstdio>

int main()
{   
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, coin, last = 0, sum = 0, count = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &coin);
            if (sum >= coin)
                sum = sum - last + coin;
            else
            {
                sum += coin;
                ++count;
            }

            last = coin;
        }

        printf("%d\n", count);
    }

    return 0;
}