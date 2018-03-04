#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
#define N 500000

vector<int> adj_list[N];
bool visited[N];
bool dfs(int last, int now)
{
    visited[now] = true;
    bool match = last == -1;
    vector<int> tmp;

    while (!adj_list[now].empty())
    {
        int next = adj_list[now].back();

        if (!match && next == last)
            match = true;
        else if (!visited[next])
        {
            if (!dfs(now, next))
                return false;
        }
        else
            tmp.push_back(next); //已經在進行中未完成的點，待會要存回去

        adj_list[now].pop_back();
    }

    for (int i : tmp)
        adj_list[now].push_back(i);

    visited[now] = false;
    return match;
}
inline int get_num()
{
    int n = 0;
    char c;
    while ((c = getchar()) != '\n' && c != ' ')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    //freopen("test.out", "w", stdout);
    int n;
    std::unordered_map<int, int> map;
    while (scanf("%d", &n) && n)
    {
        getchar();
        int a, b, idx = -1; //從 0 開始編號
        /*
        max: YES時最多有幾國，最多就是 n 行 n 個國家
        4
        1 2
        2 1
        3 4
        4 3
        中間若有 5 一定是 NO
        */
        int max = n;                       //max: 最多有幾國
        bool ans = (n & 1) ? false : true; //奇數不可能可以配對
        while (n--)
        {
            a = get_num();
            b = get_num();
            //scanf("%d%d", &a, &b);
            if (ans)
            {
                if (!map.count(a))
                    map[a] = ++idx;
                if (!map.count(b))
                    map[b] = ++idx;

                if (idx + 1 > max)
                {
                    ans = false;
                    continue;
                }

                adj_list[map[a]].push_back(map[b]);
            }
        }

        for (int i = 0; ans && i <= idx; i++)
        {
            if (!dfs(-1, i))
                ans = false;
        }

        puts(ans ? "YES" : "NO");
        map.clear();
        for (int i = 0; i <= idx; i++)
            adj_list[i].clear();
        memset(visited, false, sizeof(bool) * (idx + 1));
    }

    return 0;
}
/*
18
26 29
21 1
29 26
29 19
25 19
28 23
8 15
27 16
19 29
5 11
11 5
16 27
19 25
5 13
15 8
23 28
13 5
1 21
18
12 17
8 25
11 3
28 24
8 27
25 11
24 28
17 12
19 23
27 8
28 27
27 24
23 19
3 11
24 27
25 8
11 25
27 28
4
1 2
2 4
3 1
4 3
0

YES
YES
NO
*/