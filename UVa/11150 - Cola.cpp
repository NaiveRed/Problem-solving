#include<cstdio>

int main()
{
	int bottles;

	while (scanf("%d", &bottles) != EOF)
	{
		/*
		�̫��3�ӥH�W:�~��
		��2��:�ɤ@�ӪŲ~�~��->��1�ӡA�ܧ���1��
		��1��:����

		�i�o�{�᳣̫�|�ѤU�@�ӡA�ҥH�̦h�u���H��1��
		*/

		int sum=bottles;
		bottles++;//������1�ӪŲ~
		
		while (bottles >= 3)
		{
			sum += bottles / 3;
			bottles = bottles / 3 + bottles % 3;
		}

		printf("%d\n",sum);

	}

	return 0;
}