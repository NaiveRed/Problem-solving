#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int min_dis = 1e9, min_idx = -1;
    for (int i = 0, s = points.size(); i < s; ++i) {
      if (points[i][0] == x || points[i][1] == y) {
        int dis = abs(points[i][0] - x) + abs(points[i][1] - y);
        if (dis < min_dis) {
          min_dis = dis;
          min_idx = i;
        }
      }
    }
    return min_idx != -1 ? min_idx : -1;
  }
};
