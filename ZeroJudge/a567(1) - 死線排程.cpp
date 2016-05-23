#include<cstdio>
#include<algorithm>
#define N 10001

using namespace std;
struct Item
{
    int dead, p;

}item[N];

int day[N];
inline int find(int a);
inline void Union(int a, int b);
int main()
{
    int n, i;
    while (scanf("%d", &n) != EOF)
    {
        int max = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &item[i].dead, &item[i].p);
            if (max < item[i].dead)
                max = item[i].dead;
        }
        sort(item, item + n, [](const Item& a, const Item& b)->bool
        {
            return a.p > b.p;
        });

        int sum = 0, j;
        //init disjoint set
        for (i = 0; i <= max; i++)
            day[i] = i;

        //�C�� day[] ��ثe�i�񪺰϶�����
        for (i = 0; i < n; i++)
        {
            if (find(item[i].dead))
            {
                sum += item[i].p;
                //�N�ثeitem��J�A�q��deadline�V���A�i�H�񪺦�m
                Union(item[i].dead, day[item[i].dead] - 1);//�`�N���Ǧ��v�T
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
int find(int a)
{
    return day[a] == a ? a : (day[a] = find(day[a]));
}
void Union(int a, int b)
{
    day[find(a)] = find(b);
}