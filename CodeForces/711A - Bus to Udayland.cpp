#include<cstdio>

int main()
{
    int n, i;
    bool ans = false;
    char seat[1000][4];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        getchar();
        scanf("%c%c|%c%c", &seat[i][0], &seat[i][1], &seat[i][2], &seat[i][3]);
        if (!ans)
        {
            if (seat[i][0] == 'O'&& seat[i][1] == 'O')
            {
                seat[i][0] = seat[i][1] = '+';
                ans = true;
            }
            else if (seat[i][2] == 'O'&&seat[i][3] == 'O')
            {
                seat[i][2] = seat[i][3] = '+';
                ans = true;
            }
        }

        //
    }

    if (ans)
    {
        puts("YES");
        for (i = 0; i < n; i++)
            printf("%c%c|%c%c\n", seat[i][0], seat[i][1], seat[i][2], seat[i][3]);
    }
    else
        puts("NO");
    
    return 0;
}