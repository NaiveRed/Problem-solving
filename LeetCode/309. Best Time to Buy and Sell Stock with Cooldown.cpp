#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    /*    
    hold_state(s0): state after ``buy`` from `rest_state` or state stay in `hold_state`
    sell_state(s1): state after ``sell`` from `hold_state`
    rest_state(s2): state after ``rest`` or state stay in `rest_state`
    */
    int hold_state = numeric_limits<int>::min(), sell_state = 0, rest_state = 0;
    for (int &p : prices)
    {      
      // Can simplify to:
      int prev_hold = hold_state;
      hold_state = max(hold_state, rest_state - p);
      rest_state = max(rest_state, sell_state);
      sell_state = prev_hold + p; 
    }
    return max(sell_state, rest_state);
  }
};