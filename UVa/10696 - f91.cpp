#include<cstdio>
#define MAX 1000001

int f[MAX];

inline void f91();
inline int input();
int main()
{
	f91();
	
	int num;

	while (num =input())
		printf("f91(%d) = %d\n", num, f[num]);

	return 0;

}
int input()
{
	char c;
	int num(0);

	while ((c = getchar()) != '\n')
		num = num * 10 + c - '0';

	return num;
}
void f91()
{
	for (int i = 101, j = i - 10; i < MAX; i++, j++)
		f[i] = j;
	
	for (int i = 100; i; i--)
		f[i] = f[f[i+11]];
}