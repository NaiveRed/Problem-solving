// 注意都是標點符號的情況
#include <cstdio>
#include <cstring>
#include <cctype>
#define N 10000

int main()
{
    char str[N];
    while (fgets(str, N, stdin))
    {
        int len = strlen(str);
        if (str[len - 1] == '\n')
            str[--len] = '\0';
        if (!strcmp(str, "DONE"))
            break;

        bool palindromic = true;
        for (int tail = len - 1, head = 0; palindromic; tail--, head++)
        {
            while (tail >= 0 && !isalpha(str[tail]))
                tail--;

            while (head < len && !isalpha(str[head]))
                head++;

            if (head == len || tail < 0 || head >= tail)
                break;

            if (tolower(str[tail]) != tolower(str[head]))
                palindromic = false;
        }

        puts(palindromic ? "You won't be eaten!" : "Uh oh..");
    }

    return 0;
}