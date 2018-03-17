#include <cstdio>
#include <cstring>

int main()
{
    int T;
    char str[35];
    scanf("%d ", &T);
    for (int t = 1; t <= T; ++t)
    {
        int S1 = 0, S2 = 0;
        fgets(str, 35, stdin);
        for (int i = strlen(str) - 2, k = 1; i >= 0; --i, k <<= 1)
            if (str[i] == '1')
                S1 += k;
        fgets(str, 35, stdin);
        for (int i = strlen(str) - 2, k = 1; i >= 0; --i, k <<= 1)
            if (str[i] == '1')
                S2 += k;

        //GCD
        while (S2)
        {
            int tmp = S2;
            S2 = S1 % S2;
            S1 = tmp;
        }

        printf("Pair #%d: %s\n", t, S1 != 1 ? "All you need is love!" : "Love is not all you need!");
    }

    return 0;
}