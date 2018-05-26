#include <cstdio>
#define N 10010

//disjoint set
int p[N];     //the leader of each unit([x]: x 的代表)
int size[N];  //number of each group([x]: x 的成員有幾人)
int enemy[N]; //[x]: x's enemy
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        size[i] = 1;
        p[i] = i;
        enemy[i] = 0; //empty set
    }
}
inline int find(int x)
{
    return (x == p[x]) ? x : (p[x] = find(p[x]));
}
inline void do_union(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y || !x || !y)
        return;

    //小的併入大的
    if (size[x] < size[y])
    {
        p[x] = y;
        size[y] += size[x];
        //size[x] = 0;
    }
    else
    {
        p[y] = x;
        size[x] += size[y];
        //size[y] = 0;
    }
}
inline bool are_friends(int x, int y)
{
    x = find(x), y = find(y);
    return x == y;
}
inline bool are_enemies(int x, int y)
{
    x = find(x), y = find(y);
    return find(enemy[x]) == y || find(enemy[y]) == x;
}
inline bool set_friends(int x, int y)
{
    x = find(x), y = find(y);
    int ex = find(enemy[x]), ey = find(enemy[y]);

    if (ex == y || ey == x) //they are enemies
        return false;

    do_union(x, y);

    //兩方的敵人會成為朋友，並更新紀錄敵人的陣列
    do_union(ex, ey);
    ex = find(ex), ey = find(ey);
    enemy[find(x)] = ex ? ex : ey;

    return true;
}
inline bool set_enemies(int x, int y)
{
    x = find(x), y = find(y);

    if (x == y) //they are friends
        return false;

    do_union(enemy[x], y);
    do_union(enemy[y], x);

    x = find(x), y = find(y);
    enemy[x] = y;
    enemy[y] = x;

    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    int c, x, y;
    while (scanf("%d%d%d", &c, &x, &y) && c)
    {
        ++x, ++y; //編號從 1 開始
        if (c == 1)
        {
            if (!set_friends(x, y))
                puts("-1");
        }
        else if (c == 2)
        {
            if (!set_enemies(x, y))
                puts("-1");
        }
        else if (c == 3)
            puts(are_friends(x, y) ? "1" : "0");
        else if (c == 4)
            puts(are_enemies(x, y) ? "1" : "0");
    }

    return 0;
}