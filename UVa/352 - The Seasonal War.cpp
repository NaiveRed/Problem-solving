#include <cstdio>
#define N 25

const int dir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
bool visited[N][N];
bool pixels[N][N];
int n;

inline bool in_border(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int next_x = x + dir[i][0], next_y = y + dir[i][1];
        if (in_border(next_x, next_y) && !visited[next_x][next_y] && pixels[next_x][next_y])
        {
            visited[next_x][next_y] = true;
            dfs(next_x, next_y);
        }
    }
}
int main()
{
    int Case = 1;
    while (scanf("%d ", &n) != EOF)
    {
        char str[27];
        for (int i = 0; i < n; i++)
        {
            fgets(str, 27, stdin);
            for (int j = 0; str[j] != '\n'; j++)
                pixels[i][j] = str[j] - '0';
        }

        int count = 0;
        //for war eagle
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && pixels[i][j])
                {
                    visited[i][j] = true;
                    dfs(i, j);
                    count++;
                }
            }

        printf("Image number %d contains %d war eagles.\n", Case++, count);

        //init
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = false;
    }
    return 0;
}