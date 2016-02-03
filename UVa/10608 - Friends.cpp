/*
Disjoint-sets Forest(�ìd��)
http://www.csie.ntnu.edu.tw/~u91029/Set.html#8
https://zh.wikipedia.org/wiki/�}�d��
*/
#include<cstdio>
#define N 30001

int friends[N];//�C���I���N��(parent)�A�̤W�h�����V�ۤv
int people[N];
inline int getNum();
inline void makeSet(int n);
inline int find(int x);
inline void doUnion(int a, int b);
int main()
{
    int cases;
    scanf("%d", &cases);

    int n, m, a, b;
    while (cases--)
    {
        scanf("%d%d", &n, &m);
        getchar();

        //initialize
        makeSet(n);
        for (int i = 1; i <= n; i++)
            people[i] = 1;

        while (m--)
        {
            a = getNum();
            b = getNum();
            doUnion(a, b);
        }

        int max = 0;
        for (int i = 1; i <= n; i++)
            if (people[i] > max)
                max = people[i];

        printf("%d\n", max);
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
        friends[i] = i;
}
int find(int x)
{
    return x == friends[x] ? x : (friends[x] = find(friends[x]));//��X x ���N��A�B�⤤�~�J�쪺�H���]�m�n�A�[�֤U���d��t��(���|���Y)
}
void doUnion(int a, int b)
{
    int pa = find(a), pb = find(b);

    //�w�g�b�P�@���X
    if (pa == pb)
        return;

    friends[pa] = pb;
    people[pb] += people[pa];
}
