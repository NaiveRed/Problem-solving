#include<cstdio>

int main()
{
    int n, m;
    bool colored = false;
    scanf("%d%d", &n, &m);
    char c;
    getchar();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            c = getchar();
            getchar();
            
            if (!colored&&c != 'B' && c != 'W' && c != 'G')
                colored = true;
            
        }

    puts(colored ? "#Color" : "#Black&White");

    return 0;
}