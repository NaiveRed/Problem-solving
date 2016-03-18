#include<cstdio>
#include<deque>
#define N 101
using namespace std;

deque<int> DQ[N];
void topo(int n);
int main()
{
    int n, i, j;
    while (scanf("%d", &n) && n)
    {
        for (i = 1; i <= n; i++)
            DQ[i].clear();

        int m, a, b;
        scanf("%d", &m);
        for (j = 0; j < m; j++)
        {
            scanf("%d%d", &a, &b);
            DQ[a].push_back(b);
        }

        topo(n);
    }

    return 0;
}
void topo(int n)
{
    int ref[N] = {}, i;
    //計算每個點，有幾個指向他
    for (i = 1; i <= n; i++)
        for (int j : DQ[i])
            ref[j]++;

    deque<int> Q;
    //將沒有被指的放進 queue ，也就是可以先做的事
    for (i = 1; i <= n; i++)
    {
        if (!ref[i])
            Q.push_back(i);
    }

    bool first = true;
    while (!Q.empty())
    {
        if (!first)
            putchar(' ');
        else
            first = false;

        int s = Q.front();
        Q.pop_front();

        ref[s] = -1;
        printf("%d", s);
        //將 s 所指的點都減 1
        for (int j : DQ[s])
        {
            ref[j]--;
            if (!ref[j])
                Q.push_back(j);
        }

    }

    putchar('\n');
}