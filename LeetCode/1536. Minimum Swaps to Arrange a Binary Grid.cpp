#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSwaps(vector<vector<int>> &grid)
  {
    int n = grid.size(), i, j;
    vector<int> one(n); // The idx of first one from the right to the left
    for (i = 0, j; i < n; ++i)
    {
      j = n - 1;
      while (j >= 0 && !grid[i][j])
        --j;
      one[i] = j;
    }

    int ans = 0;
    // From the top, since it need the most zeros
    for (i = 0; i < n; ++i)
    {
      int k = n - i - 1; // Need n - i - 1 zeros from the right to the left
      for (j = i; j < n; ++j)
        if (n - one[j] - 1 >= k)
        {
          ans += j - i;
          break;
        }

      if (j == n)
        return -1;

      while (j > i)
      {
        swap(one[j], one[j - 1]);
        --j;
      }
    }
    return ans;
  }
};