/*
大數倍數判斷
4: 用最後兩位是否為 4 的倍數
100: 最後兩位 00
400: 大於 9999 皆可用 400*25*n，所以判斷最後 4 位即可
15: 3 和 5 的倍數
3: 每位加起來是 3 的倍數
5: 最後一位 0 或 5
55: 5 和 11 的倍數
11: 奇數位減偶數位是 11 的倍數
*/
#include <cstdio>
#include <cstring>
#define ORD(c) ((c) - '0')
#define N 1000000
int main()
{
    bool first = true;
    char str[N];
    while (fgets(str, N, stdin))
    {
        if (first)
            first = false;
        else
            puts("");

        int len = strlen(str);
        if (str[len - 1] == '\n')
            str[--len] = '\0';

        int n1 = ORD(str[len - 1]) + ORD(str[len - 2]) * 10;              //最後兩位
        int n2 = n1 + ORD(str[len - 3]) * 100 + ORD(str[len - 4]) * 1000; //最後四位
        int sum = 0, odd = 0;                                             //全部位數和奇數位的何
        for (int i = 0; i < len; i++)
        {
            sum += ORD(str[i]);
            if ((i << 1) < len)
                odd += ORD(str[i << 1]);
        }

        bool ordinary = true, leap = false;
        if ((n1 % 4 == 0 && n1 % 100) || n2 % 400 == 0)
        {
            puts("This is leap year.");
            ordinary = false;
            leap = true;
        }

        if ((str[len - 1] == '5' || str[len - 1] == '0') && sum % 3 == 0)
        {
            puts("This is huluculu festival year.");
            ordinary = false;
        }

        if ((str[len - 1] == '5' || str[len - 1] == '0') && (odd - (sum - odd)) % 11 == 0 && leap)
        {
            puts("This is bulukulu festival year.");
            ordinary = false;
        }

        if (ordinary)
            puts("This is an ordinary year.");
    }

    return 0;
}