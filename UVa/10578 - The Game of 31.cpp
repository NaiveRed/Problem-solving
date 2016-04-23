#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[6][6][6][6][6][6];
int num[6];
int dfs(int now);
int main()
{
    char str[25];
    int *p = dp[0][0][0][0][0];
    //init
    for (int i = 0; i < 46656; i++)
        *(p++) = -1;

    while (gets(str))
    {
        fill(num, num + 6, 0);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
            num[str[i] - '1']++;
        
        //now is A , if len is odd.Otherwise,is B
        printf("%s %c\n", str, dfs(len % 2) ? 'A' : 'B');
    }

    return 0;
}
int dfs(int now)
{
    if (num[0] * 1 + num[1] * 2 + num[2] * 3 + num[3] * 4 + num[4] * 5 + num[5] * 6 > 31)//�{�b�W�L 31 �A�]�N�O�t�@�쪱�a�|Ĺ
        return now ^ 1;
    else if (dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]] != -1)
        return dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]];

    int next = now ^ 1;//�U�@�ӽ��쪺�H
    for (int i = 0; i < 6; i++)
    {
        if (num[i] < 4)
        {
            num[i]++;
            if (dfs(next) == next)//�p�G�U�@�Ӧ��|Ĺ���A�N��{�b�o�ӷ|��
            {
                now = next;
                num[i]--;
                break;
            }
            num[i]--;
        }
    }

    return dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]] = now;//return winner
}