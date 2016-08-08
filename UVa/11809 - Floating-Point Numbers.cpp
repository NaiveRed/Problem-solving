#include<cstdio>
#include<cmath>
#define EPS 1e-6

int main()
{
	int E[10][31];
	double M[10][31], mantissa, exp, x;
	
	for (int i = 0; i < 10; i++)
		for (int j = 1; j < 31; j++)
		{
			mantissa = 1 - pow(2, -1 - i);//1-2^(-1-m),���ؤ@�����
			exp = pow(2, j) - 1;//2^e-1
			x = log10(mantissa) + exp*log10(2);//�q�G�i�����Q�i���A��log
			
			double e, m;//�Φ���ǰO��
			e = floor(x);
			m = pow(10, x - e);//10^(x-e)�A�ѤU�p���I������(����Llog)�A1 <= m < 10
			E[i][j] = e;
			M[i][j] = m;
		}

	char num[50];
	while (fgets(num, 50, stdin))
	{
		if (num[0] == '0'&&num[2] == '0')
			break;

		num[17] = ' ';//15 digits after the decimal point.
		int n;
		sscanf(num, "%lf%d", &mantissa, &n);
		for (int i = 0; i < 10; i++)
			for (int j = 1; j < 31; j++)
				if (n == E[i][j] && std::abs(mantissa - M[i][j]) < EPS)//���ƬۦP�A�p���I�~�t�p��EPS
				{
					printf("%d %d\n", i, j);
					break;
				}
	}

	return 0;
}