#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

vector<int> adjList[101];
bool visited[101];
inline int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' ' && c != '\n')
        n = n * 10 + c - '0';
    return n;
}
void dfs(int begin)
{
    stack<int> s;
    s.push(begin);
    //visited[begin] = true;// 起點不算走過
    while (!s.empty())
    {
        int u = s.top(), v;
        s.pop();

        int len = adjList[u].size();
        for (int i = 0; i < len; i++)
        {
            v = adjList[u][i];
            if (!visited[v])
            {
                s.push(v);
                visited[v] = true;
            }
        }
    }
}
int main()
{
    int vertex;
    while (scanf("%d", &vertex) != EOF && vertex)
    {
        getchar();

        int u, v;
        while (u = input())
            while (v = input())
                adjList[u].push_back(v);

        int n = input();
        while (n--)
        {
            int begin = input();
            dfs(begin);
            int count = 0, ans[100] = {};

            for (int i = 1; i <= vertex; i++)
                if (!visited[i])
                    ans[count++] = i;

            printf("%d", count);
            for (int i = 0; i < count; i++)
                printf(" %d", ans[i]);
            putchar('\n');

            memset(visited, false, sizeof visited);
        }

        //init        
        for (int i = 1; i <= vertex; i++)
            adjList[i].clear();
    }

    return 0;
}