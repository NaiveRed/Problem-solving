#include <cstdio>
#include <cstring>
#include <queue>
#define N 10000

inline int input()
{
    /*int tmp[4];
    scanf("%d%d%d%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
    return tmp[3]*1000 + tmp[2]*100 + tmp[1]*10 + tmp[0];*/

    int n = 0, k = 0;
    char ch;
    while (k < 4)
    {
        ch = getchar();
        if (ch >= '0' && ch <= '9')
        {
            n = n * 10 + ch - '0';
            ++k;
        }
    }
    return n;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int T;
    bool visited[N] = {};
    int step[N] = {};
    scanf("%d", &T);
    while (T--)
    {
        int s, t, n;
        s = input();
        t = input();
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            visited[input()] = true;

        if (s == t)
            puts("0");
        else if (visited[t])
            puts("-1");
        else
        {
            //BFS
            std::queue<int> Q;
            Q.push(s);
            visited[s] = true;

            while (!Q.empty())
            {
                int now = Q.front();
                Q.pop();

                for (int k = 1000, cpy = now; k; k /= 10)
                {
                    int tmp = (now / k) % 10; //取出當前位數
                    //逆
                    if (tmp < 9) //1 -> 2, ...
                        now += k;
                    else
                        now -= 9 * k; //9 -> 0

                    if (!visited[now])
                    {
                        Q.push(now);
                        step[now] = step[cpy] + 1;
                        visited[now] = true;
                    }
                    if (now == t)
                        break;

                    now = cpy;

                    //順
                    if (tmp) //2 -> 1, ...
                        now -= k;
                    else
                        now += 9 * k; //0 -> 9

                    if (!visited[now])
                    {
                        Q.push(now);
                        step[now] = step[cpy] + 1;
                        visited[now] = true;
                    }
                    if (now == t)
                        break;

                    now = cpy;
                }
            }

            printf("%d\n", step[t] ? step[t] : -1);
        }

        //init
        memset(visited, false, sizeof visited);
        memset(step, 0, sizeof step);
    }

    return 0;
}