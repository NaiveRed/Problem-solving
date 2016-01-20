#include<cstdio>
#include<vector>
#include<algorithm>

int main()
{
	int cake[30] = {}, flip_pos[50] = {},i;
	char str[150];

	while (gets(str))
	{
		//input token
		int count = 0, num = 0, flip = 0;
		for (i = 0; str[i]; i++)
		{
			if (str[i] != ' ')
				num = num * 10 + str[i] - '0';
			else
			{
				cake[count++] = num;
				num = 0;
			}
		}
		cake[count++] = num;

		std::vector<int> v;
		//cake[0] is top
		for (i = count - 1; i >= 0; i--)
			v.push_back(cake[i]);

		//v[0] is bottom
		for (i = 0; i < count; i++)
		{
			int max = v[i], pos = 0;
			for (int j = i + 1; j < count; j++)
				if (max < v[j])
				{
				max = v[j];
				pos = j;
				}

			//底部的flip pos為1
			if (pos)
			{
				//較大的在頂部，則不用轉
				if (pos != count - 1)
				{
					std::reverse(v.begin() +pos, v.end());
					flip_pos[flip++] = pos + 1;
				}

				std::reverse(v.begin() + i, v.end());
				flip_pos[flip++] = i + 1;
			}
		}

		//output
		puts(str);
		for (i = 0; i < flip; i++)
			printf("%d ", flip_pos[i]);
		puts("0");

	}

	return 0;
}