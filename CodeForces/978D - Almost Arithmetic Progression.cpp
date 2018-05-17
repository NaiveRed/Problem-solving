#include <cstdio>
#include <cstdlib>
#define N 100005

int main()
{
    int n, b[N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);

    if (n == 1)
    {
        puts("0");
        return 0;
    }
    
    int min_change = 1e9;
    int dir[3] = {0, 1, -1};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            int s = b[0] + dir[i], e = b[n - 1] + dir[j];

            if ((e - s) % (n - 1) == 0)
            {
                int d = (e - s) / (n - 1), k;
                int count = (i ? 1 : 0) + (j ? 1 : 0);
                for (s += d, k = 1; k < n - 1; ++k, s += d)
                    if (b[k] != s)
                    {
                        if (abs(s - b[k]) <= 1)
                            ++count;
                        else
                            break;
                    }

                if (k == n - 1)
                    min_change = (min_change > count) ? count : min_change;
            }
        }

    printf("%d\n", min_change != 1e9 ? min_change : -1);

    return 0;
}
