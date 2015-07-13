#include<cstdio>
#include<vector>
#include<cstring>
#define N 25

typedef struct POS
{
	int column;
	int row;
};

POS find(const int& block_num, const int& target);
void clear_above(POS &pos);

std::vector<int> block[N];
int main()
{
	int block_num;
	char command[2][5];

	while (scanf("%d", &block_num) != EOF)
	{
		//init
		for (int i = 0; i < block_num; i++)
			block[i].emplace_back(i);

		int a, b;
		//input command
		while (scanf("%s", command[0]) && command[0][0] != 'q')
		{
			scanf("%d%s%d", &a, command[1], &b);

			POS pos_a(find(block_num, a)), pos_b(find(block_num, b));
			if (pos_a.column == pos_b.column)
				continue;

			if (!strcmp(command[0], "move"))
				clear_above(pos_a);

			if (!strcmp(command[1], "onto"))
				clear_above(pos_b);

			if (!strcmp(command[0], "pile"))
			{
				for (auto it = block[pos_a.column].begin() + pos_a.row; it != block[pos_a.column].end(); it++)
					block[pos_b.column].emplace_back(*it);
				block[pos_a.column].erase(block[pos_a.column].begin() + pos_a.row, block[pos_a.column].end());
			}
			else
			{
				block[pos_b.column].emplace_back(a);
				block[pos_a.column].pop_back();
			}

		}

		for (int i = 0; i < block_num; i++)
		{
			printf("%d:", i);
			for (auto&& it : block[i])
				printf(" %d", it);
			puts("");
		}

		//clear
		for (int i = 0; i < block_num; i++)
			block[i].clear();
	}

	return 0;
}
inline POS find(const int& block_num, const int& target)
{
	for (int i = 0; i < block_num; i++)
	{
		int len(block[i].size());
		for (int j = 0; j < len; j++)
			if (block[i][j] == target)
				return POS{ i, j };
	}
}
inline void clear_above(POS &pos)
{

	for (int index = block[pos.column].size() - 1; index != pos.row; index--)
	{
		block[block[pos.column][index]].emplace_back(block[pos.column][index]);
		block[pos.column].pop_back();
	}
}
