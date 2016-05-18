#include<stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{
    int Case, num[100], dp[50001];
    scanf("%d", &Case);
    while (Case--)
    {
        int n, i, k, sum = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            sum += num[i];
        }

        int half = sum >> 1;
        for (i = 0; i <= half; i++)
            dp[i] = 0;

        //�q�@�b�}�l�� dp �Adp[k] ���ɥi�H��쪺�̦h���� �p�󵥩� k
        for (i = 0; i < n; i++)
            for (k = half; k >= num[i]; k--)//�����ƨϥΡAtop-down
                dp[k] = MAX(dp[k], dp[k - num[i]] + num[i]);

        printf("%d\n", (sum - dp[half]) - dp[half]);//�j�󵥩�@�b�� = sum - dp[half]�A�b� dp[half] �Y�O�ۮt���F
    }

    return 0;
}