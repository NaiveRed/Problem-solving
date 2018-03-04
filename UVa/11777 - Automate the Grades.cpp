#include <cstdio>
#include <algorithm>

int main()
{
    int Case;
    scanf("%d", &Case);
    for (int c = 1; c <= Case; c++)
    {
        printf("Case %d: ", c);
        int n[7];
        for (int i = 0; i < 7; i++)
            scanf("%d", &n[i]);
        
        int sum = (n[4] + n[5] + n[6] - std::min(n[4], std::min(n[5], n[6]))) / 2;

        for (int i = 0; i < 4; i++)
            sum += n[i];

        if (sum >= 90)
            puts("A");
        else if (sum >= 80)
            puts("B");
        else if (sum >= 70)
            puts("C");
        else if (sum >= 60)
            puts("D");
        else
            puts("F");
    }

    return 0;
}