#include<cstdio>
#define N 10
struct Shape
{
    char type;
    double x1, y1, x2, y2, r;

}shape[N];
int main()
{
    char c;
    int count = 0;
    while ((c = getchar()) != '*')
    {
        shape[count].type = c;
        if (c == 'r')
            scanf("%lf%lf%lf%lf", &shape[count].x1, &shape[count].y1, &shape[count].x2, &shape[count].y2);
        else
            scanf("%lf%lf%lf", &shape[count].x1, &shape[count].y1, &shape[count].r);

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
        for (int j = 0; j<count; j++)
        {
            if (shape[j].type == 'r')
            {
                if (x > shape[j].x1&&x < shape[j].x2&&y<shape[j].y1&&y > shape[j].y2)
                {
                    printf("Point %d is contained in figure %d\n", i, j+1);
                    in = true;
                }
            }
            else
            {
                double dis2 = (x - shape[j].x1)*(x - shape[j].x1) + (y - shape[j].y1)*(y - shape[j].y1);
                if (dis2 < shape[j].r*shape[j].r)
                {
                    printf("Point %d is contained in figure %d\n", i, j+1);
                    in = true;
                }
            }
        }

        if (!in)
            printf("Point %d is not contained in any figure\n", i);
    }
    return 0;
}