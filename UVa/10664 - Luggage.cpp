#include <cstdio>
#include <cstring>

int main()
{
    //freopen("test.out", "w", stdout);
    int t;
    char str[70];
    int weight[20] = {};
    scanf("%d ", &t);
    while (t--)
    {
        fgets(str, 70, stdin);
        int n = 0, len = strlen(str);
        str[--len] = '\0';

        for (int i = 0; i < len; ++i)
        {
            if (str[i] == ' ')
            {
                ++n;
                continue;
            }

            weight[n] = weight[n] * 10 + str[i] - '0';
        }

        int sum = 0;
        for (int i = 0; i <= n; ++i)
            sum += weight[i];

        if (sum & 1)
            puts("NO");
        else
        {
            bool DP[201] = {true};
            int half = sum >> 1;
            for (int i = 0; i <= n; ++i)
            {
                if (weight[i] > half)
                    continue;
                for (int w = half; w >= weight[i]; --w)
                    DP[w] |= DP[w - weight[i]];
            }

            puts(DP[half] ? "YES" : "NO");
        }

        memset(weight, 0, sizeof weight);
    }

    return 0;
}