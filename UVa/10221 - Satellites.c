#include<stdio.h>
#include<math.h>
#define PI (acos(-1.0))//�Ͼl���A������3.1415926�i�ण�����

int main()
{
	/*
	1 deg = 60 min
	���� = 2*pi*r*����/360
	�����Q�ξl���w�z
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
