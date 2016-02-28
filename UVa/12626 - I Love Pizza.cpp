#include<cstdio>

int main()
{
    char pizza[6] = { 'M', 'A', 'R', 'G', 'I', 'T' };
    int Case;
    scanf("%d", &Case);
    getchar();
    while (Case--)
    {
        int s[26] = {};
        char c;
        while ((c = getchar()) != '\n')
            s[c - 'A']++;
        
        s[0] /= 3;
        s['R' - 'A'] /= 2;
        int ans = 100;
        for (int i = 0; i<6; i++)
            if (ans>s[pizza[i] - 'A'])
                ans = s[pizza[i] - 'A'];
        
        printf("%d\n", ans);
    }
    
    return 0;
}