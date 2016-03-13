#include<cstdio>
#include<queue>
#define IN_BORDER(R,C,x,y) ((x)>0&&(x)<=(R)&&(y)>0&&(y)<=(C))

struct Coord
{
    int x, y;
    Coord(){}
    Coord(int _x, int _y) :x(_x), y(_y){}
};
char maze[1001][1001];
int path[1001][1001];
std::queue<Coord> manQ, fireQ;

int BFS(int R, int C);
int main()
{
    int Case, R, C;
    scanf("%d", &Case);

    while (Case--)
    {
        scanf("%d%d", &R, &C);

        //init
        int i;
        for (i = 0; i <= R; i++)
            for (int j = 0; j <= C; j++)
                path[i][j] = 0;
        while (!manQ.empty())
            manQ.pop();
        while (!fireQ.empty())
            fireQ.pop();

        //input
        for (int i = 1; i <= R; i++)
        {
            getchar();
            for (int j = 1; j <= C; j++)
            {
                maze[i][j] = getchar();
                if (maze[i][j] == 'F')
                {
                    fireQ.push(Coord(i, j));
                    path[i][j] = -1;
                }
                else if (maze[i][j] == '#')
                    path[i][j] = -1;
                else if (maze[i][j] == 'J')
                {
                    manQ.push(Coord(i, j));
                    path[i][j] = 1;
                }
            }
        }

        int ans = BFS(R, C);
        if (ans == -1)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", ans);
    }

    return 0;
}
int BFS(int R, int C)
{
    const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    int time, i;
    while (!manQ.empty())
    {
        Coord now;
        int x, y;
        //先處理火
        if (!fireQ.empty())
        {
            now = fireQ.front();
            /*
            同一時間的一起處理好
            火的時間為:-1,-2,-3....
            */
            for (time = path[now.x][now.y]; time == path[now.x][now.y]; now = fireQ.front())
            {
                fireQ.pop();
                for (i = 0; i < 4; i++)
                {
                    x = now.x + dir[i][0];
                    y = now.y + dir[i][1];
                    if (IN_BORDER(R, C, x, y))
                        if (!path[x][y] && maze[x][y] == '.')
                        {
                        path[x][y] = path[now.x][now.y] - 1;
                        fireQ.push(Coord(x,y));
                        }
                }

                if (fireQ.empty())
                    break;
            }
        }

        //人的位置
        now = manQ.front();
        /*
        同一時間人可到的位置
        人的時間為:1,2,3...
        */
        for (time = path[now.x][now.y]; time == path[now.x][now.y]; now = manQ.front())
        {
            if (now.x == R || now.y == C || now.x == 1 || now.y == 1)//已經到邊界了
                return  path[now.x][now.y];

            manQ.pop();
            for (i = 0; i < 4; i++)
            {
                x = now.x + dir[i][0];
                y = now.y + dir[i][1];
                if (IN_BORDER(R, C, x, y))
                    if (!path[x][y] && maze[x][y] == '.')
                    {
                    path[x][y] = path[now.x][now.y] + 1;
                    manQ.push(Coord(x, y));
                    }
            }

            if (manQ.empty())
                break;
        }

#ifdef DEBUG     
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
                printf("%2d", path[i][j]);
            putchar('\n');
        }
        putchar('\n');
#endif

    }

    return -1;
}