#include<stdio.h>
#include<math.h>
#define N 500

int num[N];

void Insertion_sort(int n, int index);
int main(){

	int set;
	while (scanf("%d", &set) != EOF)
	{
		while (set--)
		{
			int index = 0;
			int people, n;
			scanf("%d", &people);
			while (people--)
			{
				scanf("%d", &n);
				Insertion_sort(n, index++);
			}
			index--;
			int mid = index & 1 ? (num[index / 2] + num[index / 2 + 1]) / 2 : num[index / 2];
			
			int i, sum = 0;
			for (i = 0; i <= index; i++)
				sum += abs(mid - num[i]);
			printf("%d\n", sum);
		}
	}
	return 0;
}
void Insertion_sort(int n, int index)
{
	int i;
	for (i = index; i&&n < num[i - 1]; i--)
		num[i] = num[i - 1];
	num[i] = n;
}