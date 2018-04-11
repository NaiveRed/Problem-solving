//上傳要移掉註解
#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    int T;
    char P[35] = {};
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int D;
        scanf("%d%s", &D, P);

        int len = strlen(P);
        int tot_dmg, dmg[35] = {};

        dmg[0] = (P[0] == 'C' ? 2 : 1);
        tot_dmg = (P[0] == 'S' ? 1 : 0);

        for (int i = 1; i < len; ++i)
        {
            if (P[i] == 'C')
                dmg[i] = dmg[i - 1] << 1;
            else //'S'
            {
                tot_dmg += dmg[i - 1];
                dmg[i] = dmg[i - 1];
            }
        }

        int ans = 0, s = len - 1;
        while (D < tot_dmg)
        {
            while (s)
            {
                if (P[s] == 'S' && P[s - 1] == 'C')
                    break;
                else
                    --s;
            }

            if (!s)
                break;

            std::swap(P[s], P[s - 1]);
            dmg[s - 1] >>= 1;
            tot_dmg -= dmg[s - 1];

            //交換位置後的 s，要重新檢查前面的
            // ..[CS]S => ..[SC]S
            //...CS => ...SC 的情況，交換後 P[s] 會等於 '\0'
            ++s;
            ++ans;
        }

        if (D >= tot_dmg)
            printf("Case #%d: %d\n", t, ans);
        else
            printf("Case #%d: IMPOSSIBLE\n", t);
    }

    return 0;
}