//參考:http://www.csie.ntnu.edu.tw/~u91029/Component.html#1
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define N 100
using namespace std;

int visited[N]; //order of dfs
int low[N];     //用 back edge 能連到的最高祖先(step 小的)
int step;       //currently order of dfs
int n;
bool adj[N][N];
string name[N];
vector<string> ans;
void DFS(int p, int i) //p -> i
{
    low[i] = visited[i] = ++step;
    int child = 0;
    bool ap = false;
    for (int v = 0; v < n; ++v) //i -> v
    {
        if (adj[i][v] && v != p)
        {
            if (visited[v]) //back edge
                low[i] = min(low[i], visited[v]);
            else //tree edge
            {
                ++child;
                DFS(i, v);
                low[i] = min(low[i], low[v]);
                if (low[v] >= visited[i]) //i is AP, since it has no back edge.
                    ap = true;
            }
        }
    }

    /*
    1.不是根，不是根的才能用 ap = true 判斷
	2.根，要由子節點數量判斷是否為 AP	
	*/
    if ((i != p && ap) || (p == i && child > 1))
        ans.push_back(name[i]);
}
int main()
{
    //freopen("test.out", "w", stdout);
    char str1[35], str2[35];
    int Case = 0;

    while (scanf("%d", &n) && n)
    {
        getchar();
        unordered_map<string, int> M;
        for (int i = 0; i < n; ++i)
        {
            fgets(str1, 35, stdin);
            str1[strlen(str1) - 1] = '\0';
            name[i] = string(str1);
            M[name[i]] = i;
        }

        int r;
        scanf("%d", &r);
        for (int i = 0; i < r; ++i)
        {
            scanf("%s%s", str1, str2);
            int a = M[string(str1)], b = M[string(str2)];
            adj[a][b] = adj[b][a] = true;
        }

        //find articulation vertex
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                DFS(i, i);

        sort(ans.begin(), ans.end()); //照字典序
        int len = ans.size();
        if (Case)
            putchar('\n');
        printf("City map #%d: %d camera(s) found\n", ++Case, len);
        for (int i = 0; i < len; ++i)
            puts(ans[i].c_str());

        //init
        for (int i = 0; i < n; ++i)
            memset(adj[i], 0, sizeof adj[i]);
        memset(visited, 0, sizeof visited);
        memset(low, 0, sizeof low);
        ans.clear();
        step = 0;
    }
    return 0;
}