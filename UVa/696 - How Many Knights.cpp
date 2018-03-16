#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int M, N;
    while (scanf("%d%d", &M, &N) && (M || N))
    {
        int a = min(M, N), b = max(M, N), ans;

        if (a == 1)
            ans = b;
        else if (a == 2)
        {
            int c = b % 4;
            if (c)
                ans = (b / 4) * 4 + (c > 1 ? 4 : 2);
            else
                ans = (b / 4) * 4;
        }
        else
            ans = (a * b + 1) / 2;
        printf("%d knights may be placed on a %d row %d column board.\n", ans, M, N);
    }

    return 0;
}