#include<cstdio>
#include<map>
#include<string>
#include<cctype>
using namespace std;

int main()
{
    const char alp[27] = { "22233344455566670778889990" };
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, i;
        char c, num[9];
        map<string, int> M;

        scanf("%d", &n);
        getchar();
        for (i = 0; i < n; i++)
        {
            int idx = 0;
            while ((c = getchar()) != '\n')
            {
                if (isdigit(c))
                    num[idx++] = c;
                else if (isalpha(c) && c != 'Q'&&c != 'Z')
                    num[idx++] = alp[c - 'A'];
                if (idx == 3)
                    num[idx++] = '-';
            }

            num[idx] = NULL;
            M[string(num)]++;
        }

        bool no = true;
        for (map<string, int>::iterator it = M.begin(); it != M.end(); it++)
        {
            if (it->second > 1)
            {
                if (no)
                    no = false;

                printf("%s %d\n", it->first.c_str(), it->second);
            }
        }

        if (no)
            puts("No duplicates.");

        if (Case)
            putchar('\n');
    }

    return 0;
}
