#include<stdio.h>

void sets(int set, char relationship[]);
void show(int set, char relationship[]);

int main(){

	int  set;
	char relationship[15];

	while (scanf("%d", &set) != EOF)
	{
		sets(set, relationship);

		show(set, relationship);
	}

	return 0;

}
void sets(int set, char relationship[]){
	int i, a, b;
	for (i = 0; i < set; i++)
	{
		scanf("%d %d", &a, &b);
		if (a > b)
			relationship[i] = '>';
		else if (b > a)
			relationship[i] = '<';
		else if (a == b)
			relationship[i] = '=';
	}
}

void show(int set, char relationship[]){
	int i;
	for (i = 0; i <set; i++)
		printf("%c\n", relationship[i]);
}