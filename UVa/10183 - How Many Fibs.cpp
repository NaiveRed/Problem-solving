#include <cstdio>
#include <cstring>
#define F 480
#define N 110

inline int cmp(int *a, int *b) //a<b: -1, a==b: 0, a>b: 1
{
    if (a[0] < b[0])
        return -1;
    else if (a[0] > b[0])
        return 1;

    for (int i = a[0]; i; --i)
        if (a[i] != b[i])
            return (a[i] < b[i]) ? -1 : 1;

    return 0;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int fib[F][N] = {}; //[][0]: 位數

    fib[1][0] = fib[1][1] = 1;
    fib[2][0] = 1;
    fib[2][1] = 2;

    int len = 1;
    for (int i = 3; i < F; ++i)
    {
        for (int j = 1; j <= len; ++j)
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j];

        for (int j = 1; j <= len; ++j)
        {
            if (fib[i][j] > 9)
            {
                fib[i][j] -= 10;
                ++fib[i][j + 1];
                if (j == len)
                    ++len;
            }
        }

        fib[i][0] = len;
    }

    int a[N], b[N];
    char str1[N], str2[N];
    while (true)
    {
        scanf("%s %s", str1, str2);
        a[0] = strlen(str1);
        b[0] = strlen(str2);

        if (str1[0] == '0' && a[0] == 1 && str2[0] == '0' && b[0] == 1)
            break;

        for (int i = a[0] - 1, j = 1; i >= 0; --i, ++j)
            a[j] = str1[i] - '0';

        for (int i = b[0] - 1, j = 1; i >= 0; --i, ++j)
            b[j] = str2[i] - '0';

        int i;
        for (i = 0; i < F; ++i)
            if (cmp(a, fib[i]) <= 0) //a<=fib
                break;

        int count = 0;
        for (; i < F; ++i)
        {
            int tmp = cmp(b, fib[i]);
            if (tmp >= 0) //b>=fib
                ++count;
            else
                break;
        }

        printf("%d\n", count);
    }

    return 0;
}