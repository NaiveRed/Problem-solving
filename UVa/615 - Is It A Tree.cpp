#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#define M 100
using namespace std;

vector<int> adjList[M];
bool BFS(int n, int root);
int main()
{
    int u, v, ref[M] = {}, Case = 1;
    map<int, int> Map;

    while (scanf("%d%d", &u, &v) && u >= 0)
    {
        int i, idx = 0;
        while (u)
        {
            if (!Map.count(u))
                Map[u] = ++idx;
            if (!Map.count(v))
                Map[v] = ++idx;

            adjList[Map[u]].push_back(Map[v]);
            ref[Map[v]]++;

            scanf("%d%d", &u, &v);
        }

        int root = -1;
        bool ans = true;
        for (i = 1; i <= idx; i++)
        {
            if (!ref[i])//���u�@�� root
            {
                if (root != -1)
                {
                    ans = false;
                    break;
                }

                root = i;
            }
            else if (ref[i] > 1)//���`�I�Q��ӥH�W���I����
            {
                ans = false;
                break;
            }
        }

        //�S������`�I�ɡA�����@�ʾ�
        if (idx)
        {
            if (root == -1)//�S��root
                ans = false;
            else if (ans)//BFS �P�_�O�_�s�q
                ans = BFS(idx, root);
        }

        printf("Case %d is%sa tree.\n", Case++, ans ? " " : " not ");

        for (i = 1; i <= idx; i++)
        {
            ref[i] = 0;
            adjList[i].clear();
        }

        Map.clear();
    }


    return 0;
}
bool BFS(int n, int root)
{
    bool isVisit[M] = {};
    queue<int> Q;
    Q.push(root);
    isVisit[root] = true;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : adjList[u])
        {
            if (!isVisit[v])
                isVisit[v] = true;
            else return false;

            Q.push(v);
        }
    }

    for (int i = 1; i <= n; i++)
        if (!isVisit[i])
            return false;

    return true;
}