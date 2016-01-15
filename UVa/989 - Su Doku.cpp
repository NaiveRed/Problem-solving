#include<cstdio>

int sudoku[9][9];
int border;

bool solveSudoku(int row, int col);//backtrack
bool isOk(int row, int col, int num);//whether the number in the grid is legal
int main()
{
	int n;
	char c;
	bool first = true;;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		border = n*n;

		//input
		for (int i = 0; i < border; i++)
			for (int j = 0; j < border; j++)
			{
			c = getchar();
			getchar();

			sudoku[i][j] = c - '0';
			}

		//output
		if (first)
			first = false;
		else putchar('\n');

		if (n == 1)
		{
			putchar(sudoku[0][0] == 0 ? '1' : sudoku[0][0] + '0');
			putchar('\n');
		}
		else if (solveSudoku(0, 0))
		{
			for (int i = 0; i < border; i++)
			{
				printf("%d", sudoku[i][0]);
				for (int j = 1; j < border; j++)
					printf(" %d", sudoku[i][j]);
				putchar('\n');
			}
		}
		else
			puts("NO SOLUTION");

		//init
		for (int i = 0; i < border; i++)
			for (int j = 0; j < border; j++)
				sudoku[i][j] = 0;
	}

	return 0;
}
bool solveSudoku(int row, int col)
{
	bool isFinish = true;

	//find the empty grid
	for (; row < border; row++, col = 0)
	{
		for (; col < border; col++)
			if (!sudoku[row][col])
			{
			isFinish = false;
			break;
			}

		if (!isFinish)
			break;
	}

	//if all grids are filled ,sudoku is finished
	if (isFinish)
		return true;

	for (int num = 1; num <= border; num++)
	{
		if (isOk(row, col, num))
		{
			sudoku[row][col] = num;

			if (solveSudoku(row, col))
				return true;
		}
	}

	//1~9都不行，需回溯
	sudoku[row][col] = 0;
	return false;
}
bool isOk(int row, int col, int num)
{
	for (int i = 0; i < border; i++)
	{
		//check column and row
		if (sudoku[row][i] == num)
			return false;
		if (sudoku[i][col] == num)
			return false;
	}

	//在哪一個宮(數獨裡的大方格)
	int box_row, box_col, b;

	if (border == 9)
	{
		box_row = row - row % 3;
		box_col = col - col % 3;
		b = 3;
	}
	else
	{
		box_row = row - row % 2;
		box_col = col - col % 2;
		b = 2;
	}

	for (int i = 0; i < b; i++)
		for (int j = 0; j < b; j++)
			if (sudoku[i + box_row][j + box_col] == num)
				return false;

	return true;
}