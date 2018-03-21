#include <cstdio>
#include <queue>
#define N 3000
using namespace std;

struct drug
{
    int id, times;
    drug() {}
    drug(int _id, int _times) : id(_id), times(_times) {}
    bool operator<(const drug &a) const
    {
        if (times != a.times)
            return times > a.times;
        return id > a.id;
    }
};
int main()
{
    //freopen("test.out", "w", stdout);
    int T;
    char name[N][16];
    int fre[N];
    scanf("%d", &T);
    while (T--)
    {
        priority_queue<drug> PQ;
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s%d", name[i], &fre[i]);
            PQ.emplace(i, fre[i]);
        }
        
        for (int i = 0; i < k; ++i)
        {
            drug d = PQ.top();
            PQ.pop();
            PQ.emplace(d.id, d.times + fre[d.id]);

            printf("%d %s\n", d.times, name[d.id]);
        }
    }

    return 0;
}