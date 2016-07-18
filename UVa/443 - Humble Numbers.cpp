//與 UVa - 136 的概念相同
#include<cstdio>

int main()
{
    int ans[5843] = { 0, 1 };
    int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
    for (int i = 1; i < 5842; i++)
    {
        while (ans[p2] * 2 <= ans[i])p2++;
        while (ans[p3] * 3 <= ans[i])p3++;
        while (ans[p5] * 5 <= ans[i])p5++;
        while (ans[p7] * 7 <= ans[i])p7++;
        int min = ans[p2] * 2;
        if (min > ans[p3] * 3)min = ans[p3] * 3;
        if (min > ans[p5] * 5)min = ans[p5] * 5;
        if (min > ans[p7] * 7)min = ans[p7] * 7;

        ans[i + 1] = min;
    }

    char str[4][3] = { "th", "st", "nd", "rd"};
    int n;
    while (scanf("%d", &n) && n)
    {
        int ten = n % 10, hundred = n % 100, m = 0;
        if (hundred != 11 && hundred != 12 && hundred != 13)//eleven,twelve,thirteen
            m = ten;
        printf("The %d%s humble number is %d.\n", n, str[m < 4 ? m : 0], ans[n]);
    }

    return 0;
}