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
node[x] = x ������
�`�N 0 �����S�������F
*/
int node[N] = {};
Pair getRelation(int first,int second)
{
    /*
    �p�G���Y�� cousin:
    lev1,lev2 ���O�s�@�P�������U�Ӷ���

    �p�G�Y�@�謰�t�@�誺 ����:
    lev1 = �s�L����������
    lev2 = -1
    �Ϥ��h���Y�ۤ�
    */

    int order1[N] = {}, order2[N];//[x] = x ������
    int lev1 = -1, lev2 = -1;
    int count = 1;//�p��ثe����
    int next = node[first];

    while (next)
    {
        order1[next] = count++;
        next = node[next];
    }

    if (order1[second])//n �O this �� ����
        lev1 = order1[second];
    else
    {
        next = node[second];
        count = 1;
        while (next)
        {
            if (order1[next])//n �M this �� cousin
            {
                lev1 = order1[next];
                lev2 = count;
                break;
            }
            else if (next == first)//this �O n ������
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
    int mapId = 1;//0 �O�S����

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
        if (Map[a] == Map[b])//�ۤv�M�ۤv�S���Y
            puts("no relation");
        else
        {
            relation = getRelation(Map[a], Map[b]);
            int par1 = relation.first, par2 = relation.second;

            if (par1 != -1 && par2 != -1)
            {
                if (par1 == 1 && par2 == 1)//�S��
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
            else if (par1 != -1)//a �O b ���l�]
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
            else if (par2 != -1)//a �O b ������
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
            else//�S���Y
                puts("no relation");
        }
    }

    return 0;
}