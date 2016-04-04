#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define N 100
using namespace std;

int death[N];
int Ref[N];
vector<int> v[N];
int topo(int count);
int main()
{
    bool first = true;
    int event;
    while (scanf("%d", &event) != EOF)
    {
        int n, i, j, k;
        int count = 0;
        //init
        fill(death, death + event, 0);
        fill(Ref, Ref + event, 0);
        for (i = 0; i < event; i++)
            v[i].clear();

        for (i = 0; i < event; i++)
        {
            scanf("%d", &n);
            if (!n)
                death[count++] = i;//死亡
            else
                for (j = 0; j < n; j++)
                {
                scanf("%d", &k);
                v[i].push_back(k);
                Ref[k]++;//有多少指向 K 的邊
                }
        }

        if (!first)
            putchar('\n');
        else
            first = false;

        printf("%d\n", topo(count));
    }

    return 0;
}
int topo(int count)
{
    queue<int> Q;

    //起點為第0個事件
    Q.push(0);
    Ref[0] = -1;

    int dp[N] = { 1 };

    while (!Q.empty())
    {
        int next = Q.front();
        Q.pop();

        for (int k : v[next])
        {
            //因為已沒有任何邊指向 next 了，到 k 的方法多加上 到 next 的方法數(next 可以到 k)
            dp[k] += dp[next];

            //更新 Ref
            if (Ref[k] != -1)
            {
                Ref[k]--;
                if (!Ref[k])
                {
                    Q.push(k);
                    Ref[k] = -1;
                }
            }
        }
    }
    
    //把到各死亡事件的走法相加即為答案
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += dp[death[i]];

    return sum;
}