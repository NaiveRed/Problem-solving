#include<stdio.h>

void mine_count(char mine[][102], int n, int m);

int main(){

	char mine[102][102];//[0][0~101]、[101][0~101]、[0~101][0]、[0~101][101]，只拿來作為當炸彈在邊緣時的運算
	char c;
	int n, m;
	int i, j;
	int set = 1;

	while (scanf("%d %d", &n, &m))
	{

		if (!n&&!m)
			break;


		for (i = 0; i <= n + 1; i++)//初始化地圖為0
			for (j = 0; j <= m + 1; j++)
				mine[i][j] = '0';

		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
			c = getchar();
			if (c == '\n')
				c = getchar();
			if (c == '*')
			{
				mine[i][j] = '*';
				mine_count(mine, i, j);//計算炸彈
			}
			}

		if (set>1)//每組之間需空行
			printf("\n");

		printf("Field #%d:\n", set++);


		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				printf("%c", mine[i][j]);
			}
			printf("\n");
		}





	}
	return 0;
}


void mine_count(char mine[][102], int n, int m){

	int i, j;

	for (i = n - 1; i <= n + 1; i++)//9宮格範圍
		for (j = m - 1; j <= m + 1; j++)
			if (mine[i][j] != '*')//排除本身炸彈
				mine[i][j]++;
}