/*
事件相對順序不等於答案相對順序，要再做處理
輸入為各事件的時間:
ex.
n = 5
input: 3 1 2 5 4

事件 1 2 3 4 5
時間 3 1 2 5 4

所以事件的發生順序為: 2 3 1 5 4
用LCS解
*/
#include<cstdio>
#include<cstring>
#define N 21
#define MAX(a,b) ((a)>(b)?(a):(b))

int LCS(int *s1, int *s2);
int main()
{
    int ans[N] = {}, student[N] = {}, n, i;

    //事件為 1~n
    scanf("%d", &n);

    int rank;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &rank);
        ans[rank] = i;//第 i 個事件的順序為 rank
    }

    while (scanf("%d", &rank) != EOF)
    {
        student[rank] = 1;
        for (i = 2; i <= n; i++)
        {
            scanf("%d", &rank);
            student[rank] = i;
        }

        printf("%d\n", LCS(ans, student));
        memset(student, 0, sizeof(student));
    }

    return 0;
}
int LCS(int *s1, int *s2)
{
    int DP[N][N], i, j;
    int len1, len2;

    memset(DP, 0, sizeof(DP));
    //事件不會有0
    for (i = 1; s1[i]; i++);
    len1 = i - 1;

    for (i = 1; s2[i]; i++);
    len2 = i - 1;

    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
        if (s1[i] == s2[j])
            DP[i][j] = DP[i - 1][j - 1] + 1;
        else
            DP[i][j] = MAX(DP[i - 1][j], DP[i][j - 1]);
        }

    return DP[len1][len2];
}