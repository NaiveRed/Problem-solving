#include<cstdio>
#include<utility>
#include<queue>
#define N 102
using namespace std;
typedef pair<int, int> Pair;

bool isVisit[N][N];
char grid[N][N];
int BFS(int i, int j);
const int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int main()
{
    int n, i, j;
    Pair one[10000];
    while (scanf("%d", &n) != EOF)
    {
        getchar();
        //init border
        for (i = 0; i <= n + 1; i++)
            grid[0][i] = grid[i][0] = grid[n + 1][i] = grid[i][n + 1] = '\0';

        int s = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                grid[i][j] = getchar();
                if (grid[i][j] == '1')
                    one[s].first = i, one[s++].second = j;
            }
            getchar();
        }

        int max = 0,temp;
        for (i = 0; i < s; i++)
        {
            temp = BFS(one[i].first, one[i].second);

            if (temp > max)
                max = temp;

            for (int k = 0; k <= n + 1; k++)
                for (j = 0; j <= n + 1; j++)
                    isVisit[k][j] = false;
        }

        printf("%d\n", max);
            
    }

    return 0;
}
int BFS(int i, int j)
{
    queue<Pair> Q;
    Pair now = { i, j };
    int dis[N][N] = {};
    
    Q.push(now);
    
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            Pair next = { now.first + dir[i][0], now.second + dir[i][1] };
            if (grid[next.first][next.second] && !isVisit[next.first][next.second])
            {
                dis[next.first][next.second] = dis[now.first][now.second] + 1;
                if (grid[next.first][next.second] == '3')
                    return dis[next.first][next.second];
                isVisit[next.first][next.second] = true;
                Q.push(next);
            }
        }
    }

    return 0;
}