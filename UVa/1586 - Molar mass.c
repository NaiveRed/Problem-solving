#include<stdio.h>
#include<string.h>

int main()
{
    int Case;
    char str[100];
    scanf("%d", &Case);

    //getchar()
    while (Case--)
    {
        scanf("%s", str);//¥Îgets(str)²ö¦W·|¿ù....

        double sum = 0, atomic;
        int i, len = strlen(str);

        for (i = 0; i < len;)
        {
            if (str[i] == 'C')
                atomic = 12.01;
            else if (str[i] == 'H')
                atomic = 1.008;
            else if (str[i] == 'O')
                atomic = 16.00;
            else if (str[i] == 'N')
                atomic = 14.01;

            i++;
            int n = 0;
            while (str[i] <= '9' && str[i] >= '0')
            {
                n = n * 10 + str[i] - '0';
                i++;
            }

            sum += atomic*(n ? n : 1);
        }

        printf("%.3lf\n", sum);
    }

    return 0;
}