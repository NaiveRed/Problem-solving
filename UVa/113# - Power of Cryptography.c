#include<stdio.h>
#include<math.h>

int main(){

	double power, n;

	while (scanf("%lf%lf", &power, &n) == 2)
		printf("%.0lf\n", pow(n, 1 / power));


	return 0;
}