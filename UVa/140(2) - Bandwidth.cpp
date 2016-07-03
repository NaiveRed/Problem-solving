#include<cstdio>
#include<algorithm>
#define N 26

int min_bw;
bool adjM[N][N], isNode[N];
int ans[8], map[N];
void dfs(int n, int now);
int main()
{
    char str[100];
    while (gets(str) && str[0] != '#')
    {
        min_bw = 1e9;
        int i = 0, idx = 0, u;
        for (i = 0; i < N; i++)
            map[i] = -1, isNode[i] = false;
        for (i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adjM[i][j] = false;

        i = 0;
        while (str[i])
        {
            u = str[i] - 'A';
            if (!isNode[u])
            {
                map[idx++] = str[i]-'A';
                isNode[u] = true;
            }

            i += 2;//':'

            while (str[i] != ';'&&str[i])
            {
                int v = str[i] - 'A';
                if (!isNode[v])
                {
                    map[idx++] = v;
                    isNode[v] = true;
                }

                adjM[u][v] = true;
                i++;
            }

            if (str[i])
                i++;
        }
        std::sort(map, map + idx);

        dfs(idx, 0);
        for (i = 0; i < idx; i++)
            printf("%c ", map[ans[i]] + 'A');

        printf("-> %d\n", min_bw);
    }

    return 0;
}
void dfs(int n, int now)
{
    static int order[8];
    static bool used[8];
    int i;

    if (!now)//init
    {
        for (i = 0; i < n; i++)
            used[i] = false;
    }

    if (now == n)
    {
        int max = 0;
        for (i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (adjM[map[order[i]]][map[order[j]]] && std::abs(i - j) > max)
                    max = std::abs(i - j);

        if (max < min_bw)
        {
            min_bw = max;
            for (i = 0; i < n; i++)
                ans[i] = order[i];
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                order[now] = i;
                dfs(n, now + 1);
                used[i] = false;
            }
        }
    }

}