#include"Matrix.h"
#include<stdlib.h>

Term* getTranspose(Term* matrix)
{
	Term *Mt = calloc(matrix[0].value + 1, sizeof(Term));
	int i, j, count = 1;

	Mt[0].row = matrix[0].col;
	Mt[0].col = matrix[0].row;
	Mt[0].value = matrix[0].value;

	for (i = 1; i <= matrix[0].col; i++)
		for (j = 1; j <= matrix[0].value; j++)
		{
		if (matrix[j].col == i)
		{
			Mt[count].row = matrix[j].col;
			Mt[count].col = matrix[j].row;
			Mt[count++].value = matrix[j].value;
		}
		}

	return Mt;
}
Term* multi(Term* a, Term* b)
{
	Term* ans = calloc(a[0].row*b[0].col + 1, sizeof(Term));//[0]�O�`�@�X��X�C��D0���q�A�ҥH�n+1

	ans[0].row = a[0].row;
	ans[0].col = b[0].col;

	int i, j, k, c, sum = 0, count = 0;

	for (i = 1; i <= ans[0].row; i++)
	{
		for (c = 1; c <= b[0].col; c++)
		{
			for (j = 1; j <= b[0].row; j++)
			{
				int x = 0, y = 0;
				for (k = 1; k <= a[0].value&&a[k].row <= i; k++)
					if (a[k].row == i&&a[k].col == j)
					{
					x = a[k].value;
					break;
					}

				for (k = 1; k <= b[0].value; k++)
					if (b[k].row == j&&b[k].col == c)
					{
					y = b[k].value;
					break;
					}

				sum += (x*y);

			}

			if (sum)
			{

				ans[++count].value = sum;
				ans[count].row = i;
				ans[count].col = c;

				sum = 0;
			}
		}
	}

	ans[0].value = count;

	return ans;
}
Term* fastTranspose(Term* m)
{
	Term* Mt = calloc(m[0].value + 1, sizeof(Term));

	int *rowTerm = calloc(m[0].col + 1, sizeof(int)), *startPos = calloc(m[0].col + 1, sizeof(int));
	int i;

	Mt[0].row = m[0].col;
	Mt[0].col = m[0].row;
	Mt[0].value = m[0].value;

	if (m[0].value)
	{
		for (i = 0; i < m[0].col; i++)
			rowTerm[i] = 0;

		//��m�᪺�C�@�C���X�ӫD0����
		for (i = 1; i <= m[0].value; i++)
			rowTerm[m[i].col]++;

		/*for (i = 1; i <= m[0].col; i++)
			printf("row[%d]��%d�ӫD0\n", i, rowTerm[i]);*/

		//��m��C�@�C���}�l��m
		startPos[0] = 1;
		for (i = 1; i <= m[0].col; i++)
			startPos[i] = startPos[i - 1] + rowTerm[i - 1];

		/*for (i = 1; i <= m[0].col; i++)
			printf("row[%d]�q%d�}�l\n", i, startPos[i]);*/

		for (i = 1; i <= m[0].value; i++)
		{
			int j = startPos[m[i].col]++;//���U�Ӧp�G�A�I��A��m��P�@�C���A��m�A�V��@��
			Mt[j].row = m[i].col;
			Mt[j].col = m[i].row;
			Mt[j].value = m[i].value;
		}
	}

	free(rowTerm);
	free(startPos);

	return Mt;
}
Term* mmult(Term* a, Term* b)
{
	Term* ans = calloc(a[0].row*b[0].col + 1, sizeof(Term));

	int totalB = b[0].value, colsB = b[0].col;
	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;

	ans[0].row = rowsA;
	ans[0].col = colsB;

	int rowBegin = 1, row = a[1].row, sum = 0, max = a[0].row*b[0].col;

	Term *Bt = fastTranspose(b);//��K�p��A�ܦ����WBt���C�@�C

	int i, j, column, totalAns = 0;//column�Mrow�O��m�᪺
	for (i = 1; i <= totalA;)
	{
		column = Bt[1].row;//�qBt���Ĥ@�C�}�l�p��
		for (j = 1; j <= totalB;)//����totalB�ɴN�O�]��B���C�@�ӫD0�����F
		{
			if (a[i].row != row)//��A�}���x�}��row�w�W�L��e��(�N���L�O0�άO�w��ӦC���̫�@��)�A�N���診�ﭼ�n���s�_��
			{
				storeSum(ans, &totalAns, row, column, &sum, max);
				i = rowBegin;//�qA���P�@�C���Ĥ@�ӫD0�����}�l

				for (; Bt[j].row == column; j++)//��Bt���U�@�C�A�]�N�OB���U�@��
					;
				column = Bt[j].row;
			}
			else if (Bt[j].row != column)//�P�z�A�u�O����Bt��row�W�L�F��e��(�]�N�OB��col�w�g��U�@��F
			{
				storeSum(ans, &totalAns, row, column, &sum, max);//�s�_�ӥثe��sum
				i = rowBegin;//�qA���P�@�C���Ĥ@�ӫD0�����}�l
				
				column = Bt[j].row;
			}
			else
			{
				//�ھ�A�BB�}���x�}��col�A�P�_�O���O�Ӭۭ����A�i��A�x�}����������0�AB�����C
				if (a[i].col > Bt[j].col)
					j++;
				else if (a[i].col == Bt[j].col)
					sum += (a[i++].value*Bt[j++].value);//�����k
				else//a[i].col < Bt[j].col 
					i++;
			}

			if (j > totalB)//A��@�C�MB�C�泣���L�@����Aj�|�W�XtotalB(�w�g��Ҧ��D0���]�L�F)�A���٨S��sum�s�ians
				storeSum(ans, &totalAns, row, column, &sum, max);
		}
		for (; a[i].row == row; i++)//A���U�@�C
			;

		rowBegin = i;
		row = a[i].row;

	}

	ans[0].value = totalAns;//�ۭ����`�@�X�ӫD0����

	free(Bt);

	return ans;
}
void storeSum(Term *m, int *total, int row, int col, int *sum, int max)//�N�D0�Ȧs�J�ӭ��k���G��x�}���۹�����m
{
	if (*sum)
		if (*total < max)
		{
		m[++*total].row = row;
		m[*total].col = col;
		m[*total].value = *sum;
		*sum = 0;
		}
}