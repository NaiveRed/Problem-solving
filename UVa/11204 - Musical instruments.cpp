#include <cstdio>

int main()
{
    int T;
    scanf("%d ", &T);
    while (T--)
    {
        int n, m, instruments[32] = {};
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int order;
                scanf("%d", &order);
                if (order == 1) //只需記選該種樂器為第一順位的學生數
                    instruments[j]++;
            }

        int ans = 1;
        for (int i = 0; i < n; i++)
            if (instruments[i] > 1)
                ans *= instruments[i]; // 選該樂器為第一順位的學生數

        /*
        選: 單指選為第一順位
        假設第一種樂器有 2 個人選，第二種有 3 個人，目前就有 2 x 3 種分配方法了
        */
        
        printf("%d\n", ans);
    }

    return 0;
}