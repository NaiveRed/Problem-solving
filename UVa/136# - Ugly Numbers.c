#include<cstdio>
#define MIN(x,y,z) ((x)<(y)?        \
                   ((z)>(x)?x:z):   \
                   ((z)>(y)?y:z))   \

#define N 1500
int main(){

	int UglyNumber[N] = { 1 };
	int *n2 = UglyNumber, *n3 = UglyNumber, *n5 = UglyNumber;
	int *p = UglyNumber;

	while (p != UglyNumber + N - 1){
		for (; n2 <= p; n2++)
			if (*n2 * 2 > *p)
				break;
		for (; n3 <= p; n3++)
			if (*n3 * 3 > *p)
				break;
		for (; n5 <= p; n5++)
			if (*n5 * 5 > *p)
				break;

		*++p = MIN(*n2 * 2, *n3 * 3, *n5 * 5);
	}

	printf("The 1500'th ugly number is %d.\n", *p);

	return 0;
}