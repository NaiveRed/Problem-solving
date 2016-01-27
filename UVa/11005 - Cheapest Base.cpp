#include<cstdio>

void findBase(int num, int* price);
int main()
{
    int price[36];
    int Case;
    scanf("%d", &Case);
    getchar();

    for (int k = 1; k <= Case; k++)
    {
        if (k != 1)
            putchar('\n');
        printf("Case %d:\n", k);

        for (int i = 0; i < 36; i++)
            scanf("%d", &price[i]);

        int n;
        char str[11];
        scanf("%d", &n);
        getchar();

        while (n--)
        {
            int num;
            scanf("%d", &num);
            printf("Cheapest base(s) for number %d:", num);
            findBase(num, price);
        }
    }

    return 0;
}
void findBase(int num, int* price)
{
    //find cheapest base¡A2~36 base
    int cost = 0, ans[35] = { 2 }, ans_idx = 0;
    //2
    for (int n = num; n; n /= 2)
        cost += price[n % 2];

    //3~36
    for (int base = 3; base <= 36; base++)
    {
        int temp = 0;
        for (int n = num; n; n /= base)
            temp += price[n%base];

        if (temp < cost)
        {
            cost = temp;
            ans_idx = 0;
            ans[ans_idx] = base;
        }
        else if (temp == cost)
            ans[++ans_idx] = base;
    }

    //output
    for (int i = 0; i <= ans_idx; i++)
        printf(" %d", ans[i]);
    putchar('\n');
}