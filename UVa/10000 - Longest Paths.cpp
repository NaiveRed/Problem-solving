#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<int> adjList[101];
pair<int, int> SPFA(int s, int tar);
void path(int n, int now);
int main()
{
    int n, s, Case = 1;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i <= n; i++)
            adjList[i].clear();

        scanf("%d", &s);
        int v1, v2, count = 0;
        while (scanf("%d%d", &v1, &v2) && v1 && v2)
            adjList[v1].push_back(v2);

        pair<int, int> ans = SPFA(s, n);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", Case++, s, ans.first, ans.second);
    }

    return 0;
}
pair<int, int> SPFA(int s, int n)
{
    int d[101] = {};
    bool inQ[101] = {};
    int parent[101] = {};
    queue<int> Q;
    Q.push(s);
    parent[s] = s;

    while (!Q.empty())
    {
        int next = Q.front();
        Q.pop();
           
        inQ[next] = false;

        for (auto i : adjList[next])
        {    
            if (d[next] + 1 > d[i])
            {   
                d[i] = d[next] + 1;
                if (!inQ[i])
                {
                    Q.push(i);
                    inQ[i] = true;
                }
            }
        }
    }

    //找出經過的點最多的
    int max = 0, tar;
    for (int i = 1; i <= n; i++)
        if (max < d[i])
        {
        max = d[i];
        tar = i;
        }

    return make_pair(max, tar);
}
