/*
判斷兩字串中 "不同字母的數量" 的遞增數列是否相同
*/
#include<cstdio>
#include<cstring>

int main()
{
    char a[101], b[101];

    while (gets(a))
    {
        gets(b);
        int len = strlen(a),i;
        bool isOk = true;
       
        int count_a[26] = {}, count_b[26] = {};
        for (i = 0; i < len; i++)
        {
            count_a[a[i] - 'A']++;
            count_b[b[i] - 'A']++;
        }

        int num_a[101] = {}, num_b[101] = {};
        for (i = 0; i < 26; i++)
        {
            num_a[count_a[i]]++;
            num_b[count_b[i]]++;
        }

        for (i = 0; i <= len; i++)
            if (num_a[i] != num_b[i])
            {
            isOk = false;
            break;
            }

        puts(isOk ? "YES" : "NO");

    }

    return 0;
}
