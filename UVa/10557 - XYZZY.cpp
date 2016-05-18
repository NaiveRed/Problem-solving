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

bool ok[N][N];//�P�_���I�O�_���s�q
void BFS(int n);//�D�X�����I�O�_���s�q
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
        else if (r[idx] > n - 1)//���ͥ���
        {
            if (ok[idx][n])//�p�G�i�H�q idx ���� n
                return true;
            else//���檺�ܴN���ΦA�P�_���I�F
                e[idx] = 10000000;
            continue;
        }


        inQ[idx] = false;

        for (i = 0; i < room[idx].n; i++)
        {
            int k = room[idx].door[i], energy = e[idx] + room[idx].w;
            if (energy > e[k] && energy > 0)//���ର�t
            {
                e[k] = energy;
                r[k] = r[idx] + 1;//�����̵u���|�����
                if (!inQ[k])
                    Q.push(k);
            }
        }
    }

    return e[n] > 0;
}