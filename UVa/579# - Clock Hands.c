#include<stdio.h>
#include<math.h>

int main(){

	double h, m;
	while (scanf("%lf:%lf", &h, &m) != EOF && (h || m))
	{
		h = h * 5 + m * 5 / 60;
		double angle = fabs(h - m) * 6;
		printf("%.3lf\n", angle > 180 ? 360 - angle : angle);

	}
	return 0;
}