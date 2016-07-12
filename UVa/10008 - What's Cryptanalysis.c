#include<stdio.h>
#include<ctype.h>

int main(){

    char s[1000];
    int set;

    struct Alphabet{

        char c;
        int n;
    }alphabet[26], temp;

    while (scanf("%d", &set) != EOF)
    {
        int i, j;

        char A = 'A';
        for (i = 0; i<26; i++)
        {
            alphabet[i].c = A++;
            alphabet[i].n = 0;
        }
        getchar();
        while (set--)
        {
            gets(s);
            for (i = 0; s[i]; i++)
            {
                if (isalpha(s[i]))
                {
                    s[i] = toupper(s[i]);
                    alphabet[s[i] - 'A'].n++;
                }
            }
        }

        for (i = 25; i >= 0; i--)
            for (j = 0; j<i; j++)
                if (alphabet[j].n < alphabet[j + 1].n)
                {
            temp = alphabet[j];
            alphabet[j] = alphabet[j + 1];
            alphabet[j + 1] = temp;
                }
        for (i = 0; i < 26; i++)
        {
            if (alphabet[i].n)
                printf("%c %d\n", alphabet[i].c, alphabet[i].n);
        }
    }

    return 0;
}