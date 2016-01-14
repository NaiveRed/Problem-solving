#include<cstdio>

int finger[11];
bool last[11];

inline void press(int a, int b);
int main()
{
	int Case;
	scanf("%d", &Case);
	getchar();

	while (Case--)
	{
		char c;
		while ((c = getchar()) != '\n')
		{
			//count
			if (c == 'c')
			{
				press(2, 4);
				press(7, 10);
				last[6] = last[5] = last[1] = false;
			}
			else if (c == 'd')
			{
				press(2, 4);
				press(7, 9);
				last[10] = last[6] = last[5] = last[1] = false;
			}
			else if (c == 'e')
			{
				press(2, 4);
				press(7, 8);
				last[9] = last[10] = last[6] = last[5] = last[1] = false;
			}
			else if (c == 'f')
			{
				press(2, 4);
				press(7, 7);
				last[8] = last[9] = last[10] = last[6] = last[5] = last[1] = false;
			}
			else if (c == 'g')
			{
				press(2, 4);
				last[7] = last[8] = last[9] = last[10] = last[6] = last[5] = last[1] = false;
			}
			else if (c == 'a')
			{
				press(2, 3);
				last[4] = last[7] = last[8] = last[9] = last[10] = last[6] = last[5] = last[1] = false;
			}
			else if (c == 'b')
			{
				press(2, 2);
				last[3] = last[4] = last[7] = last[8] = last[9] = last[10] = last[6] = last[5] = last[1] = false;
			}
			else if (c == 'C')
			{
				press(3, 3);
				last[2] = last[4] = last[7] = last[8] = last[9] = last[10] = last[6] = last[5] = last[1] = false;
			}
			else if (c == 'D')
			{
				press(1, 4);
				press(7, 9);
				last[10] = last[6] = last[5] = false;
			}
			else if (c == 'E')
			{
				press(1, 4);
				press(7, 8);
				last[9] = last[10] = last[6] = last[5] = false;
			}
			else if (c == 'F')
			{
				press(1, 4);
				press(7, 7);
				last[8] = last[9] = last[10] = last[6] = last[5] = false;
			}
			else if (c == 'G')
			{
				press(1, 4);
				last[7] = last[8] = last[9] = last[10] = last[6] = last[5] = false;
			}
			else if (c == 'A')
			{
				press(1, 3);
				last[4] = last[7] = last[8] = last[9] = last[10] = last[6] = last[5] = false;
			}
			else if (c == 'B')
			{
				press(1, 2);
				last[3] = last[4] = last[7] = last[8] = last[9] = last[10] = last[6] = last[5] = false;
			}

		}

		printf("%d", finger[1]);
		for (int i = 2; i < 11; i++)
			printf(" %d", finger[i]);
		putchar('\n');

		//init
		for (int i = 1; i < 11; i++)
		{
			finger[i] = 0;
			last[i] = false;
		}
	}

	return 0;
}
void press(int a, int b)
{
	for (int i = a; i <= b; i++)
		if (!last[i])
		{
		last[i] = true;
		finger[i]++;
		}
}
