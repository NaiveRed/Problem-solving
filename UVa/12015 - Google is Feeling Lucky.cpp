#include<cstdio>
#include<algorithm>

struct Data
{
    char str[101];
    int relevance;
};
int main()
{
    Data search[10];
    int Case;
    scanf("%d", &Case);

    for (int i = 1; i <= Case; i++)
    {
        for (int j = 0; j < 10; j++)
            scanf("%s%d", search[j].str, &search[j].relevance);

        std::sort(search, search + 10, [](const Data& a, const Data& b)->bool{ return a.relevance > b.relevance; });
        
        printf("Case #%d:\n", i);
        int r = search[0].relevance;
        puts(search[0].str);

        for (int j = 1; search[j].relevance == r; j++)
            puts(search[j].str);

    }

    return 0;
}