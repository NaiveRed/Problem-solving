#include <cstdio>
#define ORD(c) ((c) - 'A')

int main()
{    
    int mix[26][3] = {};
    mix[ORD('M')][0] = mix[ORD('Y')][1] = mix[ORD('C')][2] = 1;
    mix[ORD('R')][0] = mix[ORD('V')][0] = mix[ORD('B')][0] = 1;
    mix[ORD('R')][1] = mix[ORD('G')][1] = mix[ORD('B')][1] = 1;
    mix[ORD('V')][2] = mix[ORD('G')][2] = mix[ORD('B')][2] = 1;

    int Case;
    char str[100001];
    scanf("%d", &Case);
    while (Case--)
    {
        int color[3] = {}; //M,Y,C        
        scanf("%d%d%d%s", &color[0], &color[1], &color[2], str);
        for (int i = 0; str[i]; i++)
            for (int j = 0; j < 3; j++)
                color[j] -= mix[ORD(str[i])][j];

        if (color[0] >= 0 && color[1] >= 0 && color[2] >= 0)
            printf("YES %d %d %d\n", color[0], color[1], color[2]);
        else
            puts("NO");
    }

    return 0;
}