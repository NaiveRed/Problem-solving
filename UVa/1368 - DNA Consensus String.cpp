#include<cstdio>
#include<cstring>
#define N 50
using namespace std;

int main()
{
    int ret[20] = {};
    ret[0] = 0;//A
    ret[2] = 1;//C
    ret[6] = 2;//G
    ret[19] = 3;//T

    char DNA[4] = { 'A', 'C', 'G', 'T' };
    char str[N][1001], ans[1001];
    int Case;

    scanf("%d", &Case);
    while (Case--)
    {
        int n, m, i, j, diff = 0;
        scanf("%d%d\r", &n, &m);
        for (i = 0; i < n; i++)
            gets(str[i]);

        for (i = 0; i < m; i++)
        {
            int count[4] = {};//A,C,G,T
            for (j = 0; j < n; j++)
                count[ret[str[j][i] - 'A']]++;

            int max = 0;
            //��X�{�̦h����
            for (int k = 1; k < 4; k++)
                if (count[max] < count[k])
                {
                max = k;
                }

            ans[i] = DNA[max];
            diff += (n - count[max]);//��l���@�˪��r��
        }

        ans[i] = NULL;
        puts(ans);
        printf("%d\n", diff);
    }

    return 0;
}