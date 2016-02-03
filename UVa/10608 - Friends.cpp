/*
Disjoint-sets Forest(並查集)
http://www.csie.ntnu.edu.tw/~u91029/Set.html#8
https://zh.wikipedia.org/wiki/并查集
*/
#include<cstdio>
#define N 30001

int friends[N];//每個點的代表(parent)，最上層的指向自己
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
    return x == friends[x] ? x : (friends[x] = find(friends[x]));//找出 x 的代表，且把中途遇到的人都設置好，加快下次查找速度(路徑壓縮)
}
void doUnion(int a, int b)
{
    int pa = find(a), pb = find(b);

    //已經在同一集合
    if (pa == pb)
        return;

    friends[pa] = pb;
    people[pb] += people[pa];
}
