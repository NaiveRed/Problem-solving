#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int> > PQ;

    while (scanf("%d", &n) && n)
    {
        int num;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            PQ.push(num);
        }

        for (int i = 1; i < n; i++)
        {
            int a, b;
            a = PQ.top(), PQ.pop();
            b = PQ.top(), PQ.pop();

            sum += (a + b);
            PQ.push(a + b);
        }

        PQ.pop();
        printf("%lld\n", sum);
    }

    return 0;
}