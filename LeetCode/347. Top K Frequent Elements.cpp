#include <bits/stdc++.h>
#define DEBUG
using namespace std;

class Solution
{
  // Method 1: heap
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    if (k == nums.size())
      return nums;
    // first: number, second: frequence
    unordered_map<int, int> counter;
    for (int &n : nums)
      if (counter.count(n))

        ++counter[n];
      else
        counter[n] = 1;

    // first: frequency, second: number
    typedef pair<int, int> FN;
    priority_queue<FN, vector<FN>, greater<FN>> pq;
    for (auto &p : counter)
    {
      pq.emplace(p.second, p.first);
      if (pq.size() > k)
        pq.pop();
    }
    vector<int> res(k);
    for (int i = 0; i < k; ++i)
    {
      res[i] = pq.top().second;
      pq.pop();
    }

    return res;
  }

  // Method 2: quick select
  // first: number, second: frequence
  unordered_map<int, int> counter;
  // keep the unique elements
  vector<int> result;

  // Lomuto Partition
  // Move the higher frequence (>pivot) to the left of the pivot
  // and less frequence to the right of the pivot.
  int partition(int l, int r)
  {
    int pivot = counter[result[r]], i = l;
    for (int j = l; j < r; ++j)
    {
      if (counter[result[j]] > pivot)
      {
        if (i != j)
          swap(result[i], result[j]);
        ++i;
      }
    }
    swap(result[r], result[i]);
    return i;
  }
  void quick_select(int l, int r, int k)
  {
    if (l == r)
      return;

    int pivot_idx = partition(l, r);
    if (pivot_idx > k - 1)
      quick_select(l, pivot_idx - 1, k);
    else if (pivot_idx < k - 1)
      quick_select(pivot_idx + 1, r, k);

    // if(pivot_idx == k-1) // Done
  }
  vector<int> topKFrequent1(vector<int> &nums, int k)
  {
    if (k == nums.size())
      return nums;

    result.clear();
    counter.clear();
    for (int &n : nums)
      if (counter.count(n))
        ++counter[n];
      else
      {
        counter[n] = 1;
        result.push_back(n);
      }

    if (k == result.size())
      return result;

    quick_select(0, result.size() - 1, k);

    return vector<int>(result.begin(), result.begin() + k);
  }
};