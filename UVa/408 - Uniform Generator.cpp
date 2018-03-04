#include <cstdio>

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        printf("%10d%10d    ", a, b);
        while (b)
        {
            int tmp = b;
            b = a % b;
            a = tmp;
        }

        puts(a == 1 ? "Good Choice\n" : "Bad Choice\n");
    }

    return 0;
}