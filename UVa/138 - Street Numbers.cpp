#include <cstdio>
typedef long long LL;

int main()
{
    /*int ans[10][2] = {{6, 8},
                    {35, 49},
                    {204, 288},
                    {1189, 1681},
                    {6930, 9800},
                    {40391, 57121},
                    {235416, 332928},
                    {1372105, 1940449},
                    {7997214, 11309768},
                    {46611179, 65918161}};

  for (int i = 0; i < 10; i++)
    printf("%10lld%10lld\n", ans[i][0], ans[i][1]);*/

    LL n = 8, k = 6;
    LL s_l = 15, s_r = 15; //左半邊和右半邊的和

    int count = 10;
    //利用門牌遞增的特性
    while (count)
    {
        if (s_l < s_r) //左邊和較小就將 k 向右移
        {
            s_l += k;
            k++;
            s_r -= k;
        }
        else if (s_l > s_r) //右邊和較小就將 n 增加
        {
            n++;
            s_r += n;
        }
        else
        {
            printf("%10lld%10lld\n", k, n);
            count--;
            n++;
            s_r += n;
        }
    }

    return 0;
}