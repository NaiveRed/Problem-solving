#include<cstdio>
#include<vector>
#include<deque>
#define N 51
using namespace std;

vector<int> adjList[N];
deque<int>ans;
int now[N];//[x],x ����w�i�������F
int edgeNum[N][N];//���I��������ơC�����|���ƺ�
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

            //����
            adjList[c1].push_back(c2);
            adjList[c2].push_back(c1);

            //�p����I���������
            edgeNum[c1][c2]++;
            edgeNum[c2][c1]++;

            deg[c1]++;
            deg[c2]++;

            E++;
        }

        //�P�_�䪺 degree �O�_������
        for (i = 1; i <= count; i++)
            if (deg[i] & 1)
                break;

        printf("Case #%d\n", c);
        if (i <= count)
            puts("some beads may be lost");
        else
        {
            findEuler(count);//�q�̫�@�I�}�l
            int size = ans.size();
            if (size / 2 != E)//�Ϥ��s�q
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
        else//x �s�� y ���Ҧ��䳣���L�F�A�ݷ|�A�J�� x �N�i�q�U�@���I�}�l���F�C
            now[x]++;
    }
}