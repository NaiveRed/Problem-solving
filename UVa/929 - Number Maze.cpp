#include <cstdio>
#include <queue>
#define IN(x, y, n, m) ((x) && (x) <= (n) && (y) && (y) <= (m))
#define N 1000
using namespace std;

int maze[N][N];
bool isVisit[N][N];
int d[N][N];

int dijkstra(int n, int m);
int main()
{
    int Case, i, j;
    scanf("%d", &Case);

    while (Case--)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                scanf("%d", &maze[i][j]);

        printf("%d\n", dijkstra(n, m));
    }

    return 0;
}
int dijkstra(int n, int m)
{
    struct Node
    {
        int x, y, w;
        Node(){};
        Node(int a, int b, int c) : x(a), y(b), w(c) {}
        bool operator<(const Node &a) const { return w > a.w; } //數字大的順位較低
    };

    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //上下左右

    priority_queue<Node> PQ;

    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            d[i][j] = 1e9;
            isVisit[i][j] = false;
        }

    d[1][1] = maze[1][1];
    PQ.push(Node(1, 1, d[1][1]));

    int all = n * m;
    for (i = 0; i < all; i++)
    {
        int next_x = -1, next_y = -1;

        while (!PQ.empty())
        {
            Node node = PQ.top();
            PQ.pop();
            //取出離起點最近且沒走過的點
            if (!isVisit[node.x][node.y])
            {
                next_x = node.x;
                next_y = node.y;
                break;
            }
        }

        //已經找完
        if (next_x == -1 || (next_x == n && next_y == m))
            break;

        isVisit[next_x][next_y] = true;

        //更新起點透過 (next_x,next_y) 到其他點的距離
        for (j = 0; j < 4; j++)
        {
            int x = next_x + dir[j][0], y = next_y + dir[j][1];
            if (IN(x, y, n, m))
                if (d[next_x][next_y] + maze[x][y] < d[x][y])
                {
                    d[x][y] = d[next_x][next_y] + maze[x][y];
                    PQ.push(Node(x, y, d[x][y]));
                }
        }
    }

    return d[n][m];
}