#include <bits/stdc++.h>
#define DEBUG
using namespace std;

class Solution
{
public:
  int countSquares(vector<vector<int>> &matrix)
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0, h = matrix.size(), w;
    if (h == 0)
      return 0;

    w = matrix[0].size();
    for (int r = 0; r < h; ++r)
      for (int c = 0; c < w; ++c)
      {
        // The first row and first column can not make square bigger than 1
        if (matrix[r][c] && r && c)
        {
          // After updating, the `matrix[r][c]` will be the number of square that
          // use (r, c) as the bottom-right point.
          matrix[r][c] += min({matrix[r - 1][c], matrix[r - 1][c - 1], matrix[r][c - 1]});
        }
        ans += matrix[r][c];
      }
    return ans;
  }
};