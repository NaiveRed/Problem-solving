#include <cstdio>
#include <cstring>
#include <queue>
#define N 21

bool M[N][N];
int d[N][N];
inline int input()
{
    char c;
    int n = 0;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
void BFS(int s)
{
    std::queue<int> Q;
    bool visited[N] = {};
    Q.push(s);
    visited[s] = true;

    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();

        for (int i = 1; i < N; ++i)
            if (M[now][i] && !visited[i])
            {
                d[s][i] = d[i][s] = d[s][now] + 1;                
                Q.push(i);
                visited[i] = true;
            }
    }
}
int main()
{
    //freopen("test.out", "w", stdout);
    int n, Case = 1;

    while (scanf("%d", &n) != EOF)
    {
        getchar();
        int u = 1, v;

        while (true)
        {
            for (int i = 0; i < n; ++i)
            {
                v = input();
                M[u][v] = true;
                M[v][u] = true;
            }

            if (++u < N - 1)
                n = input();
            else
                break;
        }

        printf("Test Set #%d\n", Case++);
        scanf("%d ", &n);        
        for (int i = 0; i < n; ++i)
        {
            u = input();
            v = input();
            if (!d[u][v]) //u!=v 且 所有國家間都至少有一條路徑
                BFS(u);

            printf("%2d to %2d:%2d\n", u, v, d[u][v]);
        }

        putchar('\n');

        for (int i = 1; i < N; ++i)
        {
            memset(M[i], 0, sizeof M[i]);
            memset(d[i], 0, sizeof d[i]);
        }
    }
}