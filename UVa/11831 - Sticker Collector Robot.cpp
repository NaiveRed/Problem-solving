#include <cstdio>
#include <cstring>

int main()
{

  int N, M, S;
  char arena[102][102] = {};
  //dir: North, East, South, West
  int row, col, ori, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  while (scanf("%d%d%d", &N, &M, &S) && N)
  {
    for (int i = 0; i <= N + 1; ++i)
      memset(arena, ' ', M);
    getchar();
    for (int i = 1; i <= N; ++i)
    {
      for (int j = 1; j <= M; ++j)
      {
        char c = getchar();
        if (c == 'N')
          c = ' ', row = i, col = j, ori = 0;
        else if (c == 'S')
          c = ' ', row = i, col = j, ori = 2;
        else if (c == 'L')
          c = ' ', row = i, col = j, ori = 1;
        else if (c == 'O')
          c = ' ', row = i, col = j, ori = 3;
        arena[i][j] = c;
      }
      getchar();
    }

    int new_r, new_c, sticker = 0;
    for (int i = 0; i < S; ++i)
    {
      char c = getchar();
      if (c == 'D')
        ori = (ori + 1) % 4;
      else if (c == 'E')
        ori = ori ? ori - 1 : 3;
      else if (c == 'F')
      {
        new_r = dir[ori][0] + row;
        new_c = dir[ori][1] + col;
        if (arena[new_r][new_c] == '#' || !new_r || new_r > N || !new_c || new_c > M)
          continue;

        row = new_r;
        col = new_c;
        if (arena[row][col] == '*')
        {
          ++sticker;
          arena[row][col] = ' ';
        }
      }
    }
    getchar();

    printf("%d\n", sticker);
  }
  return 0;
}