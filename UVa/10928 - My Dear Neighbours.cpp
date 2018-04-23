#include <cstdio>

int main()
{
    int N;
    char str[5000];
    scanf("%d", &N);
    while (N--)
    {
        int P;
        int ans[1000], idx = 0, min = 1000;

        scanf("%d ", &P);
        for (int i = 1; i <= P; ++i)
        {
            int count = 0; //實際數量為 count + 1
            fgets(str, 5000, stdin);
            for (int j = 0; str[j] != '\n'; ++j)
                if (str[j] == ' ') //直接用空格來判斷有幾個鄰居
                    ++count;

            if (count < min)
            {
                min = count;
                ans[idx = 0] = i;
            }
            else if (count == min)
                ans[++idx] = i;
        }

        for (int i = 0; i < idx; ++i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[idx]);
    }

    return 0;
}