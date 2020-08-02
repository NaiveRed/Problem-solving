#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right)
  {
    int dis = 0, left_most = n;
    for (int x : right) // from left to the right
      left_most = min(x, left_most);
    dis = n - left_most;
    for (int x : left) // from right to the left
      dis = max(x, dis);
    return dis;
  }
};