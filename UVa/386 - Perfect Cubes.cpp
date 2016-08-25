#include<cstdio>

int main()
{
    for (int a = 6; a <= 200; a++)
    {
        int aaa = a*a*a;
        for (int b = 2; b <= 200; b++)
        {
            int bbb = b*b*b;
            if (bbb > aaa)
                break;
            for (int c = b; c <= 200; c++)
            {
                int ccc = c*c*c;
                if (ccc + bbb > aaa)
                    break;

                for (int d = c; d <= 200; d++)
                    if (aaa == bbb + ccc + d*d*d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    else if (aaa < bbb + ccc + d*d*d)
                        break;
            }
        }
    }

    return 0;
}
