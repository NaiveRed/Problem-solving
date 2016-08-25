//https://paper.dropbox.com/doc/064-CF527D-Clique-Problem-teqEWHbCZQgXVJaek1YBp
#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > interval;

    for (int i = 0; i < n; i++)
    {
        int x, w;
        scanf("%d%d", &x, &w);
        interval.push_back(make_pair(x + w, x - w));
    }

    //Activity Selection Problem
    sort(interval.begin(), interval.end());
    int count = 0, end = -1e9;
    for (auto p : interval)
    {
        if (end <= p.second)
        {
            end = p.first;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}