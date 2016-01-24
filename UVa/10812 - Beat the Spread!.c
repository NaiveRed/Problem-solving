#include<stdio.h>

int main(){

    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        int s, d;
        scanf("%d%d", &s, &d);
        if (d > s || (s + d) & 1 || (s - d) & 1)
            printf("impossible\n");
        else
            printf("%d %d\n", (s + d) / 2, (s - d) / 2);
    }

    return 0;
}