#include<cstdio>

int main()
{
    int Case, ans[100] = {};
    scanf("%d", &Case);
    while (Case--)
    {
        int n, i;
        scanf("%d", &n);
        int sum = 0, count = 0;
        //��������2,3,4,... �A���n�W�L n
        while (true)
        {
            ans[count] = count + 2;
            if (sum + ans[count] <= n)
                sum += ans[count++];
            else break;
        }

        int diff = n - sum;
        for (i = count - 1; diff; diff--)
        {
            //�ۮt���q�᭱�̧ǥ[�@(�`��)�A�����`�X�� n
            ans[i]++;
            sum++;
            i--;
            if (i < 0)
                i = count - 1;
        }

        for (i = 0; i < count - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[i]);
        if (Case)
            putchar('\n');
    }

    return 0;
}