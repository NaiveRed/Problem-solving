#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

struct team
{
    char name[31];
    int pt, games, win, loss, score, against;
    void clear()
    {
        memset(name, '\0', sizeof name);
        pt = games = win = loss = score = against = 0;
    }
    int diff() const
    {
        return score - against;
    }
    int tie()
    {
        return games - win - loss;
    }
    bool lex_order(const team &t) const
    {
        int i;
        for (i = 0; name[i] && t.name[i]; i++)
            if (tolower(name[i]) < tolower(t.name[i]))
                return true;
            else if (tolower(name[i]) > tolower(t.name[i]))
                return false;

        return name[i] == '\0' ? true : false; //短的先
    }
    bool operator<(const team &t) const
    {
        if (pt != t.pt)
            return pt > t.pt;
        else if (win != t.win)
            return win > t.win;
        else if (diff() != t.diff())
            return diff() > t.diff();
        else if (score != t.score)
            return score > t.score;
        else if (games != t.games)
            return games < t.games;
        else
            return lex_order(t);
    }
};

unordered_map<string, int> map;
team teams[30];
void input()
{
    char s1[31], s2[31], c;
    int g1 = 0, g2 = 0, i = 0;
    while ((c = getchar()) != '#')
        s1[i++] = c;
    s1[i] = '\0';

    while ((c = getchar()) != '@')
        g1 = g1 * 10 + c - '0';
    while ((c = getchar()) != '#')
        g2 = g2 * 10 + c - '0';

    i = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        s2[i++] = c;
    s2[i] = '\0';

    int id1 = map[string(s1)], id2 = map[string(s2)];
    teams[id1].games++;
    teams[id2].games++;
    teams[id1].score += g1;
    teams[id2].score += g2;
    teams[id1].against += g2;
    teams[id2].against += g1;
    if (g1 > g2)
    {
        teams[id1].pt += 3;
        teams[id1].win++;
        teams[id2].loss++;
    }
    else if (g2 > g1)
    {
        teams[id2].pt += 3;
        teams[id2].win++;
        teams[id1].loss++;
    }
    else //tie
    {
        ++teams[id1].pt;
        ++teams[id2].pt;
    }
}
int main()
{
    //freopen("test.out", "w", stdout);
    int N;
    char tournament[105];
    scanf("%d ", &N);
    while (N--)
    {
        gets(tournament);
        puts(tournament);

        int T, G;

        scanf("%d ", &T);
        for (int i = 0; i < T; ++i)
        {
            teams[i].clear();
            gets(teams[i].name);
            map[string(teams[i].name)] = i;
        }

        scanf("%d ", &G);
        for (int i = 0; i < G; ++i)
            input();

        sort(teams, teams + T);
        for (int i = 0; i < T; ++i)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, teams[i].name, teams[i].pt, teams[i].games,
                   teams[i].win, teams[i].tie(), teams[i].loss, teams[i].diff(), teams[i].score, teams[i].against);

        if (N)
            putchar('\n');

        map.clear();
    }
    return 0;
}