#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
  int board_r, board_c;
  bool dfs(int r, int c, int word_idx, vector<vector<char>> &board, string &word)
  {
    if (word_idx >= word.size())
      return true;

    for (int i = 0; i < 4; ++i)
    {
      int r2 = r + dir[i][0], c2 = c + dir[i][1];
      if (r2 < 0 || r2 >= board_r || c2 < 0 || c2 >= board_c)
        continue;
      if (word[word_idx] == board[r2][c2])
      {
        char tmp = board[r2][c2];
        board[r2][c2] = ' ';
        if (dfs(r2, c2, word_idx + 1, board, word))
          return true;
        board[r2][c2] = tmp;
      }
    }
    return false;
  }
  bool exist(vector<vector<char>> &board, string word)
  {
    board_r = board.size(), board_c = board[0].size();
    for (int i = 0; i < board_r; ++i)
      for (int j = 0; j < board_c; ++j)
        if (board[i][j] == word[0])
        {
          char tmp = board[i][j];
          board[i][j] = ' ';
          if (dfs(i, j, 1, board, word))
            return true;
          board[i][j] = tmp;
        }
    return false;
  }
};