#include <cstdio>
#define N 100005
#define M 262144
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define LC(i) ((i) << 1)
#define RC(i) (((i) << 1) | 1)
#define PADDING 1e9

int arr[N];
int left[N], right[N]; //[n]: arr[n] 連續數字的左右邊界
int fre[N];            //該段數字的長度(次數)
int tree[M];           //segment tree
int T;                 //last level
void build(int n)
{
    //2: head and tail padding
    for (T = 1; T < n + 2; T <<= 1)
        ;
    int i;

    tree[T] = tree[T + n + 1] = 0;
    for (i = 1; i <= n; ++i)
        tree[T + i] = fre[i]; //frequent

    for (; i < T; ++i)
    {
        tree[T + i] = 0; //padding
    }

    for (i = T - 1; i; --i)
        tree[i] = MAX(tree[LC(i)], tree[RC(i)]);
}
int query(int L, int R)
{
    int res = 1;
    //因為是非遞減，頭尾數字一樣時，中間也一樣
    if (arr[L] != arr[R])
    {
        if (L > left[L]) //最左半段有被切
        {
            res = right[L] - L + 1; //最左段的長度
            L = right[L] + 1;
        }

        if (R < right[R]) //最右半段有被切
        {
            res = MAX(res, R - left[R] + 1); //最右段的長度
            R = left[R] - 1;
        }

        if (L < R) //還有剩餘沒被切割到的區段(L==R 時就只有 1 個省略不算)
            for (L += T - 1, R += T + 1; L ^ R ^ 1; L >>= 1, R >>= 1)
            {
                if (~L & 1)
                    res = MAX(res, tree[L ^ 1]);
                if (R & 1)
                    res = MAX(res, tree[R ^ 1]);
            }
    }
    else
        res = R - L + 1;

    return res;
}
inline int read()
{
    int n = 0, neg = 1;
    char c = getchar();
    if (c == '-')
        neg = -1;
    else
        n = c - '0';
    while ((c = getchar()) <= '9' && c >= '0')
        n = n * 10 + c - '0';

    return n * neg;
}
int main()
{
    /*int T;
    for (T = 1; T < N; T <<= 1)
        ;
    printf("%d\n", T * 2);*/

    int n, q;
    while (scanf("%d%d ", &n, &q) == 2)
    {
        int start = 1, last = PADDING, i;
        for (i = 1; i <= n; ++i)
        {
            //non-decreasing
            arr[i] = read();
            if (arr[i] != last)
            {
                for (int k = start; k < i; ++k)
                {
                    right[k] = i - 1;   //上個數字該邊界到 i - 1
                    fre[k] = i - start; //該段數字共有幾個
                }
                //重新開始某段數字
                start = left[i] = i;
                last = arr[i];
            }
            else
                left[i] = start;
        }
        //最後一段 [start, n]
        for (int k = start; k < i; ++k)
        {
            right[k] = i - 1; // (n+1) - 1
            fre[k] = i - start;
        }

        build(n);
        for (int i = 0; i < q; ++i)
        {
            int L = read(), R = read();
            printf("%d\n", query(L, R));
        }
    }

    return 0;
}