#include<cstdio>
#define N 9
#define M 11

int map[M][M];
bool isVisit[M][M];
const int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int dfs(int x, int y, int& count);//1:black,2:white,0:empty,-1:border,-2:fail
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int i, j, B, W;
        for (i = 0; i < M; i++)
            for (j = 0; j < M; j++)
                isVisit[i][j] = false;

        for (i = 0; i < M; i++)
            map[i][0] = map[i][M - 1] = map[M - 1][i] = map[0][i] = -1;
        B = W = 0;

        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
            {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
                B++;
            else if (map[i][j] == 2)
                W++;
            }

        int type;
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                int count = 0;
                if (!isVisit[i][j] && !map[i][j])
                {
                    type = dfs(i, j, count);
                    if (type == 1)
                        B += count;
                    else if (type == 2)
                        W += count;
                }
            }
        }

        printf("%d %d\n", B, W);
    }

    return 0;
}
int dfs(int x, int y, int& count)
{
    if (map[x][y])//如為有子或邊界，不須將isVisit[][]改為true，還需要它來判斷
        return map[x][y];
    else
    {
        isVisit[x][y] = true;
        bool flag = true;
        int i, c = 0, type = -1;

        for (i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if (isVisit[xx][yy])
                continue;

            int temp = dfs(xx, yy, c);

            if (type == -1)
                type = temp;
            if (temp != type&&temp != -1)//邊界不用中斷
            {
                flag = false;
                type = -2;//表此塊區域不屬於任何子
                break;
            }
        }

        if (flag)
            count += c + 1;//延伸出去的加自己

        return type;
    }

}