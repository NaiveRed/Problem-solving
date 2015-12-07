#include<stdio.h>
#include<string.h>
#include<limits.h>
#define N 101
#define array_sum(x,y,x1,y1) (SumTable[x1][y1]-SumTable[x-1][y1]-SumTable[x1][y-1]+SumTable[x-1][y-1])

int SumTable[N][N];

int main(){

	int size;

	while (scanf("%d", &size) != EOF)
	{
		memset(SumTable, 0, sizeof(*SumTable)*N);

		int x, y, temp;
		for (x = 1; x <= size; x++)
			for (y = 1; y <= size; y++)
			{
			scanf("%d", &temp);
			SumTable[x][y] = SumTable[x - 1][y] + SumTable[x][y - 1] - SumTable[x - 1][y - 1] + temp;
			}

		int max_array_sum = INT_MIN, x1, y1;

		for (x = 1; x <= size; x++)
			for (y = 1; y <= size; y++)
				for (x1 = x; x1 <= size; x1++)
					for (y1 = y; y1 <= size; y1++)
					{
			temp = array_sum(x, y, x1, y1);
			max_array_sum = temp > max_array_sum ? temp : max_array_sum;
					}

		printf("%d\n", max_array_sum);
	}

	return 0;
}
