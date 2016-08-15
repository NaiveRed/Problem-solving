#include<cstdio>
#include<algorithm>

int main()
{
    char str[20];
    int n, h, Case;
    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d%d", &n, &h);
        int i;
        for (i = 0; i < n - h; i++)
            str[i] = '0';
        for (i = 1; i <= h; i++)
            str[n - i] = '1';
        
        str[n] = NULL;
        do
        {
            puts(str);
        } while (std::next_permutation(str, str + n));
        if (Case)
            putchar('\n');
    }

    return 0;
}