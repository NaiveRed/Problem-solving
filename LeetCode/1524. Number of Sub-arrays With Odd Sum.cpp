#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
class Solution
{
public:
  int numOfSubarrays(vector<int> &arr)
  {    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int prev_odd_count = arr[0] & 1;
    int count = prev_odd_count;
    for (int i = 1, s = arr.size(); i < s; ++i)
    {
      int odd_count = prev_odd_count; // arr[i] is even
      if (arr[i] & 1) // arr[i] is odd
        odd_count = 1 + (i - prev_odd_count);      
      count = (count + odd_count) % MOD;
      prev_odd_count = odd_count;
    }
    return count;
  }
};