/*
Disjoint-sets Forest(�ìd��)
http://www.csie.ntnu.edu.tw/~u91029/Set.html#8
https://zh.wikipedia.org/wiki/�}�d��
*/
#include<cstdio>
#define N 1001

int com[N];//�C���I���N��A�̤W�h�����V�ۤv
inline void init(int n);
inline int find(int x);
inline void doUnion(int a, int b);
inline bool isEquivalent(int a, int b);
int main()
{
    int cases;
    scanf("%d", &cases);

    char str[100], c;

    int n, a, b;
    for (int i = 0; i < cases; i++)
    {
        int success = 0, notSuccess = 0;
        scanf("%d", &n);
        getchar();

        init(n + 1);
        while (gets(str) && str[0])
        {
            sscanf(str, "%c%d%d", &c, &a, &b);
            if (c == 'q')
            {
                if (isEquivalent(a, b))
                    success++;
                else
                    notSuccess++;
            }
            else
                doUnion(a, b);
        }

        if (i)
            putchar('\n');
        printf("%d,%d\n", success, notSuccess);
    }

    return 0;
}
void init(int n)
{
    for (int i = 0; i < n; i++)
        com[i] = i;
}
int find(int x)
{
    return x == com[x] ? x : (com[x] = find(com[x]));//��X x ���N��A�B�⤤�~�J�쪺�H���]�m�n�A�[�֤U���d��t��(���|���Y)
}
void doUnion(int a, int b)
{
    com[find(a)] = com[find(b)];//�@�p���A�N a ���N���ܬ� b ���N��
}
bool isEquivalent(int a, int b)
{
    return find(a) == find(b);//�ݥN��O���O�P�@�H
}