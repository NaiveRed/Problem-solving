#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
public:
  int p;
  vector<vector<int>> buckets;
  /** Initialize your data structure here. */
  MyHashSet() : p(2003), buckets(p)
  {
  }

  int probing(int idx, int key)
  {
    for (int i = 0; i < buckets[idx].size(); ++i)
      if (key == buckets[idx][i])
        return i;
    return -1;
  }
  int hash(int key)
  {
    return key % p;
  }
  void add(int key)
  {
    int b_idx = hash(key);
    if (probing(b_idx, key) == -1)
      buckets[b_idx].push_back(key);
  }

  void remove(int key)
  {
    int b_idx = hash(key), pos = probing(b_idx, key);
    if (pos != -1)
      buckets[b_idx].erase(buckets[b_idx].begin() + pos);
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key)
  {
    return probing(hash(key), key) != -1;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */