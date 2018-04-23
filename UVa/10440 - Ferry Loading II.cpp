#include <cstdio>

int main()
{
    int arr_time[1441];
    int C;
    scanf("%d", &C);
    while (C--)
    {
        int n, t, m, i;
        scanf("%d%d%d", &n, &t, &m);

        for (i = 1; i <= m; ++i)
            scanf("%d", &arr_time[i]);

        int times = 0, tmp = m % n;

        t *= 2;
        if (tmp)
        {
            //先把 前面先到 且 無法除盡的部分 一次載掉(為後面還沒到的爭取時間)
            times = arr_time[tmp] + t;
            i = tmp;
        }
        else
            i = 0;

        //由於多出的已經載掉，直接數次 n 個載完
        for (i += n; i <= m; i += n)
        {
            if (times < arr_time[i])
                times = arr_time[i] + t;
            else
                times += t;
        }

        printf("%d %d\n", times - (t / 2), (m + n - 1) / n);
    }

    return 0;
}
/*
2
2 5 5
6 
7
10
12
14
2 5 6
6 
7
10
12
14
33

31 3
38 3
*/