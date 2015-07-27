#include<stdio.h>

void mine_count(char mine[][102], int n, int m);

int main(){

	char mine[102][102];//[0][0~101]�B[101][0~101]�B[0~101][0]�B[0~101][101]�A�u���ӧ@�����u�b��t�ɪ��B��
	char c;
	int n, m;
	int i, j;
	int set = 1;

	while (scanf("%d %d", &n, &m))
	{

		if (!n&&!m)
			break;


		for (i = 0; i <= n + 1; i++)//��l�Ʀa�Ϭ�0
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
				mine_count(mine, i, j);//�p�⬵�u
			}
			}

		if (set>1)//�C�դ����ݪŦ�
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

	for (i = n - 1; i <= n + 1; i++)//9�c��d��
		for (j = m - 1; j <= m + 1; j++)
			if (mine[i][j] != '*')//�ư��������u
				mine[i][j]++;
}