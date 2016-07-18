#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<utility>
#include<algorithm>
#define N 301
using namespace std;
typedef pair<int, int> Pair;

/*
node[x] = x 的祖先
注意 0 號為沒有祖先了
*/
int node[N] = {};
Pair getRelation(int first,int second)
{
    /*
    如果關係為 cousin:
    lev1,lev2 分別存共同祖先的各個順位

    如果某一方為另一方的 祖先:
    lev1 = 存他祖先的順位
    lev2 = -1
    反之則關係相反
    */

    int order1[N] = {}, order2[N];//[x] = x 的順位
    int lev1 = -1, lev2 = -1;
    int count = 1;//計算目前順位
    int next = node[first];

    while (next)
    {
        order1[next] = count++;
        next = node[next];
    }

    if (order1[second])//n 是 this 的 祖先
        lev1 = order1[second];
    else
    {
        next = node[second];
        count = 1;
        while (next)
        {
            if (order1[next])//n 和 this 為 cousin
            {
                lev1 = order1[next];
                lev2 = count;
                break;
            }
            else if (next == first)//this 是 n 的祖先
            {
                lev2 = count;
                break;
            }

            order2[next] = count++;
            next = node[next];
        }
    }

    return make_pair(lev1, lev2);
}
int main()
{
    string child, parent;
    map<string, int> Map;
    int mapId = 1;//0 是沒祖先

    while (cin >> child >> parent)
    {
        if (!strcmp(child.c_str(), "no.child"))
            break;

        if (!Map.count(child))
            Map[child] = mapId++;
        if (!Map.count(parent))
            Map[parent] = mapId++;
        
        node[Map[child]] = Map[parent];
    }

    string a, b;
    pair<int, int> relation;

    while (cin >> a >> b)
    {
        if (Map[a] == Map[b])//自己和自己沒關係
            puts("no relation");
        else
        {
            relation = getRelation(Map[a], Map[b]);
            int par1 = relation.first, par2 = relation.second;

            if (par1 != -1 && par2 != -1)
            {
                if (par1 == 1 && par2 == 1)//兄弟
                    puts("sibling");
                else//cousin
                {
                    int diff = abs(par1 - par2);
                    printf("%d cousin", min(par1, par2) - 1);
                    if (diff)
                        printf(" removed %d", diff);
                    putchar('\n');
                }
            }
            else if (par1 != -1)//a 是 b 的子孫
            {
                if (par1 > 1)
                {
                    for (int i = 1; i < par1 - 1; i++)
                        printf("great ");
                    puts("grand child");
                }
                else
                    puts("child");
            }
            else if (par2 != -1)//a 是 b 的祖先
            {
                if (par2 > 1)
                {
                    for (int i = 1; i < par2 - 1; i++)
                        printf("great ");
                    puts("grand parent");
                }
                else
                    puts("parent");
            }
            else//沒關係
                puts("no relation");
        }
    }

    return 0;
}