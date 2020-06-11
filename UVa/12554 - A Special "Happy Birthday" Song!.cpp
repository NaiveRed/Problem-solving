#include <cstdio>
#include <cstring>

int main()
{
  int n;
  char name[100][105];
  char song[16][10] = {"Happy", "birthday", "to", "you",
                       "Happy", "birthday", "to", "you",
                       "Happy", "birthday", "to", "Rujia",
                       "Happy", "birthday", "to", "you"};
  bool flags[100] = {};
  scanf("%d ", &n);
  for (int i = 0; i < n; ++i)
  {
    fgets(name[i], 105, stdin);
    name[i][strlen(name[i]) - 1] = '\0';
  }

  int song_idx = 0, name_idx = 0;
  // Every one need to song once
  for (; name_idx < n; ++name_idx, song_idx = (song_idx + 1) % 16)
    printf("%s: %s\n", name[name_idx], song[song_idx]);

  // Don't stop in the middle
  for (name_idx %= n; song_idx; name_idx = (name_idx + 1) % n, song_idx = (song_idx + 1) % 16)
    printf("%s: %s\n", name[name_idx], song[song_idx]);

  return 0;
}