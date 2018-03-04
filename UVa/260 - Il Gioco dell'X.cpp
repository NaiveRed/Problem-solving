#include <cstdio>
#include <cstring>
#include <stack>
#include <utility>
#define N 202
using namespace std;

const int dir[6][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
char board[N][N];
bool visited[N][N];
int n;
inline bool in_board(int x, int y)
{
    return (x && y && x < n && y < n);
}
/*recursive version
bool dfs(int x, int y)
{

    for (int i = 0; i < 6; i++)
    {
        int next_x = x + dir[i][0], next_y = y + dir[i][1];

        if (in_board(next_x, next_y) && board[next_x][next_y] == 'b' && !visited[next_x][next_y])
        {
            visited[next_x][next_y] = true;
            if (next_x == n - 1 || dfs(next_x, next_y))
                return true;
        }
    }

    return false;
}*/
bool dfs(int x, int y)
{
    stack<pair<int, int>> s;
    s.push(make_pair(x, y));

    while (!s.empty())
    {
        x = s.top().first;
        y = s.top().second;
        s.pop();

        for (int i = 0; i < 6; i++)
        {
            int next_x = x + dir[i][0], next_y = y + dir[i][1];

            if (in_board(next_x, next_y) && board[next_x][next_y] == 'b' && !visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                if (next_x == n - 1) //goal
                    return true;
                else
                    s.push(make_pair(next_x, next_y));
            }
        }
    }

    return false;
}
int main()
{    
    int Case = 0;

    while (scanf("%d ", &n) && n)
    {
        for (int i = 0; i < n; i++)
            fgets(board[i], N, stdin);

        bool black_win = false;
        //Use black to DFS, since there is only one winner.
        for (int i = 0; i < n; i++)
        {
            if (!visited[0][i] && board[0][i] == 'b')
            {
                visited[0][i] = true;
                if (dfs(0, i))
                {
                    black_win = true;
                    break;
                }
            }
        }

        printf("%d %c\n", ++Case, black_win ? 'B' : 'W');

        for (int i = 0; i < n; i++)
            memset(visited[i], false, sizeof visited[i]);
    }

    return 0;
}