#include<cstdio>
#define N 10
struct Rec
{
    double x1, y1, x2, y2;
}rec[11];
int main()
{
    int count = 1;
    while (getchar()=='r')
    {
        scanf("%lf%lf%lf%lf", &rec[count].x1, &rec[count].y1, &rec[count].x2, &rec[count].y2);
        count++;
        getchar();
    }

    bool in;
    int i = 0;
    double x, y;
    while (scanf("%lf%lf", &x, &y) && x != 9999.9&&y != 9999.9)
    {
        in = false;
        i++;
        for (int j = 1; j<count; j++)
            if (x > rec[j].x1&&x < rec[j].x2&&y<rec[j].y1&&y > rec[j].y2)
            {
            printf("Point %d is contained in figure %d\n", i, j);
            in = true;
            }

        if (!in)
            printf("Point %d is not contained in any figure\n", i);
    }
    return 0;
}