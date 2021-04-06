#include <bits/stdc++.h>
using namespace std;
// Method 1: naive solution for 2 `if`s
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

// Method 2: unrolled the case in [i,i+14]
class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> vec(n + 1);
    int i;
    for (i = 1; i + 14 <= n; i += 15) {
      vec[i] = to_string(i);            // 1
      vec[i + 1] = to_string(i + 1);    // 2
      vec[i + 2] = "Fizz";              // 3
      vec[i + 3] = to_string(i + 3);    // 4
      vec[i + 4] = "Buzz";              // 5
      vec[i + 5] = "Fizz";              // 6
      vec[i + 6] = to_string(i + 6);    // 7
      vec[i + 7] = to_string(i + 7);    // 8
      vec[i + 8] = "Fizz";              // 9
      vec[i + 9] = "Buzz";              // 10
      vec[i + 10] = to_string(i + 10);  // 11
      vec[i + 11] = "Fizz";             // 12
      vec[i + 12] = to_string(i + 12);  // 13
      vec[i + 13] = to_string(i + 13);  // 14
      vec[i + 14] = "FizzBuzz";         // 15
    }
    while (i <= n) {
      if (i % 3 == 0)
        vec[i] = i % 5 == 0 ? "FizzBuzz" : "Fizz";
      else if (i % 5 == 0)
        vec[i] = "Buzz";
      else
        vec[i] = to_string(i);
      ++i;
    }
    vec.erase(vec.begin());  // Start from zero idx

    return vec;
  }
};
