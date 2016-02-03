/*
Disjoint-sets Forest(並查集)
http://www.csie.ntnu.edu.tw/~u91029/Set.html#8
https://zh.wikipedia.org/wiki/并查集
*/
#include<cstdio>
#define N 1001

int com[N];//每個點的代表，最上層的指向自己
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
    return x == com[x] ? x : (com[x] = find(com[x]));//找出 x 的代表，且把中途遇到的人都設置好，加快下次查找速度(路徑壓縮)
}
void doUnion(int a, int b)
{
    com[find(a)] = com[find(b)];//作聯集，將 a 的代表變為 b 的代表
}
bool isEquivalent(int a, int b)
{
    return find(a) == find(b);//看代表是不是同一人
}