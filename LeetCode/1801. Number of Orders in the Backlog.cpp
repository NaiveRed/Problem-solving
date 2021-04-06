#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> order_pair;  // price, amount
bool cmp(const order_pair& a, const order_pair& b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second > b.second;
}
class Solution {
 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    priority_queue<order_pair, vector<order_pair>,
                   bool (*)(const order_pair&, const order_pair&)>
        buy(cmp);
    priority_queue<order_pair, vector<order_pair>, greater<order_pair>> sell;
    for (auto& order : orders) {
      if (order[2])  // Sell
      {
        while (!buy.empty() && order[1] > 0) {
          order_pair top = buy.top();  // largest
          if (top.first >= order[0]) {
            int tmp = top.second;
            top.second -= order[1];
            order[1] -= tmp;  // Remaining order of current sell
            buy.pop();
            if (top.second > 0) {
              buy.push(top);  // Remaining order of buy
            } else if (top.second == 0)
              break;
          } else
            break;
        }
        if (order[1] > 0) sell.push({order[0], order[1]});
      } else  // Buy
      {
        while (!sell.empty() && order[1] > 0) {
          order_pair top = sell.top();  // smallest
          if (top.first <= order[0]) {
            int tmp = top.second;
            top.second -= order[1];
            order[1] -= tmp;
            sell.pop();
            if (top.second > 0) {
              sell.push(top);
            } else if (top.second == 0)
              break;
          } else
            break;
        }
        if (order[1] > 0) buy.push({order[0], order[1]});
      }
    }

    int amount = 0, mod = 1e9 + 7;
    while (!buy.empty()) {
      amount = (amount + buy.top().second) % mod;
      buy.pop();
    }
    while (!sell.empty()) {
      amount = (amount + sell.top().second) % mod;
      sell.pop();
    }
    return amount;
  }
};
