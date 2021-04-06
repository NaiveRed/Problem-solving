#include <bits/stdc++.h>
using namespace std;

// Method: Matrix Chain Multiplication
// dp[i][j]: means the max coins between (i, j) (**exclude** i and j)
// Base case: dp[i][i] = 0
// i<k<j
// dp[i][j]: max(dp[i][j],
//               dp[i][k] + dp[k][j] + ball[i]*ball[k]*ball[j])
//           k: means the **final** balloons we burst,
//           so its points will base on the most left and most right
//           which have not bursted yet, i.e., ball[i] and ball[j]
// We need to build the table bottom-up:
// count=0: dp[1][2], dp[2][3], dp[3][4], ... (all zero)
// count=1. dp[1][3], dp[2][4], dp[3][5], ...

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int size = nums.size();
    int balloons[size + 2];

    // Remove zero balloons (pruned)
    // Bound (i.e. 1, B1, B2, ..., Bn, 1)
    balloons[0] = 1;  // Add the bound
    int n = 1;
    for (int i = 0; i < size; ++i)
      if (nums[i]) balloons[n++] = nums[i];
    balloons[n++] = 1;  // Add the bound
    size = n;

    int dp[size][size];
    // The following code will not come to left==right
    // for (int i = 0; i < size; ++i) dp[i][i] = 0;

    // Find the max coins between (left, left+count+1) (exclude i and i+count+1)
    // E.g., 1 a b c d 1: (0, 0+4+1)
    // size - 2: the number of pruned balloons
    for (int count = 0; count <= size - 2; ++count) {
      // left<k<right
      for (int left = 0; left < size - 1 - count; ++left) {
        int right = left + 1 + count;
        // cout << count << " " << left << " " << right << endl;
        dp[left][right] = 0;
        for (int k = left + 1; k < right; ++k)
          dp[left][right] =
              max(dp[left][right],
                  dp[left][k] + dp[k][right] +
                      balloons[left] * balloons[k] * balloons[right]);
      }
    }

    return dp[0][size - 1];
  }
};
