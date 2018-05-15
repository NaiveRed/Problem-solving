//recursive
#include <cstdio>
#define N 100001
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define LC(i) ((i) << 1)
#define RC(i) (((i) << 1) + 1)

int arr[N]; //index start from 1
struct node
{
    int min;   //區間最小值
} tree[N * 4]; //root 為 [1]，非滿二元數

void build(int L, int R, int idx)
{
    if (L == R)
    {
        tree[idx].min = arr[L];
        return;
    }

    int M = (L + R) >> 1;
    int left_idx = LC(idx);     //index of left child
    int right_idx = RC(idx);    //index of right child
    build(L, M, left_idx);      //go left
    build(M + 1, R, right_idx); //go right

    tree[idx].min = MIN(tree[left_idx].min, tree[right_idx].min);
}

//單點修改
void modify(int n, int x, int L, int R, int idx)
{
    if (L == R)
    {
        tree[idx].min = n;
        return;
    }

    int M = (L + R) >> 1;
    int left_idx = LC(idx);  //index of left child
    int right_idx = RC(idx); //index of right child
    if (x <= M)
        modify(n, x, L, M, left_idx); //go left
    else
        modify(n, x, M + 1, R, right_idx); //go right

    tree[idx].min = MIN(tree[left_idx].min, tree[right_idx].min);
}

//區間查詢
int query(int x1, int x2, int L, int R, int idx)
{
    if (x1 == L && x2 == R)
        return tree[idx].min;

    int M = (L + R) >> 1;
    int left_idx = LC(idx);  //index of left child
    int right_idx = RC(idx); //index of right child

    if (x2 <= M) //查詢的區間在左邊
        return query(x1, x2, L, M, left_idx);
    else if (x1 > M) //查詢的區間在右邊
        return query(x1, x2, M + 1, R, right_idx);
    else //查詢的區間橫跨兩邊
        return MIN(query(x1, M, L, M, left_idx), query(M + 1, x2, M + 1, R, right_idx));
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
    int n, q;
    scanf("%d%d ", &n, &q);

    for (int i = 1; i <= n; ++i)
        arr[i] = read();

    const int L = 1, R = n, root = 1;
    build(L, R, root);

    char str[35];
    for (int k = 0; k < q; ++k)
    {
        if (getchar() == 'q')
        {
            for (int j = 0; j < 5; ++j)
                getchar();
            int x1 = read(), x2 = read(), xx;
            getchar(); //'\n'
            xx = query(x1, x2, L, R, root);
            printf("%d\n", xx);
        }
        else
        {
            fgets(str, 35, stdin);
            int start_val, last = 0, idx = 0, i;
            for (i = 5; str[i] != ','; ++i)
                last = last * 10 + str[i] - '0';
            start_val = arr[last];
            for (++i;; ++i)
            {
                if (str[i] == ',' || str[i] == ')')
                {
                    arr[last] = arr[idx];
                    modify(arr[idx], last, L, R, root);
                    last = idx;
                    idx = 0;
                    if (str[i] == ')')
                    {
                        arr[last] = start_val;
                        modify(start_val, last, L, R, root);
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