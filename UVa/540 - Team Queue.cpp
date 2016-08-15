#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    static int ele[1000000];//�����b���ӹζ�
    int T, Case = 1;
    int in[1001] = {};//���ζ����X�ӤH�w�g�ƶi�h�F
    queue<int> teamQ, eleQ[1001];//�s�ζ�������,�ζ�������������

    while (scanf("%d", &T) && T)
    {
        int i, n, temp;
        for (i = 1; i <= T; i++)
        {
            scanf("%d", &temp);
            for (int j = 0; j < temp; j++)
            {
                scanf("%d", &n);
                ele[n] = i;
            }
        }

        char str[10];
        printf("Scenario #%d\n", Case++);
        while (scanf("%s", &str) && str[0] != 'S')
        {
            int team;
            if (str[0] == 'E')
            {
                scanf("%d", &n);
                team = ele[n];
                if (!in[team])//�o�ӹζ����Ĥ@�Ӷi�h�ƶ���
                    teamQ.push(team);//�N�ζ��ƶi�h
                eleQ[team].push(n);//�ƤJ�ζ���
                in[team]++;
            }
            else
            {
                team = teamQ.front();
                printf("%d\n", eleQ[team].front());
                eleQ[team].pop();
                in[team]--;
                if (!in[team])//���ζ��w�S�H�b��
                    teamQ.pop();
            }
        }

        putchar('\n');
        
        //init
        for (i = 0; i <= T; i++)
            in[i] = 0;
        for (i = 0; i <= T; i++)
            while (!eleQ[i].empty())
                eleQ[i].pop();
        while (!teamQ.empty())
            teamQ.pop();
    }

    return 0;
}