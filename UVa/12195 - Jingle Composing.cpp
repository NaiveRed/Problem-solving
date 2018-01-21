#include <cstdio>

int main()
{
    int len[26] = {};
    len['W' - 'A'] = 64;
    len['H' - 'A'] = 32;
    len['Q' - 'A'] = 16;
    len['E' - 'A'] = 8;
    len['S' - 'A'] = 4;
    len['T' - 'A'] = 2;
    len['X' - 'A'] = 1;

    char str[205];
    while (fgets(str, 205, stdin))
    {
        if (str[0] == '*')
            break;

        int ans = 0, count = 0;
        for (int i = 0; str[i] != '\n'; i++)
        {
            if (str[i] == '/')
            {
                if (count == 64)
                    ans++;
                count = 0;
                continue;
            }
            count += len[str[i] - 'A'];
        }

        printf("%d\n", ans);
    }
    return 0;
}