#include <cstdio>
#include <cstring>
#define N 1000010
#define BASE 10

int main()
{
    static int num[N];
    int n;
    scanf("%d ", &n);
    while (n--)
    {
        int m;
        scanf("%d ", &m);
        for (int i = m - 1; i >= 0; i--)
        {
            int a = getchar() - '0';
            getchar();
            int b = getchar() - '0';
            getchar();
            num[i] = a + b;
        }

        for (int i = 0; i < m; i++)
        {
            if (num[i] >= BASE)
            {
                num[i + 1] += num[i] / BASE;
                num[i] %= BASE;
                if (i + 1 == m)
                    m++;
            }
        }

        for (int i = m - 1; i >= 0; i--)
            putchar(num[i] + '0');
        puts(n ? "\n" : "");

        //init 進位時會影響到
        memset(num, 0, sizeof num);
    }

    return 0;
}
