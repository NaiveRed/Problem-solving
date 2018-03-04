#include <cstdio>

int ans;
inline bool in_board(int x, int y)
{
    return x >= 0 && x <= 2048 && y >= 0 && y <= 2048;
}
void find(int c_x, int c_y, int k, int x, int y)
{
    //c_x, c_y: 中心點位置
    //k: 大小
    //x,y: 點的位置
    if ((x <= c_x + k && x >= c_x - k && y <= c_y + k && y >= c_y - k))
        ans++;

    int kk = k / 2;
    if (kk > 0)
    {
        if (in_board(c_x - k, c_y - k)) //左上
            find(c_x - k, c_y - k, kk, x, y);
        if (in_board(c_x + k, c_y - k)) //右上
            find(c_x + k, c_y - k, kk, x, y);
        if (in_board(c_x + k, c_y + k)) //右下
            find(c_x + k, c_y + k, kk, x, y);
        if (in_board(c_x - k, c_y + k)) //左下
            find(c_x - k, c_y + k, kk, x, y);
    }
}
int main()
{
    int k, x, y;
    while (scanf("%d%d%d", &k, &x, &y) && (x || y || k))
    {
        find(1024, 1024, k, x, y);
        printf("%3d\n", ans);
        ans = 0;
    }

    return 0;
}