#include<stdio.h>

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int G, L;
        scanf("%d%d", &G, &L);
       
        if (L%G)
            puts("-1");
        else
            printf("%d %d\n", G, L);
        
    }
    return 0;
}