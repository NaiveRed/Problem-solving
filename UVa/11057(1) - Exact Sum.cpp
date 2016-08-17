#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n, price[10001];

    while (scanf("%d", &n) != EOF)
    {
        int money;
        for (int i = 0; i < n; i++)
            scanf("%d", &price[i]);
        scanf("%d", &money);

        sort(price, price + n);
        int mid = lower_bound(price, price + n, money / 2) - price;//第一個大於等於 money/2 的
        bool flag = true;

        //從中間向兩側去找，先找到的他們相差一定比較小
        for (; flag&&price[mid] <= money; mid++)//向右
            for (int i = 1; i <= mid; i++)//向左
                if (price[mid] + price[mid - i] == money)
                {
                    printf("Peter should buy books whose prices are %d and %d.\n\n", price[mid - i], price[mid]);
                    flag = false;
                    break;
                }
    }

    return 0;
}