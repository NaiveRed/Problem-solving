#include<cstdio>

const int adjList[6][5] = { {},{ 2, 3, 5 }, { 1, 3, 5 }, { 1, 2, 4, 5 }, { 3, 5 }, { 1, 2, 3, 4 } };
int order[9];
bool used[6][6];
void solve(int pre, int n)
{
    if (n == 9)
    {
        for (int i = 0; i < 9; i++)
            printf("%d", order[i]);
        putchar('\n');
    }
    else
    {
        for (int j = 0; adjList[pre][j]; j++)
        {
            if (!used[pre][adjList[pre][j]])
            {
                used[adjList[pre][j]][pre] = used[pre][adjList[pre][j]] = true;
                order[n] = adjList[pre][j];

                solve(adjList[pre][j], n + 1);

                used[adjList[pre][j]][pre] = used[pre][adjList[pre][j]] = false;
            }
        }

    }
}
int main()
{
    order[0] = 1;
    solve(1, 1);
    return 0;
}