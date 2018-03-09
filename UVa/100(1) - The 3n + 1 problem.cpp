#include <cstdio>
#include <stack>
#define N 1000001
typedef long long LL;

int length[N] = {0, 1};
void build(int n)
{
    LL now = n, next;
    std::stack<LL> s;
    //for (int i = 2; i < N; i++) 也可以直接建完，速度較慢

    s.push(now);
    while (now != 1)
    {
        next = (now & 1) ? ((now << 1) + now + 1) : (now >> 1);
        s.push(next);

        if (next < N && length[next])
            break;

        now = next;
    }

    int len = length[s.top()];
    s.pop();
    for (int j = 1; !s.empty(); j++, s.pop())
    {
        now = s.top();
        if (now < N)
            length[now] = len + j;
    }
}

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

    int i, j;
    while (scanf("%d%d", &i, &j) != EOF)
    {
        int max = 0, a, b;
        if (i < j)
            a = i, b = j;
        else
            a = j, b = i;

        for (; a <= b; a++)
        {
            //邊建邊查
            if (!length[a])
                build(a);
            if (length[a] > max)
                max = length[a];
        }

        printf("%d %d %d\n", i, j, max);
    }
    return 0;
}