#include<cstdio>

int main()
{
    int size[7];
    while (scanf("%d", &size[1]))
    {
        int i, temp = size[1];
        for (i = 2; i <= 6; i++)
        {
            scanf("%d", &size[i]);
            temp += size[i];
        }

        if (!temp)
            break;

        int box = size[6]+size[5]+size[4];//6x6+5x5+4x4
        size[1] -= 11 * size[5];//5x5+11*(1x1)
        if (size[1] < 0)
            size[1] = 0;

        temp = size[2] - size[4] * 5;//4x4+5*(2x2)
        if (temp < 0)
        {
            temp *= -1;
            if (size[1])//4x4+n*(2x2)+n*(1x1)
                size[1] -= temp * 4;

            size[2] = 0;
        }
        else
            size[2] = temp;

        int temp2 = size[3] / 4;
        box += temp2;//4*(3x3)
        size[3] %= 4;
        if (size[3])
            box++;

        temp = size[2];
        if (size[3])//放完 3x3 剩下的空間
        {
            if (size[2])
            {
                if (size[3] == 1)
                    temp -= 5;
                else if (size[3] == 2)
                    temp -= 3;
                else if (size[3] == 3)
                    temp -= 1;

                if (temp > 0)
                {
                    size[2] = temp;
                    temp = 0;
                }
                else
                {
                    temp *= -1;
                    size[2] = 0;
                }
            }

            if (size[1] > 0)
            {
                if (size[3] == 1)
                    size[1] -= 7;
                else if (size[3] == 2)
                    size[1] -= 6;
                else if (size[3] == 3)
                    size[1] -= 5;
                
                size[1] -= temp * 4;
            }

        }

        if (size[2])//9*(2x2)
        {
            box += size[2] / 9;
            size[2] %= 9;
            if (size[2])
                box++;
        }

        if (size[1] > 0)//剩下的 1x1
        {
            if (size[2])
            {
                size[1] -= 36 - size[2] * 4;
                if (size[1] < 0)
                    size[1] = 0;
            }

            box += size[1] / 36;
            if (size[1] % 36)
                box++;
        }

        printf("%d\n", box);
    }

    return 0;
}