#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("Case %d: %s\n", i, (a <= 20 && b <= 20 && c <= 20) ? "good" : "bad");
    }
    return 0;
}