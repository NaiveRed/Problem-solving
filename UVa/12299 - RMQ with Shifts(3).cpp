//iterative
#include <cstdio>
#define N 100002
#define M 262144
#define MIN(a, b) ((a) < (b) ? (a) : (b))
//以陣列模擬樹，go left/right child
#define LC(i) ((i) << 1)
#define RC(i) (((i) << 1) | 1)
#define PADDING 1e9
//存取葉節點的 index
#define LEAF(i) ((T) + (i))

int tree[M];
int T; //葉節點的起始 index

void build(int n)
{
    //N: N 為數列長度

    //進行填補，使其成為滿二元數
    for (int i = n; i < T; ++i)
        tree[T + i] = PADDING;

    //bottom-up 建構樹
    for (int i = T - 1; i; --i)
        tree[i] = MIN(tree[LC(i)], tree[RC(i)]);
}

//單點修改
void modify(int n, int x)
{
    /*
    n: 欲修改的數字
    x: 欲修改的位置
    */

    int i = T + x;
    tree[i] = n;

    for (; i ^ 1; i >>= 1)
        tree[i >> 1] = MIN(tree[i], tree[i ^ 1]);
}

//區間查詢
int query(int L, int R)
{
    /*
    [L, R]: 所查詢之區間
    */

    int res = 1e9;

    for (L += T - 1, R += T + 1; L ^ R ^ 1; L >>= 1, R >>= 1)
    {
        //注意現在是 (L, R) 開區間
        if (~L & 1) //如果 L 是在左子樹，比較右邊的節點
            res = MIN(tree[L ^ 1], res);
        if (R & 1) //如果 R 是在右子樹，比較左邊的節點
            res = MIN(tree[R ^ 1], res);
    }

    return res;
}
int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) <= '9' && c >= '0')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    //freopen("test.in", "r", stdin);
    int n, q;
    scanf("%d%d ", &n, &q);

    //所需要的 tree 大小為 T * 2
    for (T = 1; T < n + 2; T <<= 1)
        ;

    tree[LEAF(0)] = tree[LEAF(n + 1)] = PADDING;
    //直接存進樹中
    for (int i = 1; i <= n; ++i)
        tree[LEAF(i)] = read();

    build(n + 2);

    char str[35];
    for (int k = 0; k < q; ++k)
    {
        if (getchar() == 'q')
        {
            for (int j = 0; j < 5; ++j)
                getchar();
            int x1 = read(), x2 = read(), xx;
            getchar(); //'\n'
            xx = query(x1, x2);
            printf("%d\n", xx);
        }
        else
        {
            fgets(str, 35, stdin);
            int start_val, last = 0, idx = 0, i;
            for (i = 5; str[i] != ','; ++i)
                last = last * 10 + str[i] - '0';
            start_val = tree[LEAF(last)]; //把第一個數字先記下
            for (++i;; ++i)
            {
                if (str[i] == ',' || str[i] == ')')
                {
                    //當前數字放進上一個位置
                    modify(tree[LEAF(idx)], last);
                    last = idx;
                    idx = 0;
                    if (str[i] == ')')
                    {
                        //將第一個放到最後一個指定的位置
                        modify(start_val, last);
                        break;
                    }
                }
                else
                    idx = idx * 10 + str[i] - '0';
            }
        }
    }
    return 0;
}