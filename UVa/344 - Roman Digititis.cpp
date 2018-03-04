#include <cstdio>

int main()
{
    const char c[5] = {'c', 'l', 'x', 'v', 'i'};
    const int roman[5] = {100, 50, 10, 5, 1}; //c,l,x,v,i
    int count[101][5] = {};                   //100,50,10,5,1
    for (int i = 1; i < 101; i++)
    {
        int tmp = i;
        if (tmp % 10 == 4)
        {
            count[i][3]++;
            count[i][4]++;
            tmp -= 4;
        }
        else if (tmp % 10 == 9)
        {
            count[i][2]++;
            count[i][4]++;
            tmp -= 9;
        }

        if (tmp / 10 == 4)
        {
            count[i][1]++;
            count[i][2]++;
            tmp -= 40;
        }
        else if (tmp / 10 == 9)
        {
            count[i][0]++;
            count[i][2]++;
            tmp -= 90;
        }

        for (int j = 0; j < 5; j++)
        {
            count[i][j] += count[i - 1][j] + tmp / roman[j];
            tmp %= roman[j];
        }
    }

    int n;
    while (scanf("%d", &n) && n)
    {
        printf("%d: %d i", n, count[n][4]);
        for (int i = 3; i >= 0; i--)
            printf(", %d %c", count[n][i], c[i]);
        putchar('\n');
    }

    return 0;
}