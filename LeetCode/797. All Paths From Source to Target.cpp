#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(int node, vector<vector<int>> &graph)
  {
    path.push_back(node);
    for (int &v : graph[node])
    {
      if (v == graph.size() - 1)
      {
        result.push_back(path);
        result.back().push_back(v);
      }
      else
        backtracking(v, graph);
    }
    path.pop_back();
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    result.clear();
    backtracking(0, graph);
    return result;
  }
};