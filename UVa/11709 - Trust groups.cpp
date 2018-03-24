#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 1000
#define T 999000
using namespace std;

struct edge
{
    int v, next;
} E[T];
unordered_map<string, int> M;
int adj[N];
int visited[N], low[N], step;
int component;
bool in_stack[N];
int Stack[N], top;

void DFS(int u)
{
    visited[u] = low[u] = ++step;
    Stack[top++] = u;
    in_stack[u] = true;

    for (int i = adj[u]; i != -1; i = E[i].next)
    {
        int v = E[i].v;
        if (!visited[v])
            DFS(v);

        if (in_stack[v])
            low[u] = MIN(low[u], low[v]);
    }

    if (visited[u] == low[u])
    {
        ++component;
        while (true)
        {
            int v = Stack[--top];
            in_stack[v] = false;
            if (v == u)
                return;
        }
    }
}
int main()
{
    int P, t;
    char str[30];
    while (scanf("%d%d", &P, &t) && (P || t))
    {
        getchar();
        for (int i = 0; i < P; ++i)
        {
            fgets(str, 30, stdin);
            M[string(str)] = i;
        }

        memset(adj, -1, sizeof adj);
        int idx = 0;
        for (int i = 0; i < t; ++i)
        {
            int u, v;
            fgets(str, 30, stdin);
            u = M[string(str)];
            fgets(str, 30, stdin);
            v = M[string(str)];

            E[idx] = (edge){v, adj[u]};
            adj[u] = idx++;
        }

        for (int i = 0; i < P; ++i)
            if (!visited[i])
                DFS(i);

        printf("%d\n", component);

        //init
        top = component = step = 0;
        memset(visited, 0, sizeof visited);
        memset(low, 0, sizeof low);
    }

    return 0;
}