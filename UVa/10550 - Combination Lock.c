/*
注意轉動鎖時:
順時針，箭頭指向順序為 39 38 37 .... 0
逆時針，箭頭指向順序為 0 1 2 3 ... 39
*/
#include<stdio.h>

int main()
{
    int st, a, b, c;
    while (scanf("%d%d%d%d", &st, &a, &b, &c) && (st || b || a || c))
    {
        int count = 1080;
        //每個都分成是否小於現在的位置去做處理
        count += ((st >= a) ? (st - a) : (st + 40 - a)) * 9;
        count += ((a > b) ? (40 - a + b) : (b - a)) * 9;
        count += ((b >= c) ? (b - c) : (b + 40 - c)) * 9;
        printf("%d\n", count);
    }

    return 0;
}