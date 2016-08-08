#include<cstdio>

char pattern[32];
int n;
int dfs(int str, int len);
inline bool check(int sub_str, int sub_len);
int main()
{
	int Case = 1;
	while (scanf("%d", &n) && n)
	{
		scanf("%s", pattern);
		printf("Case %d: %d\n", Case++, dfs(0, 0));
	}

	return 0;
}
inline bool check(int sub_str, int sub_len)
{
	int mask = (1 << sub_len) - 1;
	int s1 = sub_str&mask;
	sub_str >>= sub_len;
	int s2 = sub_str&mask;
	sub_str >>= sub_len;
	int s3 = sub_str&mask;

	return (s1 == s2&&s2 == s3);
}
int dfs(int str, int len)
{
	int sub_len = len / 3;
	//剪枝，排除已可以用SSS組成的
	for (int i = 1; i <= sub_len; i++)
		if (check(str >> (len - 3 * i), i))
			return 0;

	if (len == n)
		return 1;
	else if (pattern[len] == '0')
		return dfs(str, len + 1);
	else if (pattern[len] == '1')
		return dfs(str | (1 << len), len + 1);
	else//'*'
		return dfs(str, len + 1) + dfs(str | (1 << len), len + 1);//放 0 + 放 1
}
