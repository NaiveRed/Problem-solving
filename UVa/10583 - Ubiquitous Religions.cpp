/*
Disjoint-sets Forest(�ìd��)
*/
#include<cstdio>
#define N 50001

int p[N];//�C���I���N��(parent)
inline int getNum();
inline void makeSet(int n);
inline int find(int x);
inline void doUnion(int a, int b, int& now);//now���ثe���v�м�
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
    return x == p[x] ? x : (p[x] = find(p[x]));//���|���Y
}
void doUnion(int a, int b, int &now)
{
    int pa = find(a), pb = find(b);

    //�w�g�b�P�@���X
    if (pa == pb)
        return;

    p[pa] = pb;
    now--;
}
