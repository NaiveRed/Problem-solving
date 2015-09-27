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
	Term* ans = calloc(a[0].row*b[0].col + 1, sizeof(Term));//[0]是總共幾行幾列跟非0的量，所以要+1

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

		//轉置後的每一列有幾個非0元素
		for (i = 1; i <= m[0].value; i++)
			rowTerm[m[i].col]++;

		/*for (i = 1; i <= m[0].col; i++)
			printf("row[%d]有%d個非0\n", i, rowTerm[i]);*/

		//轉置後每一列的開始位置
		startPos[0] = 1;
		for (i = 1; i <= m[0].col; i++)
			startPos[i] = startPos[i - 1] + rowTerm[i - 1];

		/*for (i = 1; i <= m[0].col; i++)
			printf("row[%d]從%d開始\n", i, startPos[i]);*/

		for (i = 1; i <= m[0].value; i++)
		{
			int j = startPos[m[i].col]++;//接下來如果再碰到，轉置後同一列的，位置再向後一個
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

	Term *Bt = fastTranspose(b);//方便計算，變成乘上Bt的每一列

	int i, j, column, totalAns = 0;//column和row是轉置後的
	for (i = 1; i <= totalA;)
	{
		column = Bt[1].row;//從Bt的第一列開始計算
		for (j = 1; j <= totalB;)//等於totalB時就是跑完B的每一個非0元素了
		{
			if (a[i].row != row)//當A稀疏矩陣的row已超過當前的(代表其他是0或是已到該列的最後一個)，就把剛剛那對乘好的存起來
			{
				storeSum(ans, &totalAns, row, column, &sum, max);
				i = rowBegin;//從A的同一列的第一個非0元素開始

				for (; Bt[j].row == column; j++)//到Bt的下一列，也就是B的下一行
					;
				column = Bt[j].row;
			}
			else if (Bt[j].row != column)//同理，只是換成Bt的row超過了當前的(也就是B的col已經到下一行了
			{
				storeSum(ans, &totalAns, row, column, &sum, max);//存起來目前的sum
				i = rowBegin;//從A的同一列的第一個非0元素開始
				
				column = Bt[j].row;
			}
			else
			{
				//根據A、B稀疏矩陣的col，判斷是不是該相乘的，可能A矩陣的此元素為0，B不為。
				if (a[i].col > Bt[j].col)
					j++;
				else if (a[i].col == Bt[j].col)
					sum += (a[i++].value*Bt[j++].value);//做乘法
				else//a[i].col < Bt[j].col 
					i++;
			}

			if (j > totalB)//A把一列和B每行都做過一次後，j會超出totalB(已經把所有非0的跑過了)，但還沒把sum存進ans
				storeSum(ans, &totalAns, row, column, &sum, max);
		}
		for (; a[i].row == row; i++)//A換下一列
			;

		rowBegin = i;
		row = a[i].row;

	}

	ans[0].value = totalAns;//相乘後總共幾個非0的值

	free(Bt);

	return ans;
}
void storeSum(Term *m, int *total, int row, int col, int *sum, int max)//將非0值存入該乘法結果後矩陣的相對應位置
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