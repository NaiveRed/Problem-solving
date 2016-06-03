#include<cstdio>

int main()
{
    char str[20];
    int Case, i;
    scanf("%d", &Case);
    getchar();

    while (Case--)
    {
        gets(str);
        bool flag = true;
        int even = 0, odd = 0;

        for (i = 0; i < 19; i++)
        {
            if (str[i] == ' ')
                continue;
            
            int n = (str[i] - '0'), digit_sum = 0;
            if (flag)
                n *= 2;

            while (n)
            {
                digit_sum += n % 10;
                n /= 10;
            }

            if (flag)
                even += digit_sum;
            else
                odd += digit_sum;

            flag = !flag;
        }

        int sum = odd + even;
        if (sum % 10)
            puts("Invalid");
        else
            puts("Valid");
    }

    return 0;
}