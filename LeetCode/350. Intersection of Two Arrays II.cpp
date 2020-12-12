#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> m1, m2;
    for (int& n : nums1) m1[n] += 1;
    for (int& n : nums2) m2[n] += 1;
    for (pair<int, int> p : m1) {
      int times = min(p.second, m2[p.first]);
      for (int i = 0; i < times; ++i) ans.push_back(p.first);
    }
    return ans;
  }
};
