#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Method 1: In-place
  inline void removeLeadingSpace(string &s)
  {
    int i = 0;
    while (s[i] == ' ')
      ++i;
    if (i)
      s.erase(0, i);
  }
  string reverseWords(string s)
  {
    removeLeadingSpace(s); //Remove leading spaces
    reverse(s.begin(), s.end());
    removeLeadingSpace(s); //Remove trailing spaces

    int blank_start = -1, word_start = -1;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] != ' ')
      {
        if (blank_start != -1)
        {
          if (i - blank_start > 1)
          {
            int blank_count = i - blank_start - 1;
            s.erase(blank_start, blank_count);
            i -= blank_count; // The number of blank we remove
          }
          blank_start = -1;
        }

        if (word_start == -1)
          word_start = i;
      }
      else
      {
        if (word_start != -1)
        {
          reverse(s.begin() + word_start, s.begin() + i);
          word_start = -1;
        }
        if (blank_start == -1)
          blank_start = i;
      }
    }

    // Final word
    if (word_start != -1)
      reverse(s.begin() + word_start, s.end());

    return s;
  }

  // Method 2:
  string reverseWords2(string s)
  {
    int leading = s.find_first_not_of(' ', 0), trailing = s.find_last_not_of(' ');
    if (leading == string::npos)
      return "";

    //Remove leading and trailing spaces
    s = string(s.begin() + leading, s.begin() + 1 + trailing);
    reverse(s.begin(), s.end());

    string::iterator s_begin = s.begin();
    int idx = 0, word_start, word_end = -1;
    string new_s;
    while (true)
    {
      word_start = s.find_first_not_of(' ', idx);
      word_end = s.find_first_of(' ', word_start);
      if (word_end != string::npos)
      {
        reverse(s_begin + word_start, s_begin + word_end);
        new_s.append(s_begin + word_start, s_begin + word_end + 1); // 1 for space
        idx = word_end;
      }
      else
      {
        reverse(s_begin + word_start, s.end());
        new_s.append(s_begin + word_start, s.end());
        break;
      }
    }
    return new_s;
  }
};