#include <cstdio>
#include <cmath>
int main()
{
    int t;
    scanf("%d ", &t);

    char str[260];
    while (t--)
    {
        fgets(str, 260, stdin);
        int x = 0, num = 0, i;
        int tmp = 0, neg = 1;
        bool has_coee = false;

        //x 項移到左，常數項移到右
        //left
        for (i = 0; str[i] != '='; ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                tmp = tmp * 10 + str[i] - '0';
                has_coee = true; //針對 0x => 0, x or 1x => 1 來處理
            }
            else
            {
                if (str[i] == 'x')
                    x += (tmp || has_coee ? tmp : 1) * neg;
                else
                {
                    num -= tmp * neg;
                    neg = str[i] == '+' ? 1 : -1;
                }
                tmp = 0;
                has_coee = false;
            }
        }
        if (tmp)
            num -= tmp * neg;

        //right
        neg = 1, tmp = 0, has_coee = false;
        for (++i; str[i] != '\n'; ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                tmp = tmp * 10 + str[i] - '0';
                has_coee = true;
            }
            else
            {
                if (str[i] == 'x')
                    x -= (tmp || has_coee ? tmp : 1) * neg;
                else
                {
                    num += tmp * neg;
                    neg = str[i] == '+' ? 1 : -1;
                }
                tmp = 0;
                has_coee = false;
            }
        }
        if (tmp)
            num += tmp * neg;

        if (x)
            printf("%d\n", (int)floor((float)num / x));
        else
        {
            /*
            x 係數為 0 時:
                右邊有常數不等於 0(等號左右不相等) => IMPOSSIBLE
                右邊有常數等於 0 => infinite sol.
            */
            puts(num ? "IMPOSSIBLE" : "IDENTITY");
        }
    }

    return 0;
}
/*
10
0x=0
3x=-9
4=4
2+0x=3+0x
2x+3=0
7x-100=2x+200
x-3=3-x
0-x-x-x-x=4
0-x+x=2
0-x+x=0

IDENTITY
-3
IDENTITY
IMPOSSIBLE
-2
60
3
-1
IMPOSSIBLE
IDENTITY
*/