#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    static int ele[1000000];//元素在哪個團隊
    int T, Case = 1;
    int in[1001] = {};//此團隊有幾個人已經排進去了
    queue<int> teamQ, eleQ[1001];//存團隊的順序,團隊中元素的順序

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
                if (!in[team])//這個團隊中第一個進去排隊的
                    teamQ.push(team);//將團隊排進去
                eleQ[team].push(n);//排入團隊中
                in[team]++;
            }
            else
            {
                team = teamQ.front();
                printf("%d\n", eleQ[team].front());
                eleQ[team].pop();
                in[team]--;
                if (!in[team])//此團隊已沒人在排
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