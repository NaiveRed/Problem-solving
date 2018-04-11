//上傳要移掉註解
#include <cstdio>
#include <algorithm>
#define N 100005
int main()
{
    int T;
    int even[N] = {}, odd[N] = {};
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int n, even_idx = 0, odd_idx = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", ((i & 1) ? (&odd[odd_idx++]) : (&even[even_idx++])));
            
        std::sort(even, even + even_idx);
        std::sort(odd, odd + odd_idx);

        bool ok = (even[0] <= odd[0]);
        int wrong = ok ? -1 : 0, idx;
        if (ok)
        {
            for (idx = 1; idx < (n >> 1); ++idx)
            {
                if (odd[idx - 1] > even[idx])
                {
                    wrong = (idx << 1) - 1;
                    ok = false;
                    break;
                }
                else if (even[idx] > odd[idx])
                {
                    wrong = idx << 1;
                    ok = false;
                    break;
                }
            }
        }

        if (ok && (n & 1))
        {
            if (odd[idx - 1] > even[idx])
            {
                ok = false;
                wrong = (idx << 1) - 1;
            }
        }

        if (ok)
            printf("Case #%d: OK\n", t);
        else
            printf("Case #%d: %d\n", t, wrong);
    }

    return 0;
}