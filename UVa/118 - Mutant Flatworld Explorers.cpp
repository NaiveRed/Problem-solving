#include<cstdio>

int border_x, border_y;
inline void turn(char c, int &dir);
inline bool forward(int dir, int &x, int &y);
inline char convert(int dir);
int main()
{
	bool scent[51][51] {};

	scanf("%d%d", &border_x, &border_y);

	int x, y;
	char com[101], temp;
	while (scanf("%d%d %c", &x, &y, &temp) != EOF)
	{
		bool isLost = false;

		int dir;
		if (temp == 'N')
			dir = 1;
		else if (temp == 'E')
			dir = 2;
		else if (temp == 'S')
			dir = 3;
		else if (temp == 'W')
			dir = 4;

		getchar();
		gets(com);
		
		for (int i = 0; com[i];i++)
		{
			if (com[i] == 'F')
			{
				if (!forward(dir, x, y) && !scent[x][y])
				{
					isLost = true;
					scent[x][y] = true;
					break;
				}
			}
			else
				turn(com[i], dir);
		}

		printf("%d %d %c", x, y, convert(dir));
		puts(isLost ? " LOST" : "");
	}

	return 0;
}
void turn(char c, int& dir)
{
	if (c == 'R')
	{
		dir++;
		if (dir == 5)
			dir = 1;
	}
	else if (c == 'L')
	{
		dir--;
		if (dir == 0)
			dir = 4;
	}

	
}
inline bool forward(int dir, int &x, int &y)
{
	if (dir == 1)
	{
		if (y == border_y)
			return false;
		y++;

	}
	else if (dir == 2)
	{
		if (x == border_x)
			return false;
		x++;
	}
	else if (dir == 3)
	{
		if (!y)
			return false;
		y--;
	}
	else if (dir == 4)
	{
		if (!x)
			return false;
		x--;
	}

	return true;
}
inline char convert(int dir)
{
	if (dir == 1)
		return 'N';
	else if (dir == 2)
		return 'E';
	else if (dir == 3)
		return 'S';
	else if (dir == 4)
		return 'W';
}
