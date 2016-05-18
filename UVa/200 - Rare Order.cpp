//topological�A�O�o�n����....
#include<cstdio>
#include<queue>
#define N 26
using namespace std;

int main()
{
    int i, j;
    bool adjM[N][N] = {}, one = true;
    char *str1 = new char[21], *str2 = new char[21];

    gets(str1);
    while (gets(str2) && str2[0] != '#')
    {
        one = false;
        for (i = 0; str1[i] == str2[i] && str1[i]; i++);

        if (str1[i] && str2[i])
            adjM[str1[i] - 'A'][str2[i] - 'A'] = true;

        //�ĤG�Ӵ����e����
        char *p = str1;
        str1 = str2;
        str2 = p;
    }

    if (!one)
    {
        bool used[N] = {};
        int ref[N] = {};//���V���I����
        queue < int > Q;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (adjM[i][j])
                {
            used[i] = used[j] = true;//�O���o���I���Q�Ψ�
            ref[j]++;//���V j ���I�W�[
                }

        for (i = 0; i < N; i++)
            if (used[i] && !ref[i])
            {
            Q.push(i);
            break;
            }

        while (!Q.empty())
        {
            int next = Q.front();
            Q.pop();
            putchar('A' + next);
            for (i = 0; i < N; i++)
                if (used[i] && adjM[next][i])
                {
                ref[i]--;
                if (!ref[i])
                    Q.push(i);
                }
        }
    }
    else
        putchar(str1[0]);

    putchar('\n');

    return 0;
}