#include<cstdio>

int main()
{

	int Case;

	while (scanf("%d", &Case) != EOF)
	{

		while (Case--)
		{
			
			char lv[3][10], rv[3][10], result[3][10];
			for (int i = 0; i < 3; i++)
				scanf("%s%s%s", lv[i], rv[i], result[i]);

			for (int fake = 0; fake < 12; fake++)//�Q�νa�|�A���]�C�@�ӿ����O�����A�A�N�J���p
			{
				int suml, sumr, i;
				
				//����������
				for ( i = 0; i < 3; i++)
				{
					suml = sumr = 0;
					for (int k = 0; lv[i][k]; k++)
						suml += ((lv[i][k] - 'A') != fake);

					for (int r = 0; rv[i][r]; r++)
						sumr += ((rv[i][r] - 'A') != fake);

					if (result[i][0] == 'e'&&suml == sumr)
						continue;
					if (result[i][0] == 'u'&&suml > sumr)
						continue;
					if (result[i][0] == 'd'&&suml < sumr)
						continue;
					
					break;
				}
				if (i == 3)
				{
					printf("%c is the counterfeit coin and it is light.\n", 'A' + fake);
					break;
				}

				//����������
				for (i = 0; i < 3; i++)
				{
					suml = sumr = 0;
					for (int k = 0; lv[i][k]; k++)
						suml += ((lv[i][k] - 'A') == fake);

					for (int r = 0; rv[i][r]; r++)
						sumr += ((rv[i][r] - 'A') == fake);
				
					if (result[i][0] == 'e'&&suml == sumr)
						continue;
					if (result[i][0] == 'u'&&suml >sumr)
						continue;
					if (result[i][0] == 'd'&&suml < sumr)
						continue;

					break;
				}
				if (i == 3)
				{
					printf("%c is the counterfeit coin and it is heavy.\n", 'A' + fake);
					break;
				}
			}

		}

	}

	return 0;
}
