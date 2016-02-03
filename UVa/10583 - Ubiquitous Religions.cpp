/*
Disjoint-sets Forest(並查集)
*/
#include<cstdio>
#define N 50001

int p[N];//每個點的代表(parent)
inline int getNum();
inline void makeSet(int n);
inline int find(int x);
inline void doUnion(int a, int b, int& now);//now為目前的宗教數
int main()
{
    int cases = 1;

    int n, m, a, b;
    while (scanf("%d%d", &n, &m) && n)
    {
        getchar();
        //initialize
        makeSet(n);

        while (m--)
        {
            //scanf("%d%d", &a, &b);
            a = getNum();
            b = getNum();
            doUnion(a, b, n);
        }

        printf("Case %d: %d\n", cases++, n);
    }

    return 0;
}
int getNum()
{
    char c;
    int num = 0;

    while ((c = getchar()) != '\n'&&c != ' ')
        num = num * 10 + c - '0';

    return num;
}
void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
}
int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));//路徑壓縮
}
void doUnion(int a, int b, int &now)
{
    int pa = find(a), pb = find(b);

    //已經在同一集合
    if (pa == pb)
        return;

    p[pa] = pb;
    now--;
}
