#include<stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int main()
{
    int a, b;

    while (scanf("%d%d", &a, &b) != EOF)
        printf("%d\n", MAX(a, b));

    return 0;
}