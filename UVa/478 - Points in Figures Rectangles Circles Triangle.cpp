#include <cstdio>
#include <cmath>
#define N 10
struct Shape
{
    char type;
    double x1, y1, x2, y2, r;
    double x3, y3;
} shape[N];
double get_triangle(Shape s) //return triangle area
{
    //http: //highscope.ch.ntu.edu.tw/wordpress/?p=66359
    double a = s.x2 - s.x1, b = s.y2 - s.y1, c = s.x3 - s.x1, d = s.y3 - s.y1;
    return fabs(a * d - b * c) / 2;
}
int main()
{
    //freopen("test.out","w",stdout);
    char c;
    int count = 0;
    while ((c = getchar()) != '*')
    {
        shape[count].type = c;
        if (c == 'r')
            scanf("%lf%lf%lf%lf", &shape[count].x1, &shape[count].y1, &shape[count].x2, &shape[count].y2);
        else if (c == 'c')
            scanf("%lf%lf%lf", &shape[count].x1, &shape[count].y1, &shape[count].r);
        else
            scanf("%lf%lf%lf%lf%lf%lf",
                  &shape[count].x1, &shape[count].y1, &shape[count].x2, &shape[count].y2, &shape[count].x3, &shape[count].y3);

        count++;
        getchar();
    }

    bool in;
    int i = 0;
    double x, y;
    while (scanf("%lf%lf", &x, &y) && x != 9999.9 && y != 9999.9)
    {
        in = false;
        i++;
        for (int j = 0; j < count; j++)
        {
            if (shape[j].type == 'r')
            {
                if (x > shape[j].x1 && x < shape[j].x2 && y < shape[j].y1 && y > shape[j].y2)
                {
                    printf("Point %d is contained in figure %d\n", i, j + 1);
                    in = true;
                }
            }
            else if (shape[j].type == 'c')
            {
                double dis2 = (x - shape[j].x1) * (x - shape[j].x1) + (y - shape[j].y1) * (y - shape[j].y1);
                if (dis2 < shape[j].r * shape[j].r)
                {
                    printf("Point %d is contained in figure %d\n", i, j + 1);
                    in = true;
                }
            }
            else //triangle
            {
                //以該點到原先三點中的兩點可分成三個三角形，判斷面積相加後是否與原本相同。
                Shape s1, s2, s3;
                s1 = s2 = s3 = shape[j];
                s1.x1 = x, s1.y1 = y;
                s2.x2 = x, s2.y2 = y;
                s3.x3 = x, s3.y3 = y;
                double a = get_triangle(shape[j]);
                double a1 = get_triangle(s1), a2 = get_triangle(s2), a3 = get_triangle(s3);
                if (a1 && a2 && a3 && a1 + a2 + a3 - a <= 1e-9) //need EPS!
                {
                    printf("Point %d is contained in figure %d\n", i, j + 1);
                    in = true;
                }
            }
        }

        if (!in)
            printf("Point %d is not contained in any figure\n", i);
    }
    return 0;
}