#include <cstdio>
#include <cstring>
#include <new>
#define ORD(ch) (ch - 'A')
#define N 26

int main()
{
    int n;
    char input[10];
    int *past = new int[N](), *now = new int[N]();

    while (scanf("%d ", &n) != EOF)
    {
        int goal[N], gn = 0;
        int G[N][2];
        bool use[N] = {};
        for (int i = 0; i < n; ++i)
        {
            fgets(input, 10, stdin);
            use[ORD(input[0])] = true;
            G[ORD(input[0])][0] = ORD(input[2]);
            G[ORD(input[0])][1] = ORD(input[4]);
            if (input[6] == 'x')
                goal[gn++] = ORD(input[0]);
        }

        int m;
        scanf("%d", &m);

        //past: 上一時間點到各點的方法數, now: 目前到各點的方法數
        memset(past, 0, sizeof(int) * N);
        past[0] = 1; //'A' is start point

        for (int i = 0; i < m; ++i) //step
        {
            for (int j = 0; j < N; ++j)
                if (use[j])
                {
                    /*
                    e.g. A B C
                    (走 (i+1) 步後到達 B 的方法數) 會包含(+=) (走 i 步到達 A 的方法數)
                    (走 (i+1) 步後到達 C 的方法數) 會包含(+=) (走 i 步到達 A 的方法數)
                    */
                    now[G[j][0]] += past[j];
                    now[G[j][1]] += past[j];
                }

            //swap now and past, then initialize now
            int *tmp = past;
            past = now;
            now = tmp;
            memset(now, 0, sizeof(int) * N);
        }

        //加總所有的特殊點
        int ans = 0;
        for (int i = 0; i < gn; ++i)
            ans += past[goal[i]];

        printf("%d\n", ans);
    }

    delete[] past;
    delete[] now;
    return 0;
}