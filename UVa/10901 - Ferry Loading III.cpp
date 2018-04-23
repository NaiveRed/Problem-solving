/*
如果船在的另一邊已經有車在等了，那船的這邊一載完已經到的後就要馬上開走。  
有可能空船走，但前提是另一邊要有車在等。
*/
#include <cstdio>
#include <queue>
#define N 10000

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    struct car
    {
        int id, arr_time;
        car() {}
        car(int id_, int arr_) : id(id_), arr_time(arr_) {}
    };

    int tar_time[N]; //到達目的時間
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, t, m;
        scanf("%d%d%d", &n, &t, &m);

        std::queue<car> bank[2]; //0: left, 1: right

        char str[6];
        int tmp;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%s", &tmp, str);
            if (str[0] == 'l')
                bank[0].emplace(i, tmp);
            else
                bank[1].emplace(i, tmp);
        }

        int now = 0, load = 0;
        int tt = 0;
        int side = 0, opposite = 1; //0: left, 1: right

        car c;
        //要注意其中一邊有車或船上有車時，船才會動
        while (!bank[0].empty() || !bank[1].empty())
        {
            tt = now + t; //該趟到達對岸的時間

            if (bank[side].empty())
            {
                //空船開到另一邊
                if (now < bank[opposite].front().arr_time)
                    tt = bank[opposite].front().arr_time + t;
            }
            else
            {
                //first car
                c = bank[side].front();
                if (c.arr_time > now)
                {
                    //另一邊沒有車了 或 另一邊的到達時間比這邊的慢，就停原地等
                    if (bank[opposite].empty() || bank[opposite].front().arr_time >= c.arr_time)
                    {
                        now = c.arr_time;
                        tt = now + t;
                    }
                    else
                    {
                        //空船開到另一邊
                        if (now < bank[opposite].front().arr_time)
                            now = bank[opposite].front().arr_time + t; //另一邊沒車，等車到了船才會開過去
                        else
                            now = tt; //另一邊有車，直接開過去

                        opposite = side;
                        side ^= 1;
                        continue;
                    }
                }

                load = 1;
                tar_time[c.id] = tt;
                bank[side].pop();

                //other cars
                while (load < n && !bank[side].empty())
                {
                    c = bank[side].front();

                    if (c.arr_time > now) //這邊到的載完了，直接開到對岸
                        break;

                    ++load;
                    tar_time[c.id] = tt;
                    bank[side].pop();
                }
            }

            load = 0;
            now = tt;
            opposite = side;
            side ^= 1;
        }

        for (int i = 0; i < m; ++i)
            printf("%d\n", tar_time[i]);

        if (Case)
            putchar('\n');
    }

    return 0;
}