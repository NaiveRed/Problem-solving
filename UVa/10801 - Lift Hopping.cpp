#include<cstdio>
#include<queue>
#include<algorithm>
#define N 101
using namespace std;

bool lift[5][N];//[lift][floor]
int t[5];//移動不同樓層的時間
int dijkstra(int tar, int n);
int main()
{
    int n, tar;

    while (scanf("%d%d", &n, &tar) != EOF)
    {
        int  i;
        //init
        for (i = 0; i < 5; i++)
            fill(lift[i], lift[i] + N, false);

        for (i = 0; i < n; i++)
            scanf("%d", &t[i]);

        //input
        getchar();
        char str[300];
        for (i = 0; i < n; i++)
        {
            int temp = 0;
            gets(str);
            for (int j = 0; str[j]; j++)
            {
                if (str[j] == ' ')
                {
                    lift[i][temp] = true;
                    temp = 0;
                }
                else
                    temp = temp * 10 + str[j] - '0';
            }
            lift[i][temp] = true;
        }


        int ans = dijkstra(tar, n);
        if (ans == -1)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", ans);
    }

    return 0;
}
int dijkstra(int tar, int n)
{
    int i, j;
    struct Floor
    {
        int id, n, t;
        Floor(){}
        Floor(int _id, int _n, int _t) :id(_id), n(_n), t(_t){}
        bool operator<(const Floor& a)const{ return t>a.t; }//耗時少的較優先
    };

    bool isVisit[5][N] = {};//[lift][floor]
    int T[5][N];//從 0 層到各樓層所需的時間，不同電梯在同樓層的時間也不相同
    priority_queue<Floor> PQ;
    Floor next;
    //init
    for (i = 0; i < 5; i++)
        fill(T[i], T[i] + N, 1e9);

    //有到達 0 層的電梯
    for (i = 0; i < n; i++)
        if (lift[i][0])
        {
        T[i][0] = 0;
        PQ.push(Floor(i, 0, 0));
        }

    while (true)
    {
        next.id = -1;
        while (!PQ.empty())
        {
            next = PQ.top();
            PQ.pop();
            if (!isVisit[next.id][next.n])
                break;
        }

        isVisit[next.id][next.n] = true;
        if (next.id == -1 || next.n == tar)
            break;

        //更新 next 到同樓層不同電梯的可能最短時間
        for (j = 0; j < n; j++)
        {
            if (lift[j][next.n] && !isVisit[j][next.n])
                if (next.t + 60 < T[j][next.n])
                {
                T[j][next.n] = next.t + 60;
                PQ.push(Floor(j, next.n, T[j][next.n]));
                }
        }

        //更新 next 到同電梯不同樓層的可能最短時間
        for (j = 0; j < N; j++)
        {
            if (lift[next.id][j] && !isVisit[next.id][j])
            {
                //時間計算
                int time = t[next.id] * (j - next.n);
                if (time < 0)
                    time *= -1;

                if (next.t + time < T[next.id][j])
                {
                    T[next.id][j] = next.t + time;
                    PQ.push(Floor(next.id, j, T[next.id][j]));
                }
            }
        }
    }

    return next.n == tar ? next.t : -1;
}