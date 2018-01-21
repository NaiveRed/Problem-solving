#include <cstdio>
#include <cstring>

struct Vote
{
    int v[20], order; //候選人順序, 目前的順位
};
inline int get_vote()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' ' && c != '\n' && c != EOF)
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int Case;
    char name[20][100];
    int cand_list[20] = {};
    Vote vote[1001];

    scanf("%d", &Case);
    getchar();
    while (Case--)
    {
        int n, i;
        scanf("%d", &n);
        getchar();
        for (i = 0; i < n; i++)
        {
            fgets(name[i], 100, stdin);
            name[i][strlen(name[i]) - 1] = NULL;
        }

        int idx = 0; //選民
        while (vote[idx].v[0] = get_vote())
        {
            cand_list[--vote[idx].v[0]]++; // 第一順位的
            for (i = 1; i < n; i++)
                vote[idx].v[i] = get_vote() - 1;
            idx++;
        }

        for (i = 0; i < idx; i++)
            vote[i].order = 0; //都從第一順位開始

        int half = (idx / 2), win = -1;
        int max = -9999, min = 9999;

        while (true)
        {

            for (i = 0; i < n; i++)
            {
                if (cand_list[i] == -1) //已被淘汰
                    continue;

                if (max < cand_list[i])
                {
                    max = cand_list[i];
                    win = i;
                }

                if (min > cand_list[i])
                    min = cand_list[i];
            }

            if (max == min || max > half)
                break;
            else
            {
                for (i = 0; i < n; i++) //票數最少的所有候選人將被排除
                    if (cand_list[i] == min)
                        cand_list[i] = -1;

                // 投票者的當前順位是被排除者的話, 移到下一順位
                for (i = 0; i < idx; i++)
                {
                    int &order = vote[i].order;  //順位
                    int cand = vote[i].v[order]; //該順位候選人
                    if (cand_list[cand] == -1)
                    {
                        while (cand_list[cand] == -1)
                        {
                            order++;
                            cand = vote[i].v[order];
                        }

                        cand_list[cand]++;
                    }
                }
            }

            max = -9999, min = 9999;
        }

        if (max == min)
        {
            for (i = 0; i < n; i++)
                if (cand_list[i] != -1) //已被淘汰
                    puts(name[i]);
        }
        else
            puts(name[win]);

        if (Case)
            putchar('\n');

        //init
        memset(cand_list, 0, sizeof cand_list);
    }

    return 0;
}