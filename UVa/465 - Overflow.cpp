#include <cstdio>
#include <cstring>
#include <climits>

int main()
{
    //freopen("test.out", "w", stdout);
    char str[1000];
    while (fgets(str, 1000, stdin))
    {
        int len = strlen(str);
        if (str[len - 1] == '\n')
            str[len - 1] = '\0';
        puts(str);

        double a, b;
        char op;
        sscanf(str, "%lf %c %lf", &a, &op, &b);

        if (a > INT_MAX) //2147483647
            puts("first number too big");

        if (b > INT_MAX)
            puts("second number too big");

        if ((op == '+' && a + b > INT_MAX) || (op == '*' && a * b > INT_MAX))
            puts("result too big");
    }

    return 0;
}