#include <cstdio>

int main()
{
    int T;
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++)
    {
        int d1, m1, y1, d2, m2, y2;
        scanf("%d/%d/%d", &d1, &m1, &y1);
        scanf("%d/%d/%d", &d2, &m2, &y2);

        int age = -1;
        if (y1 > y2)
        {
            // 假設第一年不足一歲, e.g. 01/01/2015 01/05/2014, valid 但 0 歲
            age = y1 - y2 - 1;
            if (m1 > m2 || (m1 == m2 && d1 >= d2)) // 當天月份比較大 OR 同月但當天日期(day)比較後面
                age++;
        }
        else if (y1 == y2)
        {
            if (m1 > m2 || (m1 == m2 && d1 >= d2))
                age = 0;
        }

        if (age == -1)
            printf("Case #%d: Invalid birth date\n", t);
        else if (age <= 130)
            printf("Case #%d: %d\n", t, age);
        else
            printf("Case #%d: Check birth date\n", t);
    }

    return 0;
}