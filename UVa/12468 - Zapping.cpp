#include<cstdio>
#include<cstdlib>
#define MIN(a,b) ((a)<(b)?a:b)
#define MAX(a,b) ((a)>(b)?a:b)

int main()
{

	int a, b;

	while (scanf("%d%d", &a, &b) && a != -1)
		printf("%d\n", MIN(abs(b - a), 100- MAX(a,b) + MIN(a,b) ));
	
	return 0;
}