#include<cstdio>
#include<queue>
#define N 32
using namespace std;

char map[N][N][N] = {};
const int dir[6][3] = { { 0, 0, 1 }, { 0, 1, 0 }, { 0, 0, -1 }, { 0, -1, 0 }, { 1, 0, 0 }, { -1, 0, 0 } };
struct Coord
{
    int l, r, c;
    Coord(){}
    Coord(int ll, int rr, int cc) :l(ll), r(rr), c(cc){}
};
int bfs(int l, int r, int c);
int main()
{
    int L, R, C;
    while (scanf("%d%d%d", &L, &R, &C) && L)
    {
        getchar();
        char c;
        int i, j, k, s1, s2, s3;

        //init
        for (i = 0; i <= L + 1; i++)
            for (j = 0; j <= R + 1; j++)
                for (k = 0; k <= C + 1; k++)
                    map[i][j][k] = '#';

        //input
        for (i = 1; i <= L; i++)
        {
            for (j = 1; j <= R; j++)
            {
                for (k = 1; k <= C; k++)
                {
                    c = getchar();
                    if (c == 'S')
                    {
                        s1 = i;
                        s2 = j;
                        s3 = k;
                    }

                    map[i][j][k] = c;
                }
                getchar();
            }
            getchar();
        }

        int ans = bfs(s1, s2, s3);
        if (ans)
            printf("Escaped in %d minute(s).\n", ans);
        else
            puts("Trapped!");

    }

    return 0;
}
int bfs(int l, int r, int c)
{
    queue<Coord> Q;
    Q.push(Coord(l, r, c));
    int step[N][N][N] = {};
    bool isVisit[N][N][N] = {};
    isVisit[l][r][c] = true;

    while (!Q.empty())
    {
        Coord now = Q.front();
        Q.pop();

        for (int i = 0; i < 6; i++)
        {
            int d1 = now.l + dir[i][0], d2 = now.r + dir[i][1], d3 = now.c + dir[i][2];
            if (!isVisit[d1][d2][d3])
            {
                if (map[d1][d2][d3] == '.')
                {
                    Q.push(Coord(d1, d2, d3));
                    step[d1][d2][d3] = step[now.l][now.r][now.c] + 1;
                    isVisit[d1][d2][d3] = true;//避免待會其他點也可以走到這，而重複排進 queue
                }
                else if (map[d1][d2][d3] == 'E')
                    return step[now.l][now.r][now.c] + 1;
            }
        }
    }

    return 0;
}