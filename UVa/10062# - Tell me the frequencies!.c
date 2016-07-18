#include<stdio.h>

int main(){

	char s[1002];
	int frequency[256];
	int set = 0;
	struct show
	{
		int ascii;
		int count;
	}show[256];

	while (gets(s))
	{
		if (set)puts("");
		int i, j = 0;
		for (i = 0; i < 256; i++)
			frequency[i] = 0;
		for (i = 0; s[i]; i++)
			frequency[s[i]]++;
		for (i = 0; i < 256; i++)//由ascii小存到大
			if (frequency[i]){
			show[j].count = frequency[i];
			show[j++].ascii = i;
			}
		j--;
		int k, temp;
		for (i = j; i >= 1; i--)
			for (k = 0; k < i; k++)
				if (show[k].count < show[k + 1].count)//次數由小到大
				{
			temp = show[k].count;
			show[k].count = show[k + 1].count;
			show[k + 1].count = temp;
			
                        temp = show[k].ascii;
			show[k].ascii = show[k + 1].ascii;
			show[k + 1].ascii = temp;
				}

		for (i = j; i>=0 ; i--)//次數相同時，輸出ascii大的，所以要從j到0
			printf("%d %d\n", show[i].ascii, show[i].count);
		set = 1;
	}


	return 0;
}