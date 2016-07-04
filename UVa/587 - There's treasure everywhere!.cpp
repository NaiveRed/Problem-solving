#include<cstdio>
#include<cstring>
#include<cmath>
#define T 210

const double rate = 1 / sqrt(2);
const double dir[8][2] = { { rate, rate }, { rate, -rate }, { -rate, -rate }, { -rate, rate }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//NE,SE,SW,NW,N,E,S,W
inline int getDir(char first, char second);
int main()
{
    char str[T];
    int Case = 1;
    while (fgets(str, T, stdin))
    {
        if (str[0] == 'E'&&str[1] == 'N')
            break;

        int d, i;
        double pos_x = 0, pos_y = 0, dis;

        for (i = 0;; i += 2)
        {
            dis = 0;
            while (str[i] <= '9'&&str[i] >= '0')
            {
                dis = dis * 10 + str[i] - '0';
                i++;
            }

            d = getDir(str[i], str[i + 1]);

            pos_x += dir[d][0] * dis;
            pos_y += dir[d][1] * dis;

            if (str[i + 1] != ','&&str[i + 1] != '.')
                i++;

            if (str[i + 1] == '.')
                break;
        }

        printf("Map #%d\n", Case++);
        printf("The treasure is located at (%.3lf,%.3lf).\n", pos_x, pos_y);
        printf("The distance to the treasure is %.3lf.\n\n", sqrt(pos_x*pos_x + pos_y*pos_y));
    }

    return 0;
}
int getDir(char first, char second)
{
    if (second == 'E'&&first == 'N')
        return 0;
    else if (second == 'E'&&first == 'S')
        return 1;
    else if (second == 'W'&&first == 'S')
        return 2;
    else if (second == 'W'&&first == 'N')
        return 3;
    else if (first == 'N')
        return 4;
    else if (first == 'E')
        return 5;
    else if (first == 'S')
        return 6;
    else if (first == 'W')
        return 7;
}