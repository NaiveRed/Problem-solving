#include <bits/stdc++.h>
using namespace std;

// Method 1: DFS, recursive
class Solution {
 public:
  // up, down, left, right
  const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int dfs(vector<vector<int>>& grid, int r, int c) {
    grid[r][c] = -1;  // Mark as visited
    int area = 1;     // Current land
    for (int i = 0; i < 4; ++i) {
      int r2 = r + dir[i][0], c2 = c + dir[i][1];
      if (r2 < 0 || r2 >= grid.size() || c2 < 0 || c2 >= grid[0].size())
        continue;
      if (grid[r2][c2] == 1) area += dfs(grid, r2, c2);
    }
    return area;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size();
    int max_area = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        if (grid[i][j] == 1) max_area = max(max_area, dfs(grid, i, j));
      }
    return max_area;
  }
};

// Method 2: DFS, iterative
class Solution1 {
 public:
  // up, down, left, right
  const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0, area = 0;
    stack<pair<int, int>> S;
    int max_r = grid.size(), max_c = grid[0].size();

    for (int i = 0; i < max_r; ++i)
      for (int j = 0; j < max_c; ++j) {
        if (grid[i][j] != 1) continue;
        int area = 0;
        S.push({i, j});
        grid[i][j] = -1;
        while (!S.empty()) {
          int r = S.top().first, c = S.top().second;
          S.pop();
          ++area;
          for (int k = 0; k < 4; ++k) {
            int r2 = r + dir[k][0], c2 = c + dir[k][1];
            if (r2 < 0 || r2 >= max_r || c2 < 0 || c2 >= max_c) continue;
            if (grid[r2][c2] == 1) {
              S.push({r2, c2});
              grid[r2][c2] = -1;
            };
          }
        }
        max_area = max(max_area, area);
      }
    return max_area;
  }
};
