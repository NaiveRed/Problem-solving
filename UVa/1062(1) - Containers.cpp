//LIS O(N^2)
#include<cstdio>
#include<cstring>

int main()
{
    char str[1000];
    int length[1000], i, Case = 1;

    while (gets(str) && str[0] != 'e')
    {
        int len = strlen(str);
        for (i = 0; i < len; i++)
            length[i] = 1;

        for (i = 0; i < len; i++)
            for (int j = i+1; j<len; j++)
                if (str[j]>str[i])
                    if (length[i] + 1>length[j])
                        length[j] = length[i] + 1;
      
        int max = 0;
        for (i = 0; i < len; i++)
            if (max < length[i])
                max = length[i];

        printf("Case %d: %d\n", Case++, max);
    }

    return 0;
}
