//ref: http://www.csie.ntnu.edu.tw/~u91029/Component.html#4
#include <cstdio>
#include <cstring>
//#include <stack>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define N 100001

struct edge
{
    int v, next;
} E[N];
int adj[N]; //adjacent list
int low[N], visited[N];
int step;

bool in_stack[N];
//std::stack<int> S;
int Stack[N], top;
int contract[N], component; //收縮的點, 收縮後的點數
bool in_deg[N];             //有無入邊(in-edge)
//int have_in;

inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
void DFS(int u)
{
    visited[u] = low[u] = ++step;
    //S.push(u);
    Stack[top++] = u;
    in_stack[u] = true;

    for (int i = adj[u]; i != -1; i = E[i].next)
    {
        int v = E[i].v;
        if (!visited[v]) //tree edge
            DFS(v);

        if (in_stack[v]) //已經走過但還未成 SCC 的點
            low[u] = MIN(low[u], low[v]);
        else //連到一個 SCC，該 SCC 就有了入邊
            in_deg[contract[v]] = true;

        /*else if(!in_deg[contract[v]])
        {
            in_deg[contract[v]] = true;
            ++have_in;
        }*/
    }

    //形成 SCC，將整串(也可能一點)從 DFS tree 中移除
    if (visited[u] == low[u]) //u 是 SCC 中最早拜訪的點
    {
        ++component;
        while (true)
        {
            /*int v = S.top();
            S.pop();*/
            int v = Stack[--top];
            in_stack[v] = false;
            contract[v] = component; //記下該收縮點

            if (v == u)
                break;
        }
    }
}
int main()
{
    //freopen("test.out","w",stdout);
    int n, m, Case;
    scanf("%d ", &Case);
    while (Case--)
    {
        memset(adj, -1, sizeof adj);
        //scanf("%d%d", &n, &m);
        n = read();
        m = read();
        int u, v, idx = 0;
        for (int i = 0; i < m; ++i)
        {
            //scanf("%d%d", &u, &v);
            u = read();
            v = read();
            E[idx] = (edge){v, adj[u]}; //u -> v
            adj[u] = idx++;
        }

        for (int i = 1; i <= n; ++i)
            if (!visited[i])
                DFS(i);

		//(已在DFS中計算)
        //用每個邊計算各收縮後點的入邊數(超過 1 就不用再算)
        /*for (u = 1; u <= n; ++u)
            for (int i = adj[u]; i != -1; i = E[i].next)
            {
                //u -> v
                int v = E[i].v;

                if (contract[u] != contract[v] && !in_deg[contract[v]])
                    in_deg[contract[v]] = true;
            }*/

        int ans = 0;
        for (int i = 1; i <= component; ++i)
            if (!in_deg[i])
                ++ans;

        printf("%d\n", ans);

        //printf("%d\n", component - have_in);

        //init
        top = component = step = 0;
        memset(visited, 0, sizeof visited);
        memset(in_deg, false, N);
        memset(in_stack, false, N);
        //have_in = 0;
        //memset(low, 0, sizeof low);
        //memset(contract,0,sizeof contract);
    }

    return 0;
}