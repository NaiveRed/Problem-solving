#include<cstdio>
#include<algorithm>
#include<stack>
#define N 100
#define M 1000
using namespace std;

int main()
{
    int i, j;
    int tape, n, CD[N], length[M], use[N][M];
    stack<int> s;

    while (scanf("%d%d", &tape, &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &CD[i]);

        //init 
        fill(length, length + tape + 1, 0);
        for (i = 0; i < n; i++)
            fill(use[i], use[i] + tape + 1, false);

        //DP
        for (i = 0; i < n; i++)
            for (j = tape; j >= CD[i]; j--)//���୫�ơA�ѤW���U��
            {
            if (length[j - CD[i]] + CD[i] > length[j])
            {
                length[j] = length[j - CD[i]] + CD[i];
                use[i][j] = true;
            }
            }

        //�f���^�h�A��X���ϥΪ�
        for (i = n - 1, j = tape; i >= 0 && j; i--)
        {
            if (use[i][j])
            {
                s.push(CD[i]);
                j -= CD[i];
            }
        }

        //����CD���ǿ�X
        while (!s.empty())
            printf("%d ", s.top()), s.pop();

        printf("sum:%d\n", length[tape]);
    }

    return 0;
}