#include<stdio.h>

int main(){

	unsigned int set, farmer, i, size, animal, num;

	while (scanf("%u", &set) != EOF)
	{
		while (set)
		{
			unsigned int sum = 0;
			scanf("%u", &farmer);
			for (i = 1; i <= farmer; i++)
			{
				scanf("%u %u %u", &size, &animal, &num);
				sum += (size*num);
			}

			printf("%u\n", sum);


			set--;
		}

	}
	return 0;
}