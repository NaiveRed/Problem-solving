#include<cstdio>
#include<cstring>
#include<algorithm>
int main()
{
    int n;
    scanf("%d", &n);

    char a[205], b[205];
    int i, ans[205];
    while (n--)
    {
        for (i = 0; i < 205; i++)
        {
            b[i] = a[i] = '0';
            ans[i] = 0;
        }

        scanf("%s%s", a, b);

        int len1 = strlen(a), len2 = strlen(b), temp;
        //最後面是 0 時，顛倒後會去掉
		for (i = len1 - 1; i >= 0; i--)
            if (a[i]!='0')
                break;
            else
                len1--;

        for (i = len2 - 1; i >= 0; i--)
            if (b[i]!='0')
                break;
            else
                len2--;

        for (i = 0; i < len1; i++)
            ans[i] = a[i] - '0';
        for (i = 0; i < len2; i++)
            ans[i] += b[i] - '0';
        
        temp = std::max(len1, len2);

        for (i = 0; i < temp; i++)
        {
            if (ans[i] >= 10)
            {
                if (i == temp - 1)
                    temp++;
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }

        for (i = 0; i < temp; i++)
            if (ans[i])
                break;
        for (; i < temp; i++)
            putchar('0' + ans[i]);
        putchar('\n');
    }

    return 0;
}