#include <cstdio>

inline int get_type(int hr)
{
    if (hr >= 8 && hr < 18)
        return 0; //Day
    else if (hr >= 18 && hr < 22)
        return 1; //Evening
    return 2;     //Night
}
inline int get_duration(int h1, int m1, int h2, int m2)
{
    if (h1 < h2)
        return (h2 - h1 - 1) * 60 + 60 - m1 + m2;
    else if (h1 > h2)
        return (24 - h1 - 1) * 60 + 60 - m1 + h2 * 60 + m2;
    else //h1==h2
    {
        if (m2 > m1)
            return m2 - m1;
        else if (m2 < m1)
            return 60 - m1 + m2 + 23 * 60;
        else //m1==m2
            return 0;
    }
}
int main()
{
    const int bound[3] = {8, 18, 22};
    const int duration[3] = {10, 4, 10};
    const float rate[5][3] = {{0.1, 0.06, 0.02}, {0.25, 0.15, 0.05}, {0.53, 0.33, 0.13}, {0.87, 0.47, 0.17}, {1.44, 0.80, 0.30}};

    int h1, m1, h2, m2;
    char step[2], phone[10];

    while (scanf("%s%s%d%d%d%d", step, phone, &h1, &m1, &h2, &m2) == 6)
    {
        int dur[3] = {}; //min
        int type1 = get_type(h1), type2 = get_type(h2);

        if (type1 == type2 && !(h1 >= 22 && h2 < 8)) //在 NIGHT RATE 時的特殊跨日, 並不會切開
        {
            //該區段的時間被切成兩段, e.g. Day: (time1 -> 18) + (8 -> time2)
            if (h1 > h2 || (h1 == h2 && m1 >= m2) || (h1 >= 0 && h1 < 8 && h2 >= 22))
            {
                dur[type1] = duration[type1] * 60 - get_duration(h2, m2, h1, m1);
                type1 = (type1 + 1) % 3;
                h1 = bound[type1];
                m1 = 0;
            }
        }

        while (type1 != type2)
        {
            int next = (type1 + 1) % 3;
            dur[type1] = get_duration(h1, m1, bound[next], 0);

            type1 = next;
            h1 = bound[type1];
            m1 = 0;
        }

        if (!dur[type1])
            dur[type1] = get_duration(h1, m1, h2, m2);

        float sum = rate[step[0] - 'A'][0] * dur[0] + rate[step[0] - 'A'][1] * dur[1] + rate[step[0] - 'A'][2] * dur[2];
        printf("%10s%6d%6d%6d%3c%8.2f\n", phone, dur[0], dur[1], dur[2], step[0], sum);
    }

    return 0;
}