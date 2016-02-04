/*
KMP: http://www.csie.ntnu.edu.tw/~u91029/StringMatching.html#3
ノkmpfailure functionт"Ω玡后后"
*/
#include<cstdio>
#include<cstring>
#define N 81

int fail[N];
int failure(char *str, int len);//failure function
int main()
{
    int Case;
    scanf("%d", &Case);
    getchar();

    char str[N];
    while (Case--)
    {
        getchar();
        gets(str);
        int len = strlen(str);

        //羆 - "Ω玡后后"(奔Юぺ妓)琌璶狡琿
        int dupli = len - (failure(str, len) + 1);
        int ans;

        if (len%dupli)
            ans = len;
        else
            ans = dupli;

        printf("%d\n", ans);

        if (Case)
            putchar('\n');
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