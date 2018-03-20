#include<stdio.h>

int main(){

	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
		printf("%d\n", m*n - 1);//n-1+(m-1)*n

	return 0;
}