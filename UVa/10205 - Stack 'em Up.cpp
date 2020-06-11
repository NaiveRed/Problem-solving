#include <cstdio>

int main()
{
  int T, n;
  int mapping[100][53] = {}, deck[53], tmp_deck[53];
  char str[5];
  char idx_to_suit[][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  char idx_to_value[][6] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

  scanf("%d", &T);
  while (T--)
  {
    // Init the deck
    for (int i = 0; i < 53; ++i)
      deck[i] = i;

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i)
      for (int j = 1; j < 53; ++j)
        scanf("%d", &mapping[i][j]);
    getchar();

    int *p_deck = deck, *p_tmp = tmp_deck, k;
    while (fgets(str, 10, stdin) && str[0] != '\n')
    {
      int k;
      sscanf(str, "%d", &k);
      for (int i = 1; i < 53; ++i)
        p_tmp[i] = p_deck[mapping[k - 1][i]];

      int *p = p_deck;
      p_deck = p_tmp;
      p_tmp = p;
    }

    for (int i = 1; i < 53; ++i)
      printf("%s of %s\n", idx_to_value[(p_deck[i] - 1) % 13], idx_to_suit[(p_deck[i] - 1) / 13]);

    if (T)
      puts("");
  }

  return 0;
}