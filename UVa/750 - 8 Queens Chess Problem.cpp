//http://www.csie.ntnu.edu.tw/~u91029/Backtracking.html#4
#include<cstdio>
#define N 8

int ans[N] = {}, kind, must;//�� x �檺�ӦZ�b�� ans[x] �C
bool mx[N];
bool s1[15], s2[15];//�k�W�쥪�U,���W��k�U
void solve(int row, int col);
void backtracking(int col, int count);
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8\n");

        for (int i = 0; i < N; i++)
        {
            mx[i] = false;
            ans[i] = -1;
        }
        for (int i = 0; i < 15; i++)
            s1[i] = s2[i] = false;

        solve(x, y);

        if (Case)
            putchar('\n');
    }
    return 0;
}
void solve(int row, int col)
{
    kind = 0;
    //��K�p��A�̥��W�� (0,0)
    row--;
    col--;
    mx[row] = s1[row + col] = s2[col - row + 7] = true;
    ans[col] = row;
    must = col;
    backtracking(0, 0);
}
void backtracking(int col, int count)//�C���������P��
{
    if (count == N)
    {
        kind++;
        printf("%2d     ", kind);
        for (int i = 0; i < N; i++)
            printf(" %d", ans[i] + 1);
        putchar('\n');
        return;
    }
    else if (col == must)//���w��
        backtracking(col + 1, count + 1);
    else
    {
        for (int x = 0; x < N; x++)
        {
            int d1 = x + col, d2 = col - x + 7;//��X�L�̦b�ĴX���׽u(�o���Ӥ�V�����k���@��)
            if (!mx[x] && !s1[d1] && !s2[d2])
            {
                mx[x] = s1[d1] = s2[d2] = true;

                ans[col] = x;
                backtracking(col + 1, count + 1);

                mx[x] = s1[d1] = s2[d2] = false;
            }
        }
    }
}