#include<cstdio>
#include<cstring>

int main()
{
	int test;

	while (scanf("%d", &test) != EOF)
	{
		char origin[200][85], tar[200][85];

		while (test--)
		{
			int num;
			scanf("%d\r", &num);

			int i, j;
			for (i = 0; i < num; i++)//[0]���̤W�h
				gets(origin[i]);
			for (i = 0; i < num; i++)
				gets(tar[i]);

			i = j = num - 1;

			while (i >= 0)
			{
				/*
					1 3 2 4 5
					2 1 3 5 4
					�z��:
					�p�G��ӳ��@��(�]�N�O�۹�W�ӻ���m���Tex. 12345 �M 14325 �A5���b3���᭱�o��)�A
					�N�~�򩹤W�ݡA�ҥHi,j��-1;
					�p�G���@�ˡAorigin���N�~��V�W�ݤ@���@��(�ҥH�u��i--)�A
					���쳣�䧹�A�i�H�o�{�qtar[j]�H�W���Q�t���O�٨S�Ʀn���A�u�n�Ӷ������L�̩��W���Y�i�C
				*/
				if (!strcmp(origin[i], tar[j]))
				{
					i--;
					j--;
				}
				else i--;
			}

			while (j >= 0)
				printf("%s\n", tar[j--]);

			puts("");
		}
	}

	return 0;
}