#include<cstdio>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 51

int cut[N], dp[N][N];
int solve(int left, int right, int l_idx, int r_idx);
int main()
{
    int len, n, i;
    while (scanf("%d", &len) && len)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &cut[i]);

        for (i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = 1e9;

        printf("The minimum cutting is %d.\n", solve(0, len, 0, n - 1));
    }

    return 0;
}
int solve(int left, int right, int l_idx, int r_idx)
{
    /*
    left: ���q��ҥ���
    right: ���q��ҥk��
    l_idx: ���ϥΤ������I���̥� index
    r_idx: ���ϥΤ������I���̥k index
    */

    int len = right - left;
    if (l_idx == r_idx)//�u���@�I
        return len;
    else if (l_idx > r_idx)//�S�������I
        return 0;
    else if (dp[l_idx][r_idx] != 1e9)//�w�p��L
        return dp[l_idx][r_idx];

    for (int i = l_idx; i <= r_idx; i++)
        dp[l_idx][r_idx] = MIN(dp[l_idx][r_idx], solve(left, cut[i], l_idx, i - 1) + solve(cut[i], right, i + 1, r_idx) + len);

    return dp[l_idx][r_idx];
}