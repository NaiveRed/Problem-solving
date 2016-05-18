#include<cstdio>
#include<queue>
using namespace std;
#define N 101
#define M -10000000

struct Room
{
    int door[N];
    int w, n;
}room[N];

bool ok[N][N];//判斷兩點是否有連通
void BFS(int n);//求出任兩點是否有連通
bool SPFA(int n);
int main()
{
    int n, i, j;
    while (scanf("%d", &n) && n != -1)
    {
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                ok[i][j] = false;

        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &room[i].w, &room[i].n);
            for (j = 0; j < room[i].n; j++)
                scanf("%d", &room[i].door[j]);
        }

        for (i = 1; i <= n; i++)
            BFS(i);

        puts(SPFA(n) ? "winnable" : "hopeless");
    }

    return 0;
}
void BFS(int n)
{
    queue<int> Q;
    Q.push(n);

    while (!Q.empty())
    {
        int idx = Q.front();
        Q.pop();
        if (ok[n][idx])
            continue;
        else
            ok[n][idx] = true;

        for (int i = 0; i < room[idx].n; i++)
            Q.push(room[idx].door[i]);
    }

}
bool SPFA(int n)
{
    bool inQ[N] = {}, cycle = false;
    int e[N] = {}, r[N] = {}, i;
    for (i = 0; i <= n; i++)
        e[i] = M;
    e[1] = 100;

    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int idx = Q.front();
        Q.pop();
        
        if (idx == n)
            return true;
        else if (r[idx] > n - 1)//產生正環
        {
            if (ok[idx][n])//如果可以從 idx 走到 n
                return true;
            else//不行的話就不用再判斷此點了
                e[idx] = 10000000;
            continue;
        }


        inQ[idx] = false;

        for (i = 0; i < room[idx].n; i++)
        {
            int k = room[idx].door[i], energy = e[idx] + room[idx].w;
            if (energy > e[k] && energy > 0)//不能為負
            {
                e[k] = energy;
                r[k] = r[idx] + 1;//紀錄最短路徑的邊數
                if (!inQ[k])
                    Q.push(k);
            }
        }
    }

    return e[n] > 0;
}