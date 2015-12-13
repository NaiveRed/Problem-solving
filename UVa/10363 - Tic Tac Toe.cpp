#include<cstdio>
#define LINE(a,b,c) ((a)==(b)&&(b)==(c))

char board[3][3];

bool haveLine(char c);//不管幾條，只要有就會回傳true
int main()
{
	int Case;
	scanf("%d", &Case);

	while (Case--)
	{
		getchar();
		int O = 0, X = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = getchar();
				if (board[i][j] == 'O')
					O++;
				else if (board[i][j] == 'X')
					X++;
			}
			getchar();
		}

		/*
		1.OX數量相等，一定是O贏或平手
		2.X多一個，一定是X贏或平手
		3.其他都是錯的
		*/
		if (O == X)
		{
			bool OLine = haveLine('O');
			bool XLine = haveLine('X');
			if (OLine && XLine)
				puts("no");
			else if (OLine && !XLine)
				puts("yes");
			else if (XLine)
				puts("no");
			else//(!OLine && !XLine)
				puts("yes");
		}
		else if (O + 1 == X)
			puts(haveLine('O') ? "no" : "yes");
		else 
			puts("no");

		//init
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				board[i][j] = NULL;

	}

	return 0;
}
bool haveLine(char c)
{
	//horizontal
	for (int i = 0; i < 3; i++)
		if (LINE(board[i][0], board[i][1], board[i][2]))
			if (board[i][0] == c)
				return true;
	//vertical
	for (int i = 0; i < 3; i++)
		if (LINE(board[0][i], board[1][i], board[2][i]))
			if (board[0][i] == c)
				return true;
	//diagonal
	if (LINE(board[0][0], board[1][1], board[2][2]) || LINE(board[0][2], board[1][1], board[2][0]))
		if (board[1][1] == c)
			return true;

	return false;
}