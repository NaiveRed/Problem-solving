#include<cstdio>
#include<algorithm>
#define N 26
using namespace std;

bool adjM[N][N];
int ans[8], map[N];
int solve(int n);
int main()
{
    bool isNode[N];
    char str[100];
    while (gets(str) && str[0] != '#')
    {
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
                map[idx++] = str[i] - 'A';
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

        int min = solve(idx);

        for (i = 0; i < idx; i++)
            printf("%c ", map[ans[i]] + 'A');

        printf("-> %d\n", min);
    }

    return 0;
}
int solve(int n)
{
    int order[8];
    bool next = true;
    int i, min_bw = 100;

    sort(map, map + n);
    for (i = 0; i < n; i++)
        order[i] = i;

    while (next)
    {
        int max = 0;
        for (i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (adjM[map[order[i]]][map[order[j]]] && abs(i - j) > max)
                    max = abs(i - j);

        if (max < min_bw)
        {
            min_bw = max;
            for (i = 0; i < n; i++)
                ans[i] = order[i];
        }

        next = next_permutation(order, order + n);
    }

    return min_bw;
}