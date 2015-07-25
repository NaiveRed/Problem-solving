#include<stdio.h>
#define B 0
#define G 1
#define C 2


int main(){

	char show[6][3] =
	{ { 'B', 'C', 'G' },
	{ 'B', 'G', 'C' },
	{ 'C', 'B', 'G' },
	{ 'C', 'G', 'B' },
	{ 'G', 'B', 'C' },
	{ 'G', 'C', 'B' } };

	int bin[6][3] = { { B, C, G },
	{ B, G, C },
	{ C, B, G },
	{ C, G, B },
	{ G, B, C },
	{ G, C, B } };

	int bottle[3][3];

	while (scanf("%d %d %d %d %d %d %d %d %d",
		&bottle[0][B], &bottle[0][G], &bottle[0][C],
		&bottle[1][B], &bottle[1][G], &bottle[1][C],
		&bottle[2][B], &bottle[2][G], &bottle[2][C]) != EOF){
		int move, total = 0, min, i, temp = 0;
		for (i = 0; i <= 2; i++)
			total = total + bottle[i][B] + bottle[i][G] + bottle[i][C];


		min = total;
		for (i = 0; i <= 5; i++)
		{

			move = total - bottle[0][bin[i][0]] - bottle[1][bin[i][1]] - bottle[2][bin[i][2]];
			if (move < min)
			{
				min = move;
				temp = i;
			}

		}

		printf("%c%c%c %d\n", show[temp][0], show[temp][1], show[temp][2], min);
	}


	return 0;
}