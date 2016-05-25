#include<cstdio>

int main()
{
    puts("Lumberjacks:");
    int Case,num[10];
    scanf("%d", &Case);
    while (Case--)
    {
        int i;
        for (i = 0; i < 10; i++)
            scanf("%d", &num[i]);
        
        bool ok = true;
        for (i = 0; i < 9; i++)//小到大
            if (num[i] >= num[i + 1])
            {
            ok = false;
            break;
            }

        if (!ok)
        {
            ok = true;
            for (i = 0; i < 9; i++)//大到小
                if (num[i] <= num[i + 1])
                {
                ok = false;
                break;
                }
        }

        puts(ok ? "Ordered" : "Unordered");
    }

    return 0;
}