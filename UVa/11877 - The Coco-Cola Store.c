#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) && n)            
        printf("%d\n", n / 2); /*每兩空瓶換一瓶*/

    return 0;
}