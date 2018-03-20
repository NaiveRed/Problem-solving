#include <cstdio>

int main()
{
    char temp;

    while ((temp = getchar()) != EOF)
    {
        while (temp == '0')
            temp = getchar();

        int x[255]{}, y[255]{};

        //讀入數字，最高位在x[0]
        int i(1);
        if (temp == '\n')
            x[0] = 0;
        else
        {
            x[0] = temp - '0';
            while ((temp = getchar()) != '\n')
                x[i++] = temp - '0';
        }

        int j(1);
        temp = getchar();
        while (temp == '0')
            temp = getchar();
        if (temp == '\n')
            y[0] = 0;
        else
        {
            y[0] = temp - '0';
            while ((temp = getchar()) != '\n')
                y[j++] = temp - '0';
        }

        int ans[510]{0};
        for (int n = i - 1; n >= 0; n--)
            for (int m = j - 1; m >= 0; m--)
                ans[n + m] = ans[n + m] + x[n] * y[m]; //如直式乘法: x的n位 * y的m位 = ans的 n+m 位 再加上之前已加過的

        int len(i + j - 2); //n + m = i - 1 + j - 1

        //進位處理，從最低位開始
        while (len > 0)
        {

            if (ans[len] >= 10)
            {
                ans[len - 1] += (ans[len] / 10);
                ans[len] %= 10;
            }

            len--;
        }
        len = i + j - 2;

        //處理第一位數要進位的情況(因為ans[index],index不可為-1)
        if (ans[0] >= 10)
        {
            int first = (ans[0] / 10);
            ans[0] %= 10;
            putchar(first + '0');
        }
        //處理答案為0的情況
        else if (!ans[0])
        {
            puts("0");
            continue;
        }

        for (int n = 0; n <= len; n++)
            putchar(ans[n] + '0');

        putchar('\n');
    }

    return 0;
}