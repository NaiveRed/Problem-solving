#include<cstdio>

int main()
{
    int n, ans[1001], test[1001], i;
    int game = 0;

    while (scanf("%d", &n) && n)
    {
        printf("Game %d:\n", ++game);

        for (i = 0; i < n; i++)
            scanf("%d", &ans[i]);

        while (scanf("%d", &test[0]))
        {
            for (i = 1; i < n; i++)
                scanf("%d", &test[i]);
            if (!test[0])
                break;

            int A = 0, B = 0;
            int num1[10] = {}, num2[10] = {};
            for (int idx = 0; idx < n; idx++)
            {
                if (test[idx] == ans[idx])
                    A++;
                
                //�ݦU�ӼƦr�b��ƦC���X�{������
                num1[ans[idx]]++;
                num2[test[idx]]++;
            }

            for (int j = 1; j < 10; j++)
                if (num1[j] >= num2[j])
                    B += num2[j];
                else
                    B += num1[j];
            
            //��bA�w�g��L��
            B -= A;

            printf("    (%d,%d)\n", A, B);
        }
    }
    return 0;
}
