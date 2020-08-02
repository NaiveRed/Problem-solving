#include <bits/stdc++.h>
using namespace std;

typedef pair<double, int> Node;
class Solution
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {
    vector<vector<Node>> adj_list(n);
    vector<bool> is_visit(n);
    vector<double> dis(n, 0);
    priority_queue<Node> pq;
    for (int i = 0; i < edges.size(); ++i)
    {
      vector<int> &e = edges[i];
      adj_list[e[0]].emplace_back(succProb[i], e[1]);
      adj_list[e[1]].emplace_back(succProb[i], e[0]);
    }

    dis[start] = 1;
    pq.emplace(dis[start], start);

    for (int i = 0; i < n; ++i)
    {
      int next = -1;
      while (!pq.empty() && is_visit[next = (pq.top().second)])
        pq.pop();
      if (next == -1 || next == end)
        break;
      is_visit[next] = true;
      for (auto &v : adj_list[next])
      {
        if (!is_visit[v.second] && dis[next] * v.first > dis[v.second])
        {
          dis[v.second] = dis[next] * v.first;
          pq.emplace(dis[v.second], v.second);
        }
      }
    }
    if (abs(dis[end] - 0.0) <= 1e-5)
      return (double)0.0;
    else
      return dis[end];
  }
};