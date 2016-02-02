#include<cstdio>
#include<algorithm>
#define N 1000

struct Elephant
{
    int W;
    int S;
    int id;
};
bool comp(const Elephant& a, const Elephant& b);
bool isOk(const Elephant& small, const Elephant& big);
int main()
{
    Elephant ele[N];
    int n = 0, i;
    while (scanf("%d%d", &ele[n].W, &ele[n].S) != EOF)
    {
        ele[n].id = n + 1;//大象編號從 1 開始
        n++;
    }

    //由輕到重排好
    std::sort(ele, ele + n, comp);

    int length[N], prev[N] = {};
    std::fill(length, length + n, 1);

    //LIS
    for (i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (isOk(ele[i], ele[j]))
                if (length[i] + 1>length[j])
                    length[j] = length[i] + 1;

    }
    //最長的LIS長度
    int max = 0, final;
    for (i = 0; i < n; i++)
        if (max < length[i])
        {
        max = length[i];
        final = i;
        }

    //找出LIS
    int lis[N], temp = max;
    for (i = final; i >= 0 && temp; i--)
    {
        if (length[i] == temp)
        {
            lis[temp] = i;
            temp--;
        }
    }

    printf("%d\n", max);
    for (i = 1; i <= max; i++)
        printf("%d\n", ele[lis[i]].id);

    return 0;
}
bool comp(const Elephant& a, const Elephant& b)
{
    if (a.W < b.W)
        return true;
    else
        return false;
}
bool isOk(const Elephant& small, const Elephant& big)
{
    if (big.W > small.W&&small.S > big.S)
        return true;
    else
        return false;
}