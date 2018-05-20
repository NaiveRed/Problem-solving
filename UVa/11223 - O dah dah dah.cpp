//猜測每一行結束都會有" "
#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    const char str[53][8] = {"A.-", "B-...", "C-.-.", "D-..", "E.", "F..-.", "G--.",
                             "H....", "I..", "J.---", "K-.-", "L.-..", "M--", "N-.", "O---",
                             "P.--.", "Q--.-", "R.-.", "S...", "T-", "U..-", "V...-", "W.--",
                             "X-..-", "Y-.--", "Z--..", "0-----", "1.----", "2..---", "3...--",
                             "4....-", "5.....", "6-....", "7--...", "8---..", "9----.",
                             "..-.-.-", ",--..--", "?..--..", "'.----.", "!-.-.--", "/-..-.",
                             "(-.--.", ")-.--.-", "&.-...", ":---...", ";-.-.-.", "=-...-",
                             "+.-.-.", "--....-", "_..--.-", "\".-..-.", "@.--.-."};
    unordered_map<string, char> M;

    for (int i = 0; i < 53; ++i)
        M[string(str[i] + 1)] = str[i][0];

    int T;
    char s[2005];
    scanf("%d", &T);
    getchar();
    for (int t = 1; t <= T; ++t)
    {
        printf("Message #%d\n", t);
        fgets(s, 2005, stdin);
        int idx = 0, i;

        for (i = 0; s[i] != '\n' && s[i]; ++i)
        {
            if (s[i] == ' ')
            {
                putchar(M[string(s, idx, i - idx)]);
                if (s[i + 1] == ' ')
                {
                    putchar(' ');
                    ++i;
                }

                idx = i + 1;
            }
        }
        /*if (idx != i)
            putchar(M[string(s, idx, i - idx)]);*/

        puts(t != T ? "\n" : "");
    }

    return 0;
}
