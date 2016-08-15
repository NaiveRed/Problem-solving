#include<cstdio>
#include<cstring>
#include<algorithm>

int ans[105];
inline int carry(int idx)
{
    int ret;
    if (!idx)//(LSB)2 => 01
    {
        ans[1]++;
        ret = 1;
    }
    else if (idx == 1)//(LSB)020 => 101
    {
        ans[2]++, ans[0]++;
        ret = 0;
    }
    else//(LSB)0020 => 1001
    {
        ans[idx + 1]++, ans[idx - 2]++;
        ret = idx - 3;
    }

    ans[idx] -= 2;

    return ret;
}
int main()
{
    char str1[105], str2[105];
    int i;
    bool first = true;
    while (scanf("%s%s", str1, str2) != EOF)
    {
        std::fill(ans, ans + 105, 0);

        int len1 = strlen(str1), len2 = strlen(str2);
        for (i = 0; i < len1; i++)
            ans[i] = str1[len1 - i - 1] - '0';

        for (i = 0; i < len2; i++)
            ans[i] += str2[len2 - i - 1] - '0';

        int cont = 0, len3 = std::max(len1, len2);
        for (i = 0; i < len3; i++)//ans[0] 為 LSB
        {
            if (ans[i] >= 2)
            {
                if (i == len3 - 1)//多一位數
                    len3++;

                i = carry(i) - 1;//i 要從有變動的在開始檢查
                cont = 0;
                continue;
            }
            
            if (ans[i])
                cont++;
            else
                cont = 0;

            if (cont == 2)//處理連續兩個 1 ，進位到下一格
            {
                if (i == len3 - 1)//多一位數
                    len3++;

                cont = 0;
                ans[i + 1]++;
                ans[i - 1] = ans[i] = 0;
            }
        }

        if (first)
            first = false;
        else
            putchar('\n');

        for (i = len3 - 1; i >= 0; i--)//從MSB開始輸出
            putchar(ans[i] + '0');
        putchar('\n');
    }

    return 0;
}