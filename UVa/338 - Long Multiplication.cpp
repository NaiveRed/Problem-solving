#include<cstdio>
#include<cctype>
#include<algorithm>

struct BigNum{

	int num[25];
	int len;

};

BigNum x, y;
BigNum process[12], ans;

bool input();
void output();
int main()
{


	while (input())
	{
		
		for (int n = 0; n < y.len; n++)//列數為y的數字位數
		{
			for (int m = 0; m < x.len; m++)
				process[n].num[n + m] = process[n].num[n + m] + y.num[n] * x.num[m];//如直式乘法: x的m位 * y的n位 = process的 n+m 位 再加上之前已加過的

			process[n].len = x.len + n;//要加上前面預留的位子

		}
		//進位處理，從最低位開始
		for (int k = 0; k < y.len; k++)
			for (int l = 0; l < process[k].len; l++)
				if (process[k].num[l] >= 10)
				{
			process[k].num[l + 1] += (process[k].num[l] / 10);
			process[k].num[l] %= 10;

			if (l == process[k].len - 1)
			{
				process[k].len++;
				break;
			}

				}

		//計算結果，把每一層加起來
		for (int k = 0; k < y.len; k++)
			for (int l = k; l < process[k].len + k; l++)
			{
			ans.num[l] += process[k].num[l];
			if (ans.num[l] >= 10)
			{
				ans.num[l + 1] += (ans.num[l] / 10);
				ans.num[l] %= 10;
			}
			}

		//計算最終長度
		for (int len = 20; len >= 0; len--)
			if (ans.num[len])
			{
			ans.len = len + 1;
			break;
			}

		output();

		//clear
		for (int i = 0; i < y.len; i++)
		{
			for (int j = 0; j < 25; j++)
				process[i].num[j] = 0;
			process[i].len = 0;
		}

		for (int j = 0; j < 25; j++)
			ans.num[j] = 0;
		ans.len = 0;

		for (int j = 0; j < 25; j++)
			y.num[j] = 0;
		y.len = 0;

		for (int j = 0; j < 25; j++)
			x.num[j] = 0;
		x.len = 0;

	}


	return 0;
}
bool input()
{
	char str[100];
	long long temp1, temp2;
	
	gets(str);
	
		if (!str[1])
			return false;

		sscanf(str, "%lld%lld",&temp1 , &temp2);

		if (!temp1)
			x.num[x.len++] = 0;
		if (!temp2)
			y.num[y.len++] = 0;

		while (temp1)
		{
			x.num[x.len++] = temp1 % 10;
			temp1 /= 10;
		}
		while (temp2)
		{
			y.num[y.len++] = temp2 % 10;
			temp2 /= 10;
		}


		return true;
}
void output()
{
	int i, j;
	char str[30]{'\0'};

	bool isZero(true);

	//檢查答案是否為0
	for (i = 0; i < ans.len; i++)
		if (ans.num[i])
			isZero = false;

	for (i = x.len - 1, j = 0; i >= 0; i--, j++)
		str[j] = x.num[i] + '0';

	printf("%*s\n", isZero ? std::max(x.len, y.len) : ans.len, str);

	for (i = y.len - 1, j = 0; i >= 0; i--, j++)
		str[j] = y.num[i] + '0';
	str[j] = '\0';

	printf("%*s\n", isZero ? std::max(x.len, y.len) : ans.len, str);

	printf("%*.*s\n", ans.len, std::max(x.len, y.len), "----------");

	if (isZero)
	{
		printf("%*d\n\n", isZero ? std::max(x.len, y.len) : ans.len, 0);
		return;
	}

	int oneLine(0);//判斷是否只有一列(ex. 123 100 應輸出"---\n12300" 
	int k;

	for (i = 0; i < y.len; i++)
	{
		isZero = true;//判斷此列是否都為0

		for (j = process[i].len - 1, k = 0; j >= i; j--, k++)
		{
			str[k] = process[i].num[j] + '0';
			if (isZero&&str[k] != '0')
			{
				isZero = false;
				oneLine++;
			}
		}
		str[k] = '\0';

		if (!isZero)
		{
			if (oneLine <= 1 && i == y.len - 1)
				break;
			printf("%*s\n", ans.len - i, str);
		}
	}

	if (oneLine > 1)
	{

		printf("%.*s\n", ans.len, "-------------------------");

		for (i = ans.len - 1, j = 0; i >= 0; i--, j++)
			str[j] = ans.num[i] + '0';
		str[j] = '\0';

		printf("%s\n", str);
	}
	else
	{
		for (i = ans.len - 1, j = 0; i >= 0; i--, j++)
			str[j] = ans.num[i] + '0';
		str[j] = '\0';

		printf("%s\n", str);
	}

	putchar('\n');
}