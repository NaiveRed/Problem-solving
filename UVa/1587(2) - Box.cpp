#include<cstdio>

int main()
{
    int w, h, pallet[6][2] = {};

    while (scanf("%d%d", &w, &h) != EOF)
    {
        if (w < h)
            pallet[0][0] = w, pallet[0][1] = h;
        else
            pallet[0][0] = h, pallet[0][1] = w;

        int i;
        for (i = 1; i < 6; i++)
        {
            scanf("%d%d", &w, &h);
            if (w < h)
                pallet[i][0] = w, pallet[i][1] = h;
            else
                pallet[i][0] = h, pallet[i][1] = w;
        }

        bool used[6] = {}, ok = true;
        int side[3][2], count = 0;

        //看是否兩兩成對，並找不一樣的 3 塊
        for (i = 0; i < 6; i++)
        {
            if (used[i])
                continue;

            for (int j = i + 1; j < 6; j++)
                if (!used[j] && pallet[i][0] == pallet[j][0] && pallet[i][1] == pallet[j][1])
                {
                used[i] = used[j] = true;
                break;
                }

            if (!used[i])
                break;

            side[count][0] = pallet[i][0];
            side[count++][1] = pallet[i][1];
        }

        for (i = 0; i < 6; i++)
            if (!used[i])
                ok = false;

        if (ok)
        {
            ok = false;

            //用那 3 塊去拚看看矩形的 上方一片、側邊兩片
            for (i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    if (side[0][i] == side[1][j])
                    {
                        if (side[0][!i] == side[2][0] && side[2][1] == side[1][!j])
                            ok = true;
                        else if (side[0][!i] == side[2][1] && side[2][0] == side[1][!j])
                            ok = true;
                    }
                }
            }
        }

        puts(ok ? "POSSIBLE" : "IMPOSSIBLE");
    }

    return 0;
}