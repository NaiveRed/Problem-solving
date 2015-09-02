#include<cstdio>

int input();
int main()
{
	int Case = input();

	puts("INTERSECTING LINES OUTPUT");
	while (Case--)
	{
		double x1, y1, x2, y2;//1st line
		double x3, y3, x4, y4;//2nd line

		x1 = input();
		y1 = input();
		x2 = input();
		y2 = input();

		x3 = input();
		y3 = input();
		x4 = input();
		y4 = input();

		// y = mx + b

		double m1, m2;//斜率
		double b1, b2;
		if (x1 != x2&&x3 != x4)
		{
			m1 = (y2 - y1) / (x2 - x1);
			m2 = (y4 - y3) / (x4 - x3);
			b1 = y1 - m1*x1;
			b2 = y3 - m2*x3;

			if (m1 == m2)
			{

				if (b1 == b2)
					puts("LINE");
				else puts("NONE");
			}
			else
			{
				double x = (b2 - b1) / (m1 - m2);
				double y = m1*x + b1;
				printf("POINT %.2lf %.2lf\n", x, y);
			}
		}
		else if (x1 == x2&&x3 == x4)//兩條都為鉛直線
		{
			if (x1 == x3)
				puts("LINE");
			else puts("NONE");
		}
		else if (x1 != x2&&x3 == x4)
		{
			double m = (y2 - y1) / (x2 - x1);
			double b = y1 - m*x1;

			double y = m*x3 + b;

			printf("POINT %.2lf %.2lf\n", x3, y);

		}
		else
		{
			double m = (y4 - y3) /(x4 - x3);
			double b = y3 - m*x3;

			double y = m*x1 + b;

			printf("POINT %.2lf %.2lf\n", x1, y);
		}
	}
	puts("END OF OUTPUT");

	return 0;
}
int input()
{
	char c = getchar();
	int num(0);
	bool flag(false);

	if (c == '-')
		flag = true;
	else num = c - '0';

	while ((c = getchar()) != '\n'&&c != ' ')
		num = num * 10 + c - '0';

	return flag ? num*-1 : num;
}