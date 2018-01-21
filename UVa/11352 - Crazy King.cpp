#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#define SIZE 100
using namespace std;
typedef pair<int, int> Node;

const int dir_king[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
const int dir_h[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int M, N;
int map[SIZE][SIZE];
int visit[SIZE][SIZE];

bool in_board(int r, int c);
bool is_safe(int r, int c);
int bfs(int r, int c);
int main()
{    
    int T;
    scanf("%d", &T);
     while (T--)
    {
        char c;
        Node A;
        scanf("%d%d", &M, &N);
        getchar();
        //0:'.', 1: 'A', 2:'B', 3:'Z'
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {

                if ((c = getchar()) == '.')
                    map[i][j] = 0;
                else if (c == 'Z')
                    map[i][j] = 3;
                else if (c == 'A')
                {
                    map[i][j] = 1;
                    A.first = i;
                    A.second = j;
                }
                else //'B'
                    map[i][j] = 2;
            }

            getchar();
        }

        memset(visit, 0, sizeof visit);
        int ans = bfs(A.first, A.second);
        if (ans)
            printf("Minimal possible length of a trip is %d\n", ans);
        else
            puts("King Peter, you can't go now!");
    }

    return 0;
}
inline bool in_board(int r, int c)
{
    return (r >= 0 && c >= 0 && r < M && c < N);
}
inline bool is_safe(int r, int c)
{
    if (map[r][c] == 3)
        return false;

    for (int i = 0; i < 8; i++)
    {
        int rr = r + dir_h[i][0], cc = c + dir_h[i][1];
        if (in_board(rr, cc) && map[rr][cc]==3)
            return false;
    }

    return true;
}
int bfs(int r, int c)
{
    queue<Node> q;
    q.push(make_pair(r, c));
    visit[r][c] = 1;

    while (!q.empty())
    {
        Node n = q.front();
        q.pop();
        r = n.first;
        c = n.second;

        for (int i = 0; i < 8; i++)
        {
            int rr = r + dir_king[i][0], cc = c + dir_king[i][1];
            if (in_board(rr, cc) && !visit[rr][cc])
            {
                if (map[rr][cc] == 2)
                    return visit[r][c]; //無須再加 1, 一開始就先多一步了
                else if (is_safe(rr, cc))
                {
                    q.push(make_pair(rr, cc));
                    visit[rr][cc] = visit[r][c] + 1;
                }
            }
        }
    }

    return 0;
}