#include<stdio.h>
#define N 100
int main(){

	int num[N], count = 0,i;
	int perfect[N];
	while (scanf("%d", &num[count]) && num[count])
	{
		int sum=0;
		for (i = 1; i <= num[count] / 2; i++)
			if (!(num[count] % i))
				sum += i;
				
		if (sum == num[count])
			perfect[count] = 1;
		else if (sum > num[count])
			perfect[count] = 2;
		else perfect[count] = 0;
		
		count++;
	}
	
	puts("PERFECTION OUTPUT");
	
	for (i = 0; i < count; i++)
		printf("%5d  %s\n", num[i], perfect[i] == 1 ? "PERFECT" : (perfect[i] ? "ABUNDANT" : "DEFICIENT"));
	
	puts("END OF OUTPUT");

	return 0;
}