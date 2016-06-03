#include<cstdio>
#include<algorithm>
#define N 1<<16
using namespace std;

int main()
{
    long long dp[N];//��e���X������
    int state[N];//��e�����Ѫ����X
    int Case;
    char str[17];

    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int n, i, j;
        int robot[17] = {};//0 �� mega buster,��l�����Ѧ� robot[] ��A�i�H���˪���L robot ���X

        scanf("%d", &n);
        getchar();
        fill(state, state + (1 << n), 0);
        fill(dp, dp + (1 << n), 0);

        for (i = 0; i <= n; i++)
        {
            gets(str);
            //���Ĥ@�Ӧs�b LSB
            int r = 1;
            for (j = 0; j < n; j++)
            {
                if (str[j] == '1')
                    robot[i] |= r;
                r <<= 1;
            }
        }

        //init
        state[0] = robot[0];
        dp[0] = 1;

        int all = 1 << n;//�������զX
        for (i = 0; i < all; i++)
        {
            /*
            i = ����e�w����(���X)
            ~i = �h���٨S����
            state[i] = ��e���X�i�H����
            */
            int ok = (~i)&state[i];//�����B�i����
            
            //��ܭn���˭���
            int r = 1;
            for (j = 1; j <= n; j++)
            {
                if (ok&r)
                {
                    /*
                    r | i �����˧��᪺���X
                    */
                    dp[r | i] += dp[i];//���ƭp��
                    //���˧��᪺ state ���X �A�ܦ� "�����˫e��" �[�W(or) "���˫�~�i�H��"
                    state[r | i] = state[i] | robot[j];
                }

                r <<= 1;//���U�@��
            }
        }

        printf("Case %d: %lld\n", c, dp[all - 1]);
    }

    return 0;
}