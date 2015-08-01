/*
e.g.:

abdcccba   答案:acabbccd
(照題目最終字典序是dcccbbaa)

1.從最後開始找，找到相鄰左邊小於右邊的(找目前要變更的字典序)

2.a'b'dcccba，再從'b'後的最尾端開始找(因為從後面看過來一定是從小到大，要不在1.就被找到了)
找到大於'b'的，abdcc'c'ba，將他們交換(也就是下一個字典序了)，a'c'dcc'b'ba

3.接著再排出這個字典序的最開始，ac abbccd  (空格後開始做sort的結果)

*/
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

int main()
{
	char str[60];

	while (gets(str) && str[0] != '#')
	{
		int len(strlen(str));
		int index(len - 1);

		while ((str[index - 1] > str[index] || str[index - 1] == str[index]) && index)
			index--;

		if (!index)
			puts("No Successor");
		else
		{
			index--;
			int next(len - 1);
			while (str[index] == str[next] || str[index] > str[next])
				next--;

			char temp;
			temp = str[index];
			str[index] = str[next];
			str[next] = temp;

			std::string sstr(str);
			std::sort(sstr.begin()+index+1,sstr.end(), [](char a, char b){return a < b; });

			printf("%s\n", sstr.c_str());
		}

	}
	return 0;
}