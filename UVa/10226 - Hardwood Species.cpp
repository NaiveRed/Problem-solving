#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<iostream>

using namespace std;
int main()
{

	int Case;
	scanf("%d", &Case);
	scanf("\r\r");

	while (Case--)
	{
		map<string, int> forest;
		set<string> tree;
		char cStr[40];
		int sum(0);

		while (gets(cStr) && cStr[0])
		{
			sum++;
			string str(cStr);
			forest[str]++;
			tree.insert(str);
		}

		for (string s : tree)
			printf("%s %.4lf\n", s.c_str(), (double)forest[s] * 100 / sum);

		if (Case)
			puts("");
	}

	return 0;
}

