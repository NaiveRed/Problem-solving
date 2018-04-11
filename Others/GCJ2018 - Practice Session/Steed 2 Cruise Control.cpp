#include <cstdio>
#include <algorithm>

struct horse
{
    int pos, sp;
    horse() {}
    horse(int p, int s) : pos(p), sp(s) {}
    bool operator<(const horse &h) const
    {
        return pos > h.pos;
    }
} H[1000];

int main()
{
    int T;
    scanf("%d", &T);

    double DP[1000] = {};
    for (int t = 1; t <= T; ++t)
    {
        int N, D, k, sp;
        scanf("%d%d", &D, &N);

        for (int i = 0; i < N; ++i)
        {
            scanf("%d%d", &k, &sp);
            H[i].pos = k;
            H[i].sp = sp;
        }

        std::sort(H, H + N); //位置從大排到小

        DP[0] = (double)(D - H[0].pos) / H[0].sp;
        for (int i = 1; i < N; ++i)
        {
            //不能超過前面的馬，所以時間一定 大於等於 前面那匹
            DP[i] = DP[i - 1];
            double dis = H[i].pos + DP[i] * H[i].sp;
            //途中都沒追到，所以用自己的速度繼續跑
            if (dis < D)
                DP[i] += (double)(D - dis) / H[i].sp;
        }

        //總距離 / 最後一群到的馬(可能一匹)所花費的時間 = 不會超車所維持的最大速度
        printf("Case #%d: %.6lf\n", t, D / DP[N - 1]);
    }

    return 0;
}