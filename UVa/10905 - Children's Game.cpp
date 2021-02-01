#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool cmp(const string& a, const string& b) {
  int a_len = a.size(), b_len = b.size();
  for (int i = 0, j = 0; i < a_len + b_len; ++i, ++j) {
    int diff = a[i % a_len] - b[j % b_len];
    if (diff > 0)
      return true;
    else if (diff < 0)
      return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string nums[50];
  while (cin >> n && n) {
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums, nums + n, cmp);
    for (int i = 0; i < n; ++i) cout << nums[i];
    cout << '\n';
  }
  return 0;
}
