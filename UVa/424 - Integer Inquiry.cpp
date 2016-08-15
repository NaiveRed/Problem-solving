#include<stdio.h>
#include<string.h>
#define N 110

int main() {

    char s[N];
    int sum[N] = { 0 };
    int i;

    while (fgets(s, N, stdin) && !(s[0] == '0'&&s[1] == '\0'))
    {

        int len = strlen(s) - 1;
        s[len] = NULL;

        for (i = 0; i < len; i++)
        {
            sum[i] += s[len - i - 1] - '0';
            if (sum[i] >= 10)
            {
                sum[i + 1] += sum[i] / 10;
                sum[i] %= 10;
            }
        }
    }

    for (i = N - 1; i >= 0 && !sum[i]; i--);

    while (i >= 0)
        printf("%d", sum[i--]);
    putchar('\n');

    return 0;
}