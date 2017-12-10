#include <cstdio>

int main()
{
    int count[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    int n;
    char str[102];
    scanf("%d", &n);
    getchar();
    for (int c = 1; c <= n; c++)
    {
        int sum = 0;
        fgets(str, 102, stdin);
        for (int i = 0; str[i] != '\n'; i++)
            sum += str[i] != ' ' ? count[str[i] - 'a'] : 1;

        printf("Case #%d: %d\n", c, sum);
    }

    return 0;
}