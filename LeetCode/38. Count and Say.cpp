#include <bits/stdc++.h>
using namespace std;

string converse(const string &s) {
  int count = 1, size = s.size();
  string new_s;
  for (int i = 0; i < size; ++i) {
    if (i + 1 == size || s[i] != s[i + 1]) {
      // `count` should not greater than 3 since that
      // if s[n] is 42 then s[n-1] is 2222
      // But if it comes with same number > 3 continuously
      // s[n-2] will be 2222 is wrong.
      new_s += count + '0';
      new_s += s[i];
      count = 1;
    } else
      ++count;
  }
  return new_s;
}
class Solution {
 public:
  Solution() {
    say[1] = "1";
    for (int i = 2; i <= 30; ++i) {
      say[i] = converse(say[i - 1]);
    }
  }
  string say[31];
  string countAndSay(int n) { return say[n]; }
};
int main() {
  Solution solution;
  cout << solution.countAndSay(7) << endl;
  return 0;
}
