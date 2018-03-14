#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define M 2500
using namespace std;

int main()
{
    int E;
    vector<int> adj_list[M];
    bool visited[M] = {};

    while (scanf("%d", &E) != EOF)
    {
        int n, v;
        for (int i = 0; i < E; ++i)
        {
            scanf("%d", &n);
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &v);
                adj_list[i].push_back(v);
            }
        }

        int T, src;
        scanf("%d", &T);
        while (T--)
        {
            //BFS
            scanf("%d", &src);
            int steps[M] = {}; //steps[n]: 第 n 人開始執行擴散的日期(第幾天)
            int day[M] = {};   //day[x]: 第 x 天所擴散的人數
            queue<int> Q;
            Q.push(src);
            visited[src] = true;
            steps[src] = 1;
            
            while (!Q.empty())
            {
                int now = Q.front();
                Q.pop();

                for (int v : adj_list[now])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        Q.push(v);
                        ++day[steps[now]];
                        steps[v] = steps[now] + 1;
                    }
                }
            }
            int max = 0, max_day = 0;
            for (int i = 1; day[i]; ++i)
                if (day[i] > max)
                {
                    max = day[i];
                    max_day = i;
                }

            if (max)
                printf("%d %d\n", max, max_day);
            else
                puts("0");

            memset(visited, false, sizeof(bool) * E);
            memset(day, 0, sizeof day);
        }

        //init
        for (int i = 0; i < E; i++)
            adj_list[i].clear();
    }

    return 0;
}