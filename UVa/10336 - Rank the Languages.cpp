#include <cstdio>
#include <algorithm>
#include <utility>
#include <stack>
#include <cstring>
#define N 500
using namespace std;

int main()
{
    const int dir[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int T;
    char grid[N][N];
    bool visited[N][N] = {};
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int H, W;
        char tmp[N];
        scanf("%d%d ", &H, &W);
        for (int i = 1; i <= H; ++i)
        {
            fgets(tmp, N, stdin);
            for (int j = 1; j <= W; ++j)
                grid[i][j] = tmp[j - 1];
        }

        pair<char, int> lang[26];
        for (int i = 0; i < 26; ++i)
            lang[i] = make_pair('a' + i, 0);

        //DFS
        stack<pair<int, int>> S;
        char ch;
        for (int i = 1; i <= H; ++i)
            for (int j = 1; j <= W; ++j)
            {
                if (visited[i][j])
                    continue;

                S.emplace(i, j);
                ch = grid[i][j];
                visited[i][j] = true;

                while (!S.empty())
                {
                    int r = S.top().first, c = S.top().second;
                    S.pop();
                    for (int i = 0; i < 4; ++i)
                    {
                        int rr = r + dir[i][0], cc = c + dir[i][1];
                        if (rr && rr <= H && cc && cc <= W && !visited[rr][cc] && grid[rr][cc] == ch)
                        {
                            visited[rr][cc] = true;
                            S.emplace(rr, cc);
                        }
                    }
                }

                //使用該語言的區域增加
                lang[ch - 'a'].second++;
            }

        sort(lang, lang + 26, [](const pair<char,int> &a, const pair<char,int> &b) -> bool {
            return (a.second > b.second || (a.second == b.second && a.first < b.first));
        });

        printf("World #%d\n", t);
        for (int i = 0; i < 26; ++i)
        {
            if (lang[i].second)
                printf("%c: %d\n", lang[i].first, lang[i].second);
            else
                break;
        }

        //init
        for (int i = 0; i <= H; ++i)
            memset(visited[i], false, sizeof visited[i]);
    }

    return 0;
}