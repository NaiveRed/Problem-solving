#include <cstdio>

int main()
{    
    char str[22];
    int encode[26] =
        {0, 1, 2, 3, 0, 1, 2,
         0, 0, 2, 2, 4, 5, 5,
         0, 1, 2, 6, 2, 3, 0,
         1, 0, 2, 0, 2};

    while (fgets(str, 22, stdin))
    {
        int last = 0;
        for (int i = 0; str[i] != '\n' && str[i]; i++)
        {
            int code = encode[str[i] - 'A'];
            if (code != last)
            {
                last = code;
                if (code)
                    putchar('0' + code);
            }
        }
        putchar('\n');
    }

    return 0;
}