#include <cstdio>
typedef long long LL;

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t)
    {
        LL k, n;
        scanf("%lld%lld", &n, &k);

        LL count = 0, row = 1;
        for (; count + row < k; row <<= 1) //找出 k 在哪一層
            count += row;

        LL remain = n - count; //剩餘位置
        LL ans = remain / row; //x0

        if (k - count <= remain % row)
            ++ans; //x1

        printf("Case #%d: %lld %lld\n", t, ans >> 1, (ans >> 1) - ((ans & 1) ? 0 : 1));
    }

    return 0;
}
/*
e.g.
16
8       7
4   3   3   3
2 1 1 1 1 1 1 1
1
能挑選的間隔成樹的形狀，計算所在的最後一層，每一層最多只會有兩個不同數字(x0, x1: x1 > x0)。
count: 已使用的 stall 數量(不含最後一層)
找出自己在那一層的第幾個: k - count，從 x1 開始放
remain: n - count，還剩多少位置
x1 的數量: remain % row(該層數量)
x0 = remain / row
x1 = x0 + 1

也可以用 priority_queue 模擬每次挑選的操作，從區間大的開始選，但無法通過大測資。
*/