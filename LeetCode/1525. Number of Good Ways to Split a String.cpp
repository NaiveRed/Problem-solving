#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSplits(string s)
  {
    int s_len = s.size();
    if (s_len < 2)
      return 0;
    vector<int> l_to_r(s_len), r_to_l(s_len);
    bool table1[26] = {}, table2[26] = {};
    table1[s[0] - 'a'] = true;
    l_to_r[0] = 1;
    for (int i = 1; i < s_len; ++i)
    {
      if (table1[s[i] - 'a'])
        l_to_r[i] = l_to_r[i - 1];
      else
      {
        l_to_r[i] = l_to_r[i - 1] + 1;
        table1[s[i] - 'a'] = true;
      }
    }

    table2[s[s_len - 1] - 'a'] = true;
    r_to_l[s_len - 1] = 1;
    for (int i = s_len - 2; i >= 0; --i)
    {
      if (table2[s[i] - 'a'])
        r_to_l[i] = r_to_l[i + 1];
      else
      {
        r_to_l[i] = r_to_l[i + 1] + 1;
        table2[s[i] - 'a'] = true;
      }
    }
    int ans = 0;
    for (int i = 0; i < s_len - 1; ++i)    
      if (l_to_r[i] == r_to_l[i + 1])
        ++ans;    
    return ans;
  }
};