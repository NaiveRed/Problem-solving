#include<stdio.h>
#define N 1000
int main(){

	int set,num[N];

	while (scanf("%d", &set) != EOF)
	{
		int i,j;
		for (i = 0; i < set; i++)
			scanf("%d", &num[i]);
		
		int temp,count=0;
		for (i = set - 1; i > 0; i--)
			for (j = 0;j<i;j++)
				if (num[j]>num[j+1])
				{
			temp = num[j];
			num[j] = num[j + 1];
			num[j + 1] = temp;
			count++;
				}
		
		printf("Minimum exchange operations : %d\n", count);
	}
	
	return 0;
}