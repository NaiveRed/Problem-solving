#include<cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, diff = 0, top, bottom;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d%d", &top, &bottom);
            if (diff != -1)
            {
                if (!diff)
                    diff = top - bottom;
                else if (diff != top - bottom)
                    diff = -1;
            }
        }

        puts(diff == -1 ? "no" : "yes");
        if (Case)
            putchar('\n');
    }
    return 0;
}