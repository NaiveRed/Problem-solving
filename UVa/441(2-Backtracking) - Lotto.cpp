#include<cstdio>

int num[15], ans[7];

void back(int len, int pos, int& total);//Backtracking
int main()
{
	int n;
	bool first(true);

	while (scanf("%d", &n) && n)
	{

		if (!first)
			putchar('\n');
		else
			first = false;

		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		back(0, 0, n);

	}


	return 0;
}
void back(int len, int pos, int& total)
{
	if (len == 6)//長度滿6即可輸出
	{
		//ans從1開始
		for (int i = 1; i < 6; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[6]);
	}
	else
	{
		len++;
		for (int i = pos; i < total; i++)//ans[len]的答案依序從num[]中往後挑
		{
			ans[len] = num[i];//將數字推入答案
			back(len, i + 1, total);//答案的下一位從下個位置開始推
		}
	}
}