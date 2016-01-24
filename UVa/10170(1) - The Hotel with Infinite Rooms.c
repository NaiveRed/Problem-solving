#include <stdio.h>

int main(void)
{
    int n;
    long long day;
    while (scanf("%d%lld", &n, &day) != EOF)
    {
        /*
        幾個人就需要幾天
        ex. 3 d
        day     1 2 3 4 5 ... d
        people  3 3 3 4 4 ...

        3 + 4 + ... 
        */
        long long sum = 0;
        for (; sum < day; n++)
            sum += n;

        printf("%d\n", n - 1);
    }

    return 0;
}