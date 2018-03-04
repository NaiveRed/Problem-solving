#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int W[100][100];     //-1: 'L', 0: not visited, >=1: area of the lake
char grid[101][100]; //從(0, 0)開始存

int DFS(int r, int c)
{
    stack<pair<int, int>> s;
    vector<pair<int, int>> rec;
    s.push(make_pair(r, c));
    rec.push_back(make_pair(r, c));

    int count = 1;
    W[r][c] = 1; //visited
    while (!s.empty())
    {
        r = s.top().first;
        c = s.top().second;
        s.pop();

        for (int i = 0; i < 8; ++i)
        {
            int rr = r + dir[i][0], cc = c + dir[i][1];
            if (rr >= 0 && cc >= 0 && grid[rr][cc] == 'W' && !W[rr][cc])
            {
                ++count;
                pair<int, int> p(rr, cc);
                rec.push_back(p);
                s.push(p);
                W[rr][cc] = 1; //visited
            }
        }
    }

    //把剛經過的 water 都填上總面積
    for (int i = 0; i < count; ++i)
        W[rec[i].first][rec[i].second] = count;

    return count;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int Case;
    char str[105];
    scanf("%d ", &Case);
    while (Case--)
    {
        int r = 0, c;
        fgets(str, 105, stdin);
        strncpy(grid[0], str, c = strlen(str) - 1); //"...\n\0"
        grid[0][c] = '\0';

        while (fgets(str, 105, stdin) && (str[0] == 'L' || str[0] == 'W'))
        {
            strncpy(grid[++r], str, c);
            grid[r][c] = '\0';
        }
        memset(grid[r + 1], '\0', sizeof grid[r + 1]); //補上最下方的邊界

        //init
        for (int i = 0; i <= r; ++i)
            memset(W[i], 0, sizeof W[i]);

        //先處理剛已經讀進去的座標
        do
        {
            sscanf(str, "%d%d", &r, &c);
            --r;
            --c;

            if (grid[r][c] == 'W')
                printf("%d\n", W[r][c] ? W[r][c] : DFS(r, c));
            else
            {
                W[r][c] = -1;
                puts("0");
            }

        } while (fgets(str, 105, stdin) && str[0] != '\n');

        if (Case)
            putchar('\n');
    }

    return 0;
}