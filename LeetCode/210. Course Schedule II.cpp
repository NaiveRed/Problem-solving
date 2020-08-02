#include <bits/stdc++.h>
#define DEBUG
using namespace std;

class Solution
{
public:
  // Method 1: Kahn's algorithm
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    // The prerequisites will be the form: [a, b], the b is the prerequisite of a.
    // And we represent that in b -> a

    // Build adjacency list (b -> a)
    vector<vector<int>> adj_list(numCourses);
    // Incoming counter
    vector<int> incoming(numCourses);
    for (auto &p : prerequisites)
    {
      adj_list[p[1]].push_back(p[0]);
      ++incoming[p[0]];
    }

    vector<int> result;
    queue<int> no_incoming;
    for (int i = 0; i < numCourses; ++i)
      if (!incoming[i]) // Add the course with no incoming
        no_incoming.push(i);

    while (!no_incoming.empty())
    {
      int course = no_incoming.front();
      no_incoming.pop();
      result.push_back(course);

      for (int n : adj_list[course])
        if (!(--incoming[n])) // Add the course with no incoming
          no_incoming.push(n);
    }
    if (result.size() == numCourses)
      return result;
    return {};
  }

  // Method 2: DFS
  stack<int> result_stack;
  vector<int> findOrder1(int numCourses, vector<vector<int>> &prerequisites)
  {
    while (!result_stack.empty())
      result_stack.pop();

    vector<vector<int>> adj_list(numCourses);
    for (auto &p : prerequisites)
      adj_list[p[1]].push_back(p[0]);

    // DFS
    vector<int> status(numCourses); //0: not visited, 1: visited, 2: done
    // It may be forest (not connected together)
    for (int i = 0; i < numCourses; ++i)
    {
      if (!status[i] && !dfs(i, adj_list, status))
        return {};
    }

    // Find the order
    vector<int> order(numCourses);
    for (int i = 0; i < numCourses; ++i)
    {
      order[i] = result_stack.top();
      result_stack.pop();
    }
    return order;
  }

  bool dfs(int node, vector<vector<int>> &adj_list, vector<int> &status)
  {
    status[node] = 1; // Visited
    for (int neighbor : adj_list[node])
    {
      if (!status[neighbor] && !dfs(neighbor, adj_list, status))
        return false;
      else if (status[neighbor] == 1) // is cyclic
        return false;
    }
    status[node] = 2; // Done
    result_stack.push(node);
    return true;
  }
};