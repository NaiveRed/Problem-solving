#include<cstdio>

int main()
{

	char temp;

	while ((temp = getchar()) != EOF)
	{

		int x[251]{temp - '0'}, y[251]{0};

		//Ū�J�Ʀr�A�̰���bx[0]
		int i(1);
		while ((temp = getchar()) != '\n')
			x[i++] = temp - '0';

		int j(0);
		while ((temp = getchar()) != '\n')
			y[j++] = temp - '0';

		int ans[501]{0};
		for (int n = i-1 ; n >= 0; n--)
			for (int m = j - 1; m >= 0; m--)
				ans[n + m] = ans[n + m] + x[n] * y[m];//�p�������k: x��n�� * y��m�� = ans�� n+m �� �A�[�W���e�w�[�L��

		int len(i+j-2);//n + m = i - 1 + j - 1 
		
		//�i��B�z�A�q�̧C��}�l
		while (len >0)
		{
			
			if (ans[len] >= 10)
			{
				ans[len - 1] += (ans[len ] / 10);
				ans[len] %= 10;
			}

			len--;
		}
		len = i + j - 2;

		//�B�z�Ĥ@��ƭn�i�쪺���p(�]��ans[index],index���i��-1)
		if (ans[0] >= 10)
		{
			int first = (ans[0] / 10);
			ans[0] %= 10;
			putchar(first + '0');
		}
		//�B�z���׬�0�����p
		else if (!ans[0] )
		{
			puts("0");
			continue;
		}

		for (int n = 0; n <= len; n++)
			putchar(ans[n] + '0');
			
		putchar('\n');
	}

	return 0;
}