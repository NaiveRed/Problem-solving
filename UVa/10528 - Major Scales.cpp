#include <cstdio>
#include <unordered_map>
#include <string>
#define N 12
using namespace std;

int main()
{
    const string S[N] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    const int step[7] = {2, 2, 1, 2, 2, 2, 1};

    //Map string to idx
    unordered_map<string, int> M;
    for (int i = 0; i < N; ++i)
        M[S[i]] = i;

    //甚麼調有用到那些音符
    bool scale_used[N][N] = {};
    for (int i = 0; i < N; ++i) //12種調，不同的開頭
    {
        scale_used[i][i] = true;
        for (int j = 0, k = i; j < 7; ++j) //7個step中有出現過那些音符
        {
            k = (k + step[j]) % N;
            scale_used[i][k] = true;
        }
    }

    char str[1005];
    while (fgets(str, 1005, stdin) && str[1] != 'N')
    {
        char tone[5];
        bool used[N] = {};
        bool first = true;

        //該段弦律中有出現那些音符
        for (int i = 0, idx = 0; str[i]; ++i)
        {
            if (str[i] == ' ' || str[i] == '\n')
            {
                tone[idx] = '\0';
                used[M[string(tone)]] = true;
                idx = 0;
            }
            else
                tone[idx++] = str[i];
        }

        for (int i = 0; i < N; ++i)
        {
            bool flag = true;
            for (int k = 0; k < N; ++k)
                if (used[k] && !scale_used[i][k]) //該音符在調中未出現，不可能是該調
                {
                    flag = false;
                    break;
                }

            if (flag)
            {
                if (!first)
                    putchar(' ');
                else
                    first = false;

                printf("%s", S[i].c_str());
            }
        }

        putchar('\n');
    }

    return 0;
}