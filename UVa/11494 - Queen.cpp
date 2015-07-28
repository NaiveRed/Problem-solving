#include<cstdio>
#include<cstdlib>

int main()
{
	char coord[10];
	while (gets(coord))
	{
		if (coord[0] == '0' && coord[2] == '0' && coord[4] == '0' && coord[6] == '0')
			break;

		int x(abs(coord[0] - coord[4])), y(abs(coord[2] - coord[6]));

		if (!x&&!y)
			puts("0");
		else if (!x || !y || (x == y))
			puts("1");
		else puts("2");
	}

	return 0;
}