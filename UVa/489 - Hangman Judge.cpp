#include<cstdio>

int main()
{
    int round;
    while (scanf("%d", &round) && round != -1)
    {
        getchar();
        bool used[26] = {}, ans[26] = {};
        int count = 0, hangman = 7;
        char c;

        while ((c = getchar()) != '\n')
        {
            if (!used[c - 'a'])
            {
                used[c - 'a'] = true;
                count++;
            }

            if (count == 26)
            {
                while ((c = getchar()) != '\n');
                break;
            }
        }

        while ((c = getchar()) != '\n')
        {
            int temp = c - 'a';
            if (!ans[temp])
            {
                ans[temp] = true;
                if (used[temp])
                {
                    used[temp] = false;
                    count--;
                }
                else
                    hangman--;
            }

            if (!hangman || !count)
            {
                while ((c = getchar()) != '\n');
                break;
            }
        }

        printf("Round %d\n", round);
        if (!hangman)
            puts("You lose.");
        else if (count)
            puts("You chickened out.");
        else
            puts("You win.");
    }

    return 0;
}