#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Method 1
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> m1;
        for (int n : nums1)
            m1[n] += 1;
        int i = 0;
        for (int n : nums2)
            if (m1.count(n) && m1[n])
            {
                --m1[n];
                ans.push_back(n);
            }
        return ans;
    }

    // Method 2
    vector<int> intersect2(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> m1, m2;
        for (int &n : nums1)
            m1[n] += 1;
        for (int &n : nums2)
            m2[n] += 1;
        for (pair<int, int> p : m1)
        {
            int times = min(p.second, m2[p.first]);
            for (int i = 0; i < times; ++i)
                ans.push_back(p.first);
        }
        return ans;
    }
};
