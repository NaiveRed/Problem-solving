#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> backtracking(int begin, string &s, unordered_map<string, bool> &word_map, unordered_map<string, vector<string>> &sentence_map)
  {
    // If have already found the current string then return
    if (sentence_map.count(s.substr(begin)))
      return sentence_map[s.substr(begin)];

    vector<string> result_vector;
    for (int i = begin, len = s.size(); i < len; ++i)
    {
      // Try each substr whether matches or not
      string &&match = s.substr(begin, i - begin + 1);
      if (word_map.count(match))
      {
        // Add the result: match + [all combination of remain string]
        if (i != len - 1)
        {
          int m_size = match.size();
          match.insert(m_size, " ");
          for (string &sub_result : backtracking(i + 1, s, word_map, sentence_map))
            result_vector.push_back(string(match).insert(m_size + 1, sub_result));
        }
        else
          // Add the result: match
          result_vector.push_back(match);
      }
    }
    return sentence_map[s.substr(begin)] = result_vector;
  }
  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    unordered_map<string, vector<string>> sentence_map;
    unordered_map<string, bool> word_map;
    for (string &word : wordDict)
      word_map[word] = true;

    return backtracking(0, s, word_map, sentence_map);
  }
};