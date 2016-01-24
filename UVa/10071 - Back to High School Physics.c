/*
v-t 圖即可解
*/
#include<stdio.h>

int main()
{
    int v, t;
    while (scanf("%d%d", &v, &t) != EOF)
    {
        printf("%d\n", 2 * t*v);
    }
    return 0;
}
