//UVa: 0.000
#include <cstdio>
typedef long long LL;

int main()
{
    //freopen("test.out", "w", stdout);
    //freopen("test.in", "r", stdin);
    LL ans[17][17][2] = {{{2, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{12, 22}, {12, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{112, 222}, {112, 212}, {112, 0}, {112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{1112, 2222}, {1112, 2212}, {1112, 2112}, {2112, 0}, {2112, 0}, {2112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{11112, 22222}, {11112, 22212}, {11112, 22112}, {12112, 22112}, {22112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{111112, 222222}, {111112, 222212}, {111112, 222112}, {112112, 222112}, {122112, 222112}, {122112, 0}, {122112, 0}, {122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{1111112, 2222222}, {1111112, 2222212}, {1111112, 2222112}, {1112112, 2222112}, {1122112, 2222112}, {1122112, 2122112}, {2122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{11111112, 22222222}, {11111112, 22222212}, {11111112, 22222112}, {11112112, 22222112}, {11122112, 22222112}, {11122112, 22122112}, {12122112, 22122112}, {12122112, 0}, {12122112, 0}, {12122112, 0}, {12122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{111111112, 222222222}, {111111112, 222222212}, {111111112, 222222112}, {111112112, 222222112}, {111122112, 222222112}, {111122112, 222122112}, {112122112, 222122112}, {112122112, 212122112}, {212122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{1111111112, 2222222222}, {1111111112, 2222222212}, {1111111112, 2222222112}, {1111112112, 2222222112}, {1111122112, 2222222112}, {1111122112, 2222122112}, {1112122112, 2222122112}, {1112122112, 2212122112}, {1212122112, 2212122112}, {1212122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{11111111112, 22222222222}, {11111111112, 22222222212}, {11111111112, 22222222112}, {11111112112, 22222222112}, {11111122112, 22222222112}, {11111122112, 22222122112}, {11112122112, 22222122112}, {11112122112, 22212122112}, {11212122112, 22212122112}, {11212122112, 21212122112}, {11212122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{111111111112, 222222222222}, {111111111112, 222222222212}, {111111111112, 222222222112}, {111111112112, 222222222112}, {111111122112, 222222222112}, {111111122112, 222222122112}, {111112122112, 222222122112}, {111112122112, 222212122112}, {111212122112, 222212122112}, {111212122112, 221212122112}, {111212122112, 211212122112}, {111212122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{1111111111112, 2222222222222}, {1111111111112, 2222222222212}, {1111111111112, 2222222222112}, {1111111112112, 2222222222112}, {1111111122112, 2222222222112}, {1111111122112, 2222222122112}, {1111112122112, 2222222122112}, {1111112122112, 2222212122112}, {1111212122112, 2222212122112}, {1111212122112, 2221212122112}, {1111212122112, 2211212122112}, {1111212122112, 2111212122112}, {1111212122112, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{11111111111112, 22222222222222}, {11111111111112, 22222222222212}, {11111111111112, 22222222222112}, {11111111112112, 22222222222112}, {11111111122112, 22222222222112}, {11111111122112, 22222222122112}, {11111112122112, 22222222122112}, {11111112122112, 22222212122112}, {11111212122112, 22222212122112}, {11111212122112, 22221212122112}, {11111212122112, 22211212122112}, {11111212122112, 22111212122112}, {11111212122112, 21111212122112}, {11111212122112, 0}, {11111212122112, 0}, {11111212122112, 0}, {11111212122112, 0}},
                         {{111111111111112, 222222222222222}, {111111111111112, 222222222222212}, {111111111111112, 222222222222112}, {111111111112112, 222222222222112}, {111111111122112, 222222222222112}, {111111111122112, 222222222122112}, {111111112122112, 222222222122112}, {111111112122112, 222222212122112}, {111111212122112, 222222212122112}, {111111212122112, 222221212122112}, {111111212122112, 222211212122112}, {111111212122112, 222111212122112}, {111111212122112, 221111212122112}, {111111212122112, 211111212122112}, {211111212122112, 0}, {0, 0}, {0, 0}},
                         {{1111111111111112, 2222222222222222}, {1111111111111112, 2222222222222212}, {1111111111111112, 2222222222222112}, {1111111111112112, 2222222222222112}, {1111111111122112, 2222222222222112}, {1111111111122112, 2222222222122112}, {1111111112122112, 2222222222122112}, {1111111112122112, 2222222212122112}, {1111111212122112, 2222222212122112}, {1111111212122112, 2222221212122112}, {1111111212122112, 2222211212122112}, {1111111212122112, 2222111212122112}, {1111111212122112, 2221111212122112}, {1111111212122112, 2211111212122112}, {1211111212122112, 2211111212122112}, {1211111212122112, 0}, {0, 0}},
                         {{11111111111111112, 22222222222222222}, {11111111111111112, 22222222222222212}, {11111111111111112, 22222222222222112}, {11111111111112112, 22222222222222112}, {11111111111122112, 22222222222222112}, {11111111111122112, 22222222222122112}, {11111111112122112, 22222222222122112}, {11111111112122112, 22222222212122112}, {11111111212122112, 22222222212122112}, {11111111212122112, 22222221212122112}, {11111111212122112, 22222211212122112}, {11111111212122112, 22222111212122112}, {11111111212122112, 22221111212122112}, {11111111212122112, 22211111212122112}, {11211111212122112, 22211111212122112}, {11211111212122112, 21211111212122112}, {11211111212122112, 0}}};

    //dfs(略)

    //要先建好ans後的打表
    /*
    printf("LL ans = {");
    for (int len = 1; len <= 17; len++)
    {
        putchar('{');
        for (int power = 1; power <= 17; power++)
        {
            printf("{%lld,%lld}", ans[0][len][power], ans[1][len][power]);
            if (power != 17)
                putchar(',');
        }
        putchar('}');
        if (len != 17)
            putchar(',');
    }
    putchar('}');
    */

    int Case;
    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int len, power;
        scanf("%d%d", &len, &power);
        len--;
        power--;
        printf("Case %d:", c);
        if (ans[len][power][0])
        {
            if (ans[len][power][1])
                printf(" %lld %lld\n", ans[len][power][0], ans[len][power][1]);
            else
                printf(" %lld\n", ans[len][power][0]);
        }
        else
            puts(" impossible");
    }

    return 0;
}