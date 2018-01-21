#include <cstdio>

inline int get_num()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' ' && c != '\n')
        n = n * 10 + c - '0';
    return n;
}
inline int get_type()
{
    char c = getchar();
    int type;
    if (c == 'r') //rock
        type = 3;
    else if (c == 's') //scissors
        type = 2;
    else //paper
        type = 1;

    while ((c = getchar()) != ' ' && c != '\n')
        ;

    return type;
}
int main()
{
    //freopen("test.out", "w", stdout);
    //freopen("test.in", "r", stdin);
    int n, k;
    bool f = false;
    while (scanf("%d%d", &n, &k) == 2 && n)
    {
        getchar();
        if (f)
            putchar('\n');
        else
            f = true;

        int lose[101] = {}, win[101] = {};
        int all = n * (n - 1) * k / 2;
        int p1, p2, t1, t2, res;

        for (int i = 0; i < all; i++)
        {
            p1 = get_num();
            t1 = get_type();
            p2 = get_num();
            t2 = get_type();
            res = t1 - t2;

            if (res == 1 || res == -2) //p1 win
            {
                win[p1]++;
                lose[p2]++;
            }
            //else if (res == 2 || res == -1) //p2 win
            else if (res)
            {
                win[p2]++;
                lose[p1]++;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (win[i] + lose[i])
                printf("%.3f\n", (float)win[i] / (win[i] + lose[i]));
            else
                puts("-");
        }
    }
    return 0;
}
