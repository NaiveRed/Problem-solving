#include<cstdio>
#include<algorithm>
#define N 30*3
using namespace std;

struct Block
{
    int len[3];

    bool operator<(const Block& b)
    {
        if (len[0] == b.len[0])
            return len[1] < b.len[1];
        else
            return len[0] < b.len[0];
    }

}blocks[N];
int main()
{
    int n, Case = 1, hight[N];
    while (scanf("%d", &n) && n)
    {
        int i, j;
        n *= 3;

        for (i = 0; i < n; i++)
        {
            int dim[3];
            scanf("%d%d%d", &dim[0], &dim[1], &dim[2]);
            sort(dim, dim + 3);

            blocks[i].len[0] = dim[0], blocks[i].len[1] = dim[1], blocks[i].len[2] = dim[2];//0,1,2
            i++;
            blocks[i].len[0] = dim[0], blocks[i].len[1] = dim[2], blocks[i].len[2] = dim[1];//0,2,1
            i++;
            blocks[i].len[0] = dim[1], blocks[i].len[1] = dim[2], blocks[i].len[2] = dim[0];//1,2,0
        }

        sort(blocks, blocks + n);

        for (i = 0; i < n; i++)
            hight[i] = blocks[i].len[2];

        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (blocks[i].len[0] < blocks[j].len[0] && blocks[i].len[1] < blocks[j].len[1])
                    hight[j] = max(hight[j], hight[i] + blocks[j].len[2]);

        int max = -1;
        for (i = 0; i < n; i++)
            if (max < hight[i])
                max = hight[i];

        printf("Case %d: maximum height = %d\n", Case++, max);
    }

    return 0;
}