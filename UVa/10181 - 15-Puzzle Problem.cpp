#include <cstdio>
#include <cstdlib>
#include <utility> //C++11, for swap()
#define N 16
#define MAX_DEEP 50
using namespace std;

const char cmd[4] = {'U', 'R', 'L', 'D'}; //上右左下
int board[N];

bool solvable(int *board)
{
	// Inversion_parity
	// Empty tile is zero
	// 左右移不會改變逆序數;上下移會使逆序數 +-3 or +-1
	int count = 0;
	for (int i = 0; i < N; i++)
		if (board[i])
		{
			for (int j = i + 1; j < N; j++)
				if (board[i] > board[j] && board[j])
					count++;
		}
		else
			// 計算將空格移到最後一列所需要的奇偶轉換
			count += ((i / 4) & 1) ? 0 : 1;

	// The inversion of completed board is 0 (even), 空格(0) 不計算在內
	return !(count & 1);
}
int move_tar(int zero_pos, char c) // false if the move is illegal
{
	if (c == 'U')
	{
		int tar = zero_pos - 4;
		return (tar < 0) ? -1 : tar;
	}
	else if (c == 'R')
	{
		return ((zero_pos + 1) % 4 == 0) ? -1 : (zero_pos + 1);
	}
	else if (c == 'L')
		return (zero_pos % 4 == 0) ? -1 : (zero_pos - 1);
	else //'D'
	{
		int tar = zero_pos + 4;
		return (tar > 15) ? -1 : tar;
	}
}
int heuristic(int *board)
{
	//manhattan
	int h = 0;
	for (int i = 0; i < N; i++)
	{
		int r = board[i] ? ((board[i] - 1) / 4) : 3;
		int c = board[i] ? ((board[i] - 1) % 4) : 3; //正確的位置

		h += abs(r - i / 4) + abs(c - i % 4); //row + col
	}

	return h;
}
void show_board(int *b)
{
	for (int i = 0; i < N; i++)
	{
		if (i % 4 == 0)
			putchar('\n');
		printf("%3d ", b[i]);
	}
}
bool is_goal()
{
	for (int i = 0; i < N - 1; i++)
		if (board[i] != i + 1)
			return false;
	return true;
}
int ida_star(int pre, int zero_pos, int dis, char *path, bool &found, int bound)
{
	// if not find the goal return the minimum f-value that exceeded the current bound
	// O/W return current distance
	int f = dis + heuristic(board);
	if (f > bound * 1.5) //多乘了1.5就快了一點, 我也不知道為何...
		return f;

	if (is_goal())
	{
		found = true;
		return dis;
	}

	int f_min = 1e8;
	for (int i = 0; i < 4; i++)
	{
		if (i + pre == 3) //不要走回上一個盤面
			continue;

		int tar = move_tar(zero_pos, cmd[i]); //tar will become the index of zero
		if (tar == -1)
			continue;

		std::swap(board[zero_pos], board[tar]);
		path[dis] = cmd[i];

		//show_board(board);
		int temp = ida_star(i, tar, dis + 1, path, found, bound);
		if (!found)
		{
			if (temp < f_min)
				f_min = temp;
			std::swap(board[zero_pos], board[tar]);
		}
		else
			return temp; //find the goal return dis
	}

	return f_min;
}
int main()
{	
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int zero;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &board[i]);
			if (board[i] == 0)
				zero = i;
		}

		bool found = solvable(board) ? true : false;
		int dis = 0;
		char path[100] = "";
		if (found)
		{
			found = false;
			int bound = heuristic(board); //max deep
			while (bound <= MAX_DEEP && !found)
				bound = ida_star(-1, zero, 0, path, found, bound);
			dis = bound;
		}

		if (found)
		{
			for (int i = 0; i < dis; i++)
				putchar(path[i]);
			putchar('\n');
		}
		else
			puts("This puzzle is not solvable.");
	}

	return 0;
}