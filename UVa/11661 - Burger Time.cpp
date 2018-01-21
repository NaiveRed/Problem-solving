#include <cstdio>

int main()
{
    int len;
    char str[2000005];
    while (scanf("%d ", &len) && len)
    {
        int r = -1, d = -1, min = 1e9;
        fgets(str, 2000005, stdin);
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '.')
                continue;
            else if (str[i] == 'R')
            {
                r = i;
                if (d != -1 && r - d < min)
                    min = r - d;
            }
            else if (str[i] == 'D')
            {
                d = i;
                if (r != -1 && d - r < min)
                    min = d - r;
            }
            else
            {
                min = 0;
                break;
            }
        }

        printf("%d\n", min);
    }

    return 0;
}