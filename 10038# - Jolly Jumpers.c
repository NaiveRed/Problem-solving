#include<stdio.h>
#include<math.h>
#include<stdbool.h>


int main(){

	int a;
	int b[3000];


	while (scanf("%d", &a) != EOF)
	{
		bool c[3000] = { false };
		int i;
		for (i = 0; i < a; i++)
			scanf("%d", &b[i]);


		bool check = true;
		int q = a - 1;

		for (i = 0; i < q; i++)
		{
			int temp = fabs(b[i] - b[i + 1]);
			c[temp] = true;
		}
		for (i = 1; i < a; i++)
			if (!c[i])
			{
			check = false;
			break;
			}
		if (check)
			printf("Jolly\n");
		else printf("Not jolly\n");
	}


	return 0;
}