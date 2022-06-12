#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        int count[1001] = {};
        for (const auto& arr : nums)
            for (const auto& n : arr)
                ++count[n];

        vector<int> ans;
        for (int i = 0; i < 1001; ++i)
            if (count[i] == n)
                ans.push_back(i);
        return ans;
    }
};

int main() {
#ifdef DEBUG
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
#endif
    // Solution solution;
    // string s;
    // int k;
    // while (cin >> s >> k)
    //     printf("%d\n", solution.hasAllCodes(s, k));

    return 0;
}
