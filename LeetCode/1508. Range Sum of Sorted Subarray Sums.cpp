#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> int_pair;
bool cmp(const int_pair& a, const int_pair& b) { return a.first > b.first; }
class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    priority_queue<int_pair, vector<int_pair>,
                   bool (*)(const int_pair&, const int_pair&)>
        pq(cmp);

    // .first: current cumulative sum.
    // .second: index of next number to be added.
    for (int i = 0; i < n; ++i) pq.push({nums[i], i + 1});
    int sum = 0, mod = 1e9 + 7;
    for (int i = 1; i <= right; ++i) {
      int_pair p = pq.top();
      pq.pop();
      if (i >= left) sum = (sum + p.first) % mod;
      if (p.second < n) pq.push({p.first + nums[p.second], p.second + 1});
    }
    return sum;
  }
};
