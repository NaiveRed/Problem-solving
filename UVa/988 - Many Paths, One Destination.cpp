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
                death[count++] = i;//���`
            else
                for (j = 0; j < n; j++)
                {
                scanf("%d", &k);
                v[i].push_back(k);
                Ref[k]++;//���h�֫��V K ����
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

    //�_�I����0�Өƥ�
    Q.push(0);
    Ref[0] = -1;

    int dp[N] = { 1 };

    while (!Q.empty())
    {
        int next = Q.front();
        Q.pop();

        for (int k : v[next])
        {
            //�]���w�S����������V next �F�A�� k ����k�h�[�W �� next ����k��(next �i�H�� k)
            dp[k] += dp[next];

            //��s Ref
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
    
    //���U���`�ƥ󪺨��k�ۥ[�Y������
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += dp[death[i]];

    return sum;
}