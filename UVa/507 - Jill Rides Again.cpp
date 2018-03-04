/*
stop: 1    2    3
n   :-1....6....home
1~2 is -1
2~3 is 6
1~3 is 5
*/
#include <cstdio>

int main()
{
    int Case;
    scanf("%d", &Case);

    for (int c = 1; c <= Case; c++)
    {
        int s, n, from = 1, to, sum = 0, max = 0;
        int ans_from = 0, ans_to = 0;        
        scanf("%d", &s);
        for (int i = 2; i <= s; i++)
        {
            scanf("%d", &n);
            sum += n;
            //to = i;

            if (sum > max || (sum == max && ans_to - ans_from < i - from))
            {
                max = sum;
                ans_from = from;
                ans_to = i;
            }
            else if (sum < 0)
            {
                from = i;
                sum = 0;
            }
        }

        if (max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", c, ans_from, ans_to);
        else
            printf("Route %d has no nice parts\n", c);
    }

    return 0;
}