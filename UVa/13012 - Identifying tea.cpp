#include<cstdio>

int main()
{
    char type;
    char c;

    while ((type = getchar()) != EOF)
    {
        getchar();
        int count = 0;
        for (int i = 0; i < 5; i++)
        {
            if (getchar() == type)
                    count++;
            getchar();
        }

        printf("%d\n", count);
    }

    return 0;
}