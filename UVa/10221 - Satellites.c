#include<stdio.h>
#include<math.h>
#define PI (acos(-1.0))//反餘弦，直接用3.1415926可能不夠精準

int main()
{
	/*
	1 deg = 60 min
	弧長 = 2*pi*r*角度/360
	弦長利用餘弦定理
	*/

	double r, a;
	char str[5];

	while (scanf("%lf%lf%s", &r, &a, str) != EOF)
	{
		r += 6440;
		if (str[0] == 'm')
			a /= 60;
		if (a > 180)
			a = 360 - a;

		printf("%.6lf %.6lf\n", 2 * PI*r*a / 360, sqrt(2 * r*r - 2 * r*r*cos(a*PI / 180)));
	}

	return 0;
}
