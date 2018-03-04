//從第K堆開始往第1堆放，且先放的牌在最上面...
#include <cstdio>
#define N 14

inline int get_point(char c)
{
    if (c >= '2' && c <= '9')
        return c - '0';
    else if (c == 'A')
        return 1;
    else if (c == 'T')
        return 10;
    else if (c == 'J')
        return 11;
    else if (c == 'Q')
        return 12;
    else //'K'
        return 13;
}
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    char cards[N][4][2]; //一開始某一堆的最上面那張是cards[n][0][]
    char str[5];

    while (scanf("%s", str) && str[0] != '#')
    {
        cards[13][0][0] = str[0]; //點數
        cards[13][0][1] = str[1]; //花色
        for (int i = 1; i < N - 1; i++)
        {
            scanf("%s", str);
            cards[13 - i][0][0] = str[0]; //點數
            cards[13 - i][0][1] = str[1]; //花色
        }

        for (int j = 1; j < 4; j++)
        {
            for (int i = 0; i < N - 1; i++)
            {
                scanf("%s", str);
                cards[13 - i][j][0] = str[0];
                cards[13 - i][j][1] = str[1];
            }
        }

        int idx[N] = {}, pos = 13, open = 0;
        char now[2];
        while (idx[pos] < 4)
        {
            open++; //翻開的牌數
            now[0] = cards[pos][idx[pos]][0];
            now[1] = cards[pos][idx[pos]++][1];
            pos = get_point(now[0]);
        }

        printf("%02d,%c%c\n", open, now[0], now[1]);
    }

    return 0;
}
/*
KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S AS
KH QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AH
KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AC
KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AD
04,KD
*/