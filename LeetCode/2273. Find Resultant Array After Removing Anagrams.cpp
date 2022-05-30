#include <bits/stdc++.h>
using namespace std;

// Method 1: count char eahc check
class Solution1 {
  public:
    bool check(const string& a, const string& b) {
        int count[26] = {};
        for (const char& c : a)
            ++count[c - 'a'];
        for (const char& c : b)
            --count[c - 'a'];
        for (const int& i : count)
            if (i != 0)
                return false;
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans = {words[0]};
        for (int i = 1, n = words.size(); i < n; ++i) {
            if (!check(words[i], ans.back())) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
// Method 2: use sorted to check anagrams
class Solution2 {
  public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans = {words[0]};
        string sorted = words[0];
        sort(sorted.begin(), sorted.end());
        for (const string& s : words) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if (tmp != sorted) {
                ans.push_back(s);
                sorted = tmp;
            }
        }
        return ans;
    }
};

