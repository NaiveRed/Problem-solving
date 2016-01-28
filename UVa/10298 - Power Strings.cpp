/*
KMP: http://www.csie.ntnu.edu.tw/~u91029/StringMatching.html#3
ノkmpfailure functionт"Ω玡后后"
*/
#include<cstdio>
#include<cstring>
#define N 1000001

int fail[N];
int failure(char *str, int len);//failure function
int main()
{
    char str[N];
    while (gets(str))
    {
        int len = strlen(str);
        if (len == 1 && str[0] == '.')
            break;

        //羆 - "Ω玡后后"(奔Юぺ妓)琌璶狡琿
        int dupli = len - (failure(str, len) + 1);
        int ans;

        if (dupli)
        {
            if (len%dupli)
                ans = 1;
            else
                ans = len / dupli;
        }
        else
            ans = len / dupli;

        printf("%d\n", ans);
    }

    return 0;
}
int failure(char *str, int len)
{
    fail[0] = -1;
    int i = 1, j = -1;

    for (; i < len; i++)
    {
        while (j >= 0 && str[i] != str[j + 1])
            j = fail[j];

        if (str[i] == str[j + 1])
            j++;

        fail[i] = j;
    }

    return fail[len - 1];
}