#include<cstdio>
#include<cctype>
#include<deque>
#include<cstring>
using namespace std;

char str[100];
deque<int> num;
void solve();
int main()
{
    while (fgets(str, 100, stdin) && str[0] != '*')
    {
        str[strlen(str) - 1] = NULL;
        solve();
        num.clear();
    }

    return 0;
}
void solve()
{
    int len = strlen(str), i, k;
    int base, tar, tran, size = 1;
    if (isdigit(str[0]))
        base = 10, tar = 26, tran = '0';
    else
        base = 26, tar = 10, tran = 'a' - 1;

    //把字串轉成數字
    for (i = 0; i < len; i++)
    {
        if (i)
        {
            size = num.size();

            //迭代計算次方
            for (k = 0; k < size; k++)
                num[k] *= base;
            num[size - 1] += (str[i] - tran);
        }
        else//還沒有數字時
            num.push_back(str[i] - tran);

        //處理進位
        for (k = size - 1; k; k--)
            if (num[k] >= tar)
            {
            num[k - 1] += (num[k] / tar);
            num[k] %= tar;
            }

        //最高位
        while (num[0] >= tar)
        {
            num.push_front(num[0] / tar);
            num[1] %= tar;
        }
    }

    size = num.size();
    if (base == 10)//轉成英文字母
    {
        /*
        處理沒有 0 的問題:

        將每個 num[] 只要是 0 ，就將其前一位減一，如果前一位也是 0 就借位直到不為 0 的。
        */
        for (i = size - 1; i; i--)
        {
            if (!num[i])
            {
                for (int j = i - 1; j >= 0; j--)
                    if (!num[j])
                        num[j] = 25;
                    else
                    {
                        num[j]--;
                        break;
                    }
            }
        }

        int temp = 0;
        //如果第一位是 0 則代表借位借掉了(非 z)
        for (i = num[0] ? 0 : 1; i < size; i++)
        {
            putchar(num[i] ? ('a' + num[i] - 1) : 'z');//0 為 z，其餘要減 1 才是代表的字母
            temp++;
        }

        //格式處理
        for (; temp < 22; temp++)
            putchar(' ');
        i = 0;
        int count = len % 3;
        if (count)//多出來的
        {
            for (i = 0; i < count; i++)
                putchar(str[i]);
            if (len > 3)
                putchar(',');
        }

        count = 0;
        for (; i < len; i++, count++)
        {
            if (count == 3)
            {
                putchar(',');
                count = 0;
            }
            putchar(str[i]);
        }

        putchar('\n');
    }
    else//轉成數字(decimal)
    {
        printf("%-22s", str);

        int  count;

        count = size % 3;
        i = 0;
        if (count)//多出來的
        {
            while (count--)
                putchar('0' + num[i++]);

            if (size > 3)
                putchar(',');
        }

        count = 0;
        for (; i < size; i++, count++)
        {
            if (count == 3)
            {
                putchar(',');
                count = 0;
            }

            putchar('0' + num[i]);
        }
        putchar('\n');
    }
}