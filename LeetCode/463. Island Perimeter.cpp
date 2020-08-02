#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int r = grid.size(), c = grid[0].size(), count = 0, shared = 0;
    for (int k = 0; k < r; ++k)
    {
      for (int i = 0; i < c; ++i)
      {
        if (grid[k][i])
        {
          ++count;
          // Check the horizontal wall
          if (i + 1 < c && grid[k][i + 1])
            ++shared;
          // Check the vertical wall
          if (k + 1 < r && grid[k + 1][i])
            ++shared;
        }
      }
    }
    return count * 4 - shared * 2;
  }

  // Method 2:
  int islandPerimeter1(vector<vector<int>> &grid)
  {
    int r = grid.size(), c = grid[0].size(), ans = 0;
    for (int k = 0; k < r; ++k)
    {
      for (int i = 0; i < c; ++i)
      {
        if (grid[k][i])
        {
          // Check the horizontal land
          if ((i + 1 < c && !grid[k][i + 1]))
            ++ans;
          // Check the vertical land
          if ((k + 1 < r && !grid[k + 1][i]) || k + 1 == r)
            ++ans;
        }
      }

      if (grid[k][c - 1])
        ++ans;
    }

    return ans * 2;
  }
};