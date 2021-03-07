#include <bits/stdc++.h>
using namespace std;
#define MOD 18446744073709551557ULL

// (24 ms) Method 1: use prime number to encode the string
class Solution {
 public:
  int prime[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                   43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<uint64_t, vector<string>> group;
    for (string& str : strs) group[encode(str)].push_back(str);

    vector<vector<string>> res;
    for (auto& p : group) res.push_back(p.second);
    return res;
  }

  uint64_t encode(string& s) {
    uint64_t n = 1;
    for (char& c : s) n = (n * prime[c - 'a']) % MOD;
    return n;
  };
};

// (28 ms) Method 2: use sorted string to encode the string (counting sort)
class Solution2 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> group;
    for (string& str : strs) group[encode(str)].push_back(str);

    vector<vector<string>> res;
    for (auto& p : group) res.push_back(p.second);
    return res;
  }

  string encode(const string& s) {
    string sorted;
    int count[26] = {};
    for (const char& c : s) ++count[c - 'a'];
    for (int i = 0; i < 26; ++i)
      if (count[i]) sorted += string(count[i], 'a' + i);
    return sorted;
  };
};
