#include <cstdio>

int main()
{
    int up = 11, low = 0, n;
    char str[20];
    bool ok = true;

    while (scanf("%d ", &n) && n)
    {
        fgets(str, 20, stdin);
        if (str[4] == 'l' && n > low)
            low = n;
        else if (str[4] == 'h' && n < up)
            up = n;
        else if (str[0] == 'r')
        {
            if (n >= up || n <= low) //不在範圍內
                ok = false;

            puts(ok ? "Stan may be honest" : "Stan is dishonest");
            ok = true;
            up = 11;
            low = 0;
            continue;
        }
    }

    return 0;
}
