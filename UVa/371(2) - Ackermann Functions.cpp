//time: 0.040
#include <cstdio>
#include <stack>
#define N 10000001
typedef unsigned int UI;

int length[N] = {0, 1};

inline UI get_next(const UI &now)
{
    return (now & 1) ? ((now << 1) + now + 1) : (now >> 1);
}
void build(int n)
{
    UI now = n, next;
    std::stack<UI> s;

    s.push(now);
    while (now != 1)
    {
        next = get_next(now);
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
    while (scanf("%d%d", &i, &j) && (i || j))
    {
        if (i > j)
        {
            int tmp = i;
            i = j;
            j = tmp;
        }
        UI max = 0, a = i, b = j, n;

        for (; a <= b; a++)
        {
            if (a == 1 && 3 > max)
            {
                n = 1;
                max = 4;
            }
            else
            {
                int count = 0;
                while (a >= N)
                {
                    a = get_next(a);
                    count++;
                }

                //邊建邊查
                if (!length[a])
                    build(a);

                if (length[a] + count > max)
                {
                    max = length[a];
                    n = a + count;
                }
            }
        }

        printf("Between %d and %d, %d generates the longest sequence of %d values.\n", i, j, n, max - 1);
    }
    return 0;
}