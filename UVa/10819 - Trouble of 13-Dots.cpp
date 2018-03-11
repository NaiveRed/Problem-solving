#include <cstdio>
#define N 10000
#define MAX(a, b) ((a) > (b) ? (a) : (b))

inline int get_num()
{
    int n = 0;
    char c;

    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    int money, n;
    int price[100], favour[100] = {}, dp[N + 201] = {};

    while (scanf("%d%d ", &money, &n) != EOF)
    {
        if (money > 1800)
            money += 200;

        //因為能湊到的可以剛好減為 0 : money - price[i,j,...] = 0
        //要剛好用完錢(非題目要求，而是為了處理+200)，除了 dp[0] = 0 外，都初始為 -1e9
        for (int i = 1; i <= money; i++)
            dp[i] = -1e9;
        
        for (int i = 0; i < n; i++)
        {
            //scanf("%d%d", &price[i], &favour[i]);
            price[i] = get_num();
            favour[i] = get_num();
        }

        for (int i = 0; i < n; i++)
            for (int m = money; m >= price[i]; m--) //物品只能挑一次，從大到小做
                dp[m] = MAX(dp[m], dp[m - price[i]] + favour[i]);

        /*
        要注意買未超 2000，卻還是多 200 元的情況
        e.g. 
        money = 1805
        1. 買小於等於 2000，僅可使用 1805 (也就是買的總價格介於 0~1805)
        2. 如果買超過 2000，可使用 1805 + 200 = 2005 (也就是買的總價格介於 2001~2005)
        要找出以上兩種情況中的最大值(favour)

        money = 2001
        1. 0~2000
        2. 2001~2201

        money = 1800
        1. 0~1800
        2. - (1800+200<2000)
        */

        // 1. 買小於等於 2000
        int tmp = money; //原始預算 <= 1800
        if (tmp > 2200)  //原始預算 > 2000，可以直接使用 0~2000
            tmp = 2000;
        else if (tmp > 2000) //原始預算介於 1801~2000
            tmp -= 200;

        int max = -1, ans;
        for (int i = tmp; i >= 0; i--)
        {
            if (dp[i] > max)
            {
                max = dp[i];
                ans = i;
            }
        }

        // 2. 如果買超過 2000，有多 200 可用
        for (int i = money; i > 2000; i--)
        {
            if (dp[i] > max)
            {
                max = dp[i];
                ans = i;
            }
        }

        printf("%d\n", dp[ans]);
    }

    return 0;
}
/*
1900 4
2000 5
2050 4
1950 2
101 1

4
*/