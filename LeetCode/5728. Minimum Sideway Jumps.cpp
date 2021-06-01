#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  inline int min3(int a, int b, int c) { return min(min(a, b), c); }
  int minSideJumps(vector<int>& obstacles) {
    int size = obstacles.size();
    int dp[size][3];  // number of side jumps.
    // Start from 1 (mid lane).
    dp[0][0] = dp[0][2] = 1;
    dp[0][1] = 0;
    for (int i = 1; i < size; ++i) {
      if (obstacles[i]) dp[i - 1][obstacles[i] - 1] = 1e9;
      dp[i][0] = obstacles[i] != 1
                     ? min3(dp[i - 1][0], dp[i - 1][1] + 1, dp[i - 1][2] + 1)
                     : 1e9;
      dp[i][1] = obstacles[i] != 2
                     ? min3(dp[i - 1][1], dp[i - 1][0] + 1, dp[i - 1][2] + 1)
                     : 1e9;
      dp[i][2] = obstacles[i] != 3
                     ? min3(dp[i - 1][2], dp[i - 1][0] + 1, dp[i - 1][1] + 1)
                     : 1e9;
      //   cout << i << ": " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2]
      //        << endl;
    }
    return min3(dp[size - 1][0], dp[size - 1][1], dp[size - 1][2]);
  }
};
