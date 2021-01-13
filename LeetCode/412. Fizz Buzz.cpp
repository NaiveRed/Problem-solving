#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> vec(n);

    for (int i = 1; i <= n; ++i) {
      if (i % 3 == 0)
        vec[i - 1] = i % 5 == 0 ? "FizzBuzz" : "Fizz";
      else if (i % 5 == 0)
        vec[i - 1] = "Buzz";
      else
        vec[i - 1] = to_string(i);
    }

    return vec;
  }
};
