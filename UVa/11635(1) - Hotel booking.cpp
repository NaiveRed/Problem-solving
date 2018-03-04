#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 10001
#define E 600
using namespace std;

struct node
{
    int v, w;
    node(int a, int b) : v(a), w(b) {}
};

vector<node> adj_list[N]; //[i]: i -> v, time: w
int n;                    //number of cities
int n_to_hotel[N];        //map, index to city id which has hotel. (1: 1, 2: n)

int hotel[105][105] = {}; //the new adj_matrix of hotels(include 1 and n)

int d[N]; //time from source to each city
bool inQ[N];
//int parent[N]; 不處理反而比較快
void SPFA(int source)
{
    //init
    memset(inQ, false, sizeof inQ);
    fill(d, d + n + 1, 1e9);

    queue<node> Q;
    Q.emplace(source, 0);
    d[source] = 0;

    while (!Q.empty())
    {
        int now = Q.front().v;
        Q.pop();
        inQ[now] = false;

        for (node next : adj_list[now])
        {
            int tmp = d[now] + next.w;
            if (tmp < d[next.v])
            {
                d[next.v] = tmp;

                if (!inQ[next.v])
                {
                    Q.emplace(next.v, tmp);
                    inQ[next.v] = true;
                }
            }
        }
    }
}
inline int input()
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
    int h, m;
    while (scanf("%d", &n) && n)
    {
        scanf("%d ", &h);
        int tmp, idx = 2;

        //take 1 and n as a hotel for the convenience of the new adjacency matrix
        n_to_hotel[1] = 1;
        n_to_hotel[2] = n;
        for (int i = 0; i < h; ++i)
        {
            //scanf("%d", &tmp);
            tmp = input();
            n_to_hotel[++idx] = tmp;
        }

        scanf("%d ", &m);
        int u, v, w;
        for (int i = 0; i < m; ++i)
        {
            //scanf("%d%d%d", &u, &v, &w);
            u = input();
            v = input();
            w = input();
            adj_list[u].emplace_back(v, w);
            adj_list[v].emplace_back(u, w);
        }

        //build the new adj_matrix of hotels(include 1 and n)
        for (int i = 1; i <= idx; ++i)
            for (int j = 1; j <= idx; ++j)
                hotel[i][j] = 1e9;

        for (int i = 1; i <= idx; ++i)
        {
            hotel[i][i] = 0;
            SPFA(n_to_hotel[i]);

            for (int j = 1; j <= idx; ++j)
                if (i != j && d[n_to_hotel[j]] <= E)
                    hotel[i][j] = 1;
        }

        //Floyd-Warshall
        for (int k = 1; k <= idx; ++k)
            for (int i = 1; i <= idx; ++i)
                for (int j = 1; j <= idx; ++j)
                    if (hotel[i][k] + hotel[k][j] < hotel[i][j])
                        hotel[i][j] = hotel[i][k] + hotel[k][j];

        //Minus one, since he does not need to spend the night in the destination (n).
        printf("%d\n", hotel[1][2] != 1e9 ? (hotel[1][2] - 1) : -1);

        //init
        memset(hotel, 0, sizeof hotel);
        for (int i = 1; i <= n; ++i)
            adj_list[i].clear();
    }

    return 0;
}