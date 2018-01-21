#include <cstdio>

inline int get_month(char *str)
{
	if ((str[0] == 'J' && str[1] == 'a'))
		return 1;
	if (str[0] == 'F')
		return 2;

	return 0; //3~12
}
inline bool leap(int y)
{
	if (!(y % 4))
	{
		if (y % 100)
			return true;
		else
			return !(y % 400);
	}
	return false;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		char m1[20], m2[20];
		int day1, day2, year1, year2;
		scanf("%s%d,%d", m1, &day1, &year1);
		scanf("%s%d,%d", m2, &day2, &year2);
		int count1 = year1 / 4 - year1 / 100 + year1 / 400;
		int count2 = year2 / 4 - year2 / 100 + year2 / 400;
		if (leap(year1) && get_month(m1))
			count1--;
		if (leap(year2) && (get_month(m2) == 1 || (get_month(m2) == 2 && day2 < 29)))
			count2--;
		printf("Case %d: %d\n", t, count2 - count1);
	}

	return 0;
}