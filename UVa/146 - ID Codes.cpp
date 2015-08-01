/*
e.g.:

abdcccba   ����:acabbccd
(���D�س̲צr��ǬOdcccbbaa)

1.�q�̫�}�l��A���۾F����p��k�䪺(��ثe�n�ܧ󪺦r���)

2.a'b'dcccba�A�A�q'b'�᪺�̧��ݶ}�l��(�]���q�᭱�ݹL�Ӥ@�w�O�q�p��j�A�n���b1.�N�Q���F)
���j��'b'���Aabdcc'c'ba�A�N�L�̥洫(�]�N�O�U�@�Ӧr��ǤF)�Aa'c'dcc'b'ba

3.���ۦA�ƥX�o�Ӧr��Ǫ��̶}�l�Aac abbccd  (�Ů��}�l��sort�����G)

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