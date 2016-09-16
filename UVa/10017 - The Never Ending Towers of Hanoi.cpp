#include<cstdio>
#include<vector>
using namespace std;

vector<int>s[3];
char c[3] = { 'A','B','C' };
int step, m;
void print()
{
    int size;

    putchar('\n');
    for (int i = 0; i < 3; i++)
    {
        printf("%c=>", c[i]);
        if (!s[i].empty())
        {
            printf("   ");
            size = s[i].size();
            for (int j = 0; j < size - 1; j++)
                printf("%d ", s[i][j]);
            printf("%d", s[i].back());
        }
        putchar('\n');
    }
}
void solve(int n, int from, int buffer, int to)
{
    if (step == m)
        return;

    if (n == 1)//move only one disc from "from" to "to"
    {
        step++;
        s[to].push_back(s[from].back());
        s[from].pop_back();
        print();
    }
    else
    {
        solve(n - 1, from, to, buffer);//move n-1 discs form "from" to "buffer"
        if (step == m)
            return;
        step++;
        //move n-th disc from "from" to "to"
        s[to].push_back(s[from].back());
        s[from].pop_back();
        print();
        solve(n - 1, buffer, from, to);//move n-1 disc form "buffer" to "to"
    }
}
int main()
{
    int n, Case = 1;
    while (scanf("%d%d", &n, &m) && n)
    {
        printf("Problem #%d\n", Case++);
        step = 0;
        for (int i = n; i; i--)
            s[0].push_back(i);

        print();
        solve(n, 0, 1, 2);

        for (int i = 0; i < 3; i++)
            s[i].clear();

        putchar('\n');
    }

    return 0;
}