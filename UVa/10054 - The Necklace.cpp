#include<cstdio>
#include<vector>
#include<deque>
#define N 51
using namespace std;

vector<int> adjList[N];
deque<int>ans;
int now[N];//[x],x 的邊已進行到哪條了
int edgeNum[N][N];//兩點之間的邊數。自環會重複算
void findEuler(int x);
int main()
{
    int Case;
    scanf("%d", &Case);
    for (int c = 1; c <= Case; c++)
    {
        if (c != 1)
            putchar('\n');
        //---init---
        int n, i, c1, c2, E = 0, count = 0;
        int deg[N] = {}, map[N] = {}, reMap[N] = {};
        for (i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                edgeNum[i][j] = 0;
        for (i = 0; i < N; i++)
            now[i] = 0;
        for (i = 0; i < N; i++)
            adjList[i].clear();
        ans.clear();
        //---

        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &c1, &c2);

            if (!map[c1])
            {
                map[c1] = ++count;
                reMap[map[c1]] = c1;
            }
            if (!map[c2])
            {
                map[c2] = ++count;
                reMap[map[c2]] = c2;
            }

            c1 = map[c1];
            c2 = map[c2];

            //建邊
            adjList[c1].push_back(c2);
            adjList[c2].push_back(c1);

            //計算兩點之間的邊數
            edgeNum[c1][c2]++;
            edgeNum[c2][c1]++;

            deg[c1]++;
            deg[c2]++;

            E++;
        }

        //判斷邊的 degree 是否為偶數
        for (i = 1; i <= count; i++)
            if (deg[i] & 1)
                break;

        printf("Case #%d\n", c);
        if (i <= count)
            puts("some beads may be lost");
        else
        {
            findEuler(count);//從最後一點開始
            int size = ans.size();
            if (size / 2 != E)//圖不連通
                puts("some beads may be lost");
            else
                for (i = 0; i < size; i += 2)
                    printf("%d %d\n", reMap[ans[i]], reMap[ans[i + 1]]);
        }
    }

    return 0;
}
void findEuler(int x)
{
    int size = adjList[x].size();
    for (int v = now[x]; v < size; v++)
    {
        int next = adjList[x][v];
        if (edgeNum[x][next])
        {
            edgeNum[x][next]--;
            edgeNum[next][x]--;

            findEuler(next);

            //x -> next
            ans.push_front(next);
            ans.push_front(x);
        }
        else//x 連到 y 的所有邊都走過了，待會再遇到 x 就可從下一個點開始走了。
            now[x]++;
    }
}