#include<cstdio>
#define Left(n) ((n)<<1)
#define Right(n) (((n)<<1)+1)
#define N 32768

int tree[N];
bool isVisit[N];
inline bool input(int& val, char *str)
{
	char c;
	val = 0;
	while ((c = getchar()) != '(')
		if (c == EOF)
			return false;

	if ((c = getchar()) == ')')
		return false;
	else
		val = c - '0';

	while ((c = getchar()) != ',')
		val = val * 10 + c - '0';

	int i;
	for (i = 0;; i++)
	{
		c = getchar();

		if (c == ')')
		{
			str[i] = NULL;
			break;
		}

		str[i] = c;
	}

	return true;
}
inline bool insert(int val, char* str)
{
	int idx = 1;
	if (!str[0])
	{
		if (tree[1] != -1)
			return false;
		tree[1] = val;
		return true;
	}

	for (int i = 0; str[i]; i++)
		if (str[i] == 'L')
			idx = Left(idx);
		else
			idx = Right(idx);

	if (tree[idx] != -1)//處理重複節點
		return false;

	tree[idx] = val;
	return true;
}
inline void traverse(int idx)//VLR
{
	if (idx < N&&tree[idx] != -1)
	{
		isVisit[idx] = true;
		traverse(Left(idx));
		traverse(Right(idx));
	}
}
int main()
{
	int val;
	char str[10];

	while (input(val, str))
	{
		int i, count = 1;
		bool isOk = true;

		for (i = 0; i < N; i++)
		{
			tree[i] = -1;
			isVisit[i] = false;
		}

		isOk = insert(val, str);
		while (input(val, str))
		{
			if (isOk)
			{
				isOk = insert(val, str);
				count++;
			}
		}

		if (isOk)
		{
			traverse(1);

			int temp = 0;
			for (i = 1; i < N&&temp < count; i++)
				if (tree[i] != -1)
				{
					if (isVisit[i])
						temp++;
					else
					{
						isOk = false;
						break;
					}
				}
		}

		if (isOk)
		{
			bool first = true;
			int temp = 0;
			for (i = 0; i < N&&temp < count; i++)
			{
				if (tree[i] != -1)
				{
					if (first)
						first = false;
					else
						putchar(' ');

					printf("%d", tree[i]);
					temp++;
				}
			}
			putchar('\n');
		}
		else
			puts("not complete");

	}

	return 0;
}
