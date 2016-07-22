#include<cstdio>

int t, n, num[12];
bool used[12], ok;
void backtracking(int idx, int sum);
int main()
{
    while (scanf("%d%d", &t, &n) && n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            used[i] = false;
        }

        ok = false;
        printf("Sums of %d:\n", t);
        backtracking(0, 0);
        if (!ok)
            puts("NONE");
    }

    return 0;
}
void backtracking(int idx, int sum)
{
    if (sum == t)
    {
        if (!ok)
            ok = true;

        int i;
        for (i = 0; i < idx; i++)
            if (used[i])
            {
            printf("%d", num[i]);
            break;
            }

        for (i++; i < idx; i++)
            if (used[i])
                printf("+%d", num[i]);
        putchar('\n');

        return;
    }
    else if (idx == n)
        return;

    int last = 0;
    for (; idx < n; idx++)
    {
        if (last == num[idx])//避免重複的組合，只要沒有選上個一樣的，接下來也都不選同個數字
            continue;

        if (sum + num[idx] <= t)
        {
            used[idx] = true;
            backtracking(idx + 1, sum + num[idx]);
        }

        used[idx] = false;
        last = num[idx];
    }
}