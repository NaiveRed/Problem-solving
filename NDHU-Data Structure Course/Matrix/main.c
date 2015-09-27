#include <stdio.h>
#include"Matrix.h"
#include<stdlib.h>

int main()
{
    Term m1[50],m2[50];
    int i,j,nonZero=0;

	printf("m1:");
	scanf("%d%d", &m1[0].row, &m1[0].col);

	for (i = 1; i <= m1[0].row; i++)
		for (j = 1; j <= m1[0].col; j++)
        {
            int temp;
            scanf("%d",&temp);
            if(temp)
                {
				m1[++nonZero].row = i;
				m1[nonZero].col = j;
				m1[nonZero].value = temp;
                }
        }

	m1[0].value = nonZero;
	
	nonZero = 0;
	
	printf("m2:");
	scanf("%d%d", &m2[0].row, &m2[0].col);

	for (i = 1; i <= m2[0].row; i++)
		for (j = 1; j <= m2[0].col; j++)
		{
		int temp;
		scanf("%d", &temp);
		if (temp)
		{
			m2[++nonZero].row = i;
			m2[nonZero].col = j;
			m2[nonZero].value = temp;
		}
		}

	m2[0].value = nonZero;

    Term *Mt=fastTranspose(m1);

    printf("\nm1's transpose:\n");
    for(i=0;i<=Mt[0].value;i++)
        printf("%d %d %d\n",Mt[i].row,Mt[i].col,Mt[i].value);

    Term* multMatrix=mmult(m1,m2);

    printf("\nmulti:\n");
    for(i=0;i<=multMatrix[0].value;i++)
        printf("%d %d %d\n",multMatrix[i].row,multMatrix[i].col,multMatrix[i].value);
	
	free(multMatrix);
	free(Mt);

	system("pause");
    return 0;
}
