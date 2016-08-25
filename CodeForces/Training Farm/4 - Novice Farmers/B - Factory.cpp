#include<cstdio>

int main()
{
    int N, H, D;
    scanf("%d%d%d", &N, &H, &D);
    int need = N * 24 * D;
    printf("%d\n", need / H + (need%H ? 1 : 0));

    return 0;
}