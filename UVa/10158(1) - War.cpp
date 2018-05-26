#include <cstdio>
#define N 20010

//disjoint set
int n;
int p[N];    //the leader of each unit([x]: x 的代表)
int size[N]; //number of each group([x]: x 的成員有幾人)
inline void init()
{
    for (int i = 0; i < (n << 1); ++i)
    {
        size[i] = 1;
        p[i] = i;
    }
}
inline int find(int x)
{
    return (x == p[x]) ? x : (p[x] = find(p[x]));
}
inline int get_ene(int x) //x 的敵人
{
    return x + n;
}
inline void do_union(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;

    //小的併入大的
    if (size[x] < size[y])
    {
        p[x] = y;
        size[y] += size[x];
    }
    else
    {
        p[y] = x;
        size[x] += size[y];
    }
}
inline bool are_friends(int x, int y)
{
    return find(x) == find(y);
}
inline bool are_enemies(int x, int y)
{
    return find(get_ene(x)) == find(y) || find(get_ene(y)) == find(x);
}
inline bool set_friends(int x, int y)
{
    int ex = find(get_ene(x)), ey = find(get_ene(y));
    x = find(x), y = find(y);

    if (ex == y || ey == x) //they are enemies
        return false;

    do_union(x, y);
    do_union(ex, ey); //雙方的敵人互為朋友
    return true;
}
inline bool set_enemies(int x, int y)
{
    int ex = find(get_ene(x)), ey = find(get_ene(y));
    x = find(x), y = find(y);

    if (x == y) //they are friends
        return false;

    //敵人的敵人就是朋友
    do_union(ex, y);
    do_union(ey, x);

    return true;
}
int main()
{
    scanf("%d", &n);
    init();
    int c, x, y;
    while (scanf("%d%d%d", &c, &x, &y) && c)
    {
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
/*
7
1 1 2
1 3 4
2 2 3
1 1 4
2 4 5
2 1 5
1 5 6
3 1 6
3 3 6
0 0 0

-1
-1
1
0
*/