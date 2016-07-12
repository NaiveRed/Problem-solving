#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str1[102] = {}, str2[102] = {};
    int dp[102][102] = {}, Case = 1;

    while (gets(str1) && str1[0] != '#')
    {
        gets(str2);
        int i, j, len1 = strlen(str1) , len2 = strlen(str2) ;

        for (i = 1; i <= len1; i++)
            for (j = 1; j <= len2; j++)
            {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }

        printf("Case #%d: you can visit at most %d cities.\n", Case++, dp[len1][len2]);
    }

    return 0;
}