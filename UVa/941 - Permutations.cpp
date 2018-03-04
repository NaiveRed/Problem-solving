#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;

int main()
{
    LL fac[20] = {1, 1};
    for (int i = 2; i < 20; i++)
        fac[i] = fac[i - 1] * i;

    int Case;
    char str[22];
    scanf("%d", &Case);

    while (Case--)
    {
        LL n;
        getchar();
        fgets(str, 22, stdin);
        scanf("%lld", &n);

        int len = strlen(str) - 1;
        str[len] = '\0';
        std::sort(str, str + len);

        if (!n)
        {
            puts(str);
            continue;
        }

        //康托展開
        bool flag[22] = {};
        while (len--)
        {
            LL count = n / fac[len]; //有幾個比它小的在右邊
            n %= fac[len];

            int idx = 0;

            ++count; //自己要再加一
            while (true)
            {
                if (!flag[idx])
                    --count;

                if (!count)
                    break;

                ++idx;
            }

            flag[idx] = true;

            putchar(str[idx]);
        }

        putchar('\n');
    }

    return 0;
}