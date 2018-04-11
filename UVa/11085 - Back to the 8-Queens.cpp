#include <cstdio>
#define LEFT(r, c) ((r) + (c))
#define RIGHT(r, c) (7 + (c) - (r))

int correct_row[100][8] = {}, tmp[8]; //[][col]: 第 col 行的棋子在第幾 row
int no;

//左上角為 (0, 0)
bool left[15];  //左下到右上的斜線，左上那條為 [0]
bool right[15]; //左上到右下的斜線，左下那條為 [0]，最長那條為 [7]
bool row[8];

void backtracking(int col)
{
    if (col == 8)
    {
        for (int i = 0; i < 8; ++i)
            correct_row[no][i] = tmp[i] + 1;

        ++no;
        return;
    }

    for (int i = 0; i < 8; ++i) //row
    {
        if (!row[i] && !left[LEFT(i, col)] && !right[RIGHT(i, col)])
        {
            row[i] = left[LEFT(i, col)] = right[RIGHT(i, col)] = true;
            tmp[col] = i;
            backtracking(col + 1);

            row[i] = left[LEFT(i, col)] = right[RIGHT(i, col)] = false;
        }
    }
}

int main()
{
    //freopen("test.out", "w", stdout);
    backtracking(0);

    int Case = 0, in_row[8];
    while (scanf("%d", &in_row[0]) != EOF)
    {
        for (int i = 1; i < 8; ++i)
            scanf("%d", &in_row[i]);

        int min = 8;
        //找到哪一種方法要移動得最少
        for (int i = 0; i < no; ++i)
        {
            int diff = 0;
            for (int j = 0; j < 8; ++j)
                if (in_row[j] != correct_row[i][j])
                    ++diff;

            if (diff < min)
                min = diff;
        }

        printf("Case %d: %d\n", ++Case, min);
    }

    return 0;
}