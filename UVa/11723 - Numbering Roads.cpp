#include <cstdio>
#include <cmath>

int main()
{
    int R, N, Case = 0;
    while (scanf("%d%d", &R, &N) && R)
    {
        int alp = ceil((float)R / N);

        //都不放字母也行和 A~Z 共 27
        if (alp <= 27)
            printf("Case %d: %d\n", ++Case, alp ? (alp - 1) : 0);
        else
            printf("Case %d: impossible\n", ++Case);
    }

    return 0;
}