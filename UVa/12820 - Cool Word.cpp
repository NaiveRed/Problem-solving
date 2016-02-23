#include<cstdio>

int main()
{
    int n, Case = 0;

    while (scanf("%d", &n) != EOF)
    {
        getchar();
        int count = 0;
        char c;

        while (n--)
        {
            bool diff = false;
            int alphabet[26] = {};
            int len = 0;

            while ((c = getchar()) != '\n')
            {
                alphabet[c - 'a']++;
                len++;
            }

            bool num[31] = {}, isCool = true;
            for (int i = 0; i < 26; i++)
            {
                if (alphabet[i])
                {
                    //看數字是否重複或字母只有一種
                    if (num[alphabet[i]] || len == alphabet[i])
                    {
                        isCool = false;
                        break;
                    }
                    else
                        num[alphabet[i]] = true;
                }
            }

            if (isCool)
                count++;
        }

        printf("Case %d: %d\n", ++Case, count);
    }

    return 0;
}
