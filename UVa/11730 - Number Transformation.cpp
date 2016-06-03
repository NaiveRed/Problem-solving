#include<cstdio>
#include<queue>
#define N 1001
using namespace std;

int prime[N];
int bfs(int s, int t);
int main()
{
    //建質數表
    bool notPrime[N] = { true, true };
    int s, t, i, j;
    for (i = 2; i <= 32; i++)
        for (j = i + i; j < N; j += i)
            notPrime[j] = true;
    int cp = 0;
    for (i = 2; i < N; i++)
        if (!notPrime[i])
            prime[cp++] = i;

    int Case = 0;
    while (scanf("%d%d", &s, &t) && s&&t)
    {
        printf("Case %d: ",++Case);
        if (s == t)
            puts("0");
        else
            printf("%d\n", bfs(s,t));
    }

    return 0;
}
int bfs(int s, int t)
{
    int count[1001] = {};//深度
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int p_idx = 0; prime[p_idx] < now; p_idx++)//不包含 now 自己
        {
            if (!(now%prime[p_idx]))
            {
                int temp = now + prime[p_idx];
                if (count[temp])//已經排進去過了
                    continue;

                if (temp == t)
                    return count[now] + 1;
                else if (temp < t)
                {
                    count[temp] = count[now]+1;
                    q.push(temp);
                }
                else
                    break;
            }
        }
    }

    return -1;
}