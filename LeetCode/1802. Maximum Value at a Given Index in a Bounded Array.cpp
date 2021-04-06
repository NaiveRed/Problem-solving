#include <bits/stdc++.h>
using namespace std;

// Binary search
class Solution {
 public:
  inline long long f_sum(int a1, int an) {
    return (long long)(a1 + an) * (an - a1 + 1) / 2;
  }
  inline long long calc(int x, int len) {
    int a1 = max(x - len, 1), remain = max(len - (x - 1), 0);
    return f_sum(a1, x) + remain;
  }
  int maxValue(int n, int index, long long maxSum) {
    int l = 1, r = maxSum, ans;
    while (l <= r) {
      int m = (l + r) / 2;
      long long sum = calc(m, index) + calc(m, n - index - 1) - m;
      if (sum <= maxSum) {
        ans = m;
        l = m + 1;
      } else if (sum > maxSum)
        r = m - 1;
    }
    return ans;
  }

  // Another way for binary searching.
  int maxValue1(int n, int index, long long maxSum) {
    int l = 1, r = maxSum;
    while (l < r) {
      int m = (1 + l + r) / 2;
      long long sum = calc(m, index) + calc(m, n - index - 1) - m;
      if (sum <= maxSum) {
        l = m;
      } else if (sum > maxSum)
        r = m - 1;
    }
    return l;
  }
};
int main() {
  Solution sol;
  sol.maxValue(4, 2, 6);
  return 0;
}
