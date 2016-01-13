#include<cstdio>

struct card
{
	char s;
	int val;

	card()
	{
		s = NULL;
		val = 0;
	}

};

inline bool match(card &a, card &b);
inline void push(card *p, int &top, card tar);
inline void pop(card *p, int &top);

int main()
{
	card pile[53][53] = {};
	int top[53] = {};

	int i = 1;
	char c;
	bool flag = false;

	while ((c = getchar()) != '#')
	{
		//��J�B�z
		if (c == ' ' || c == '\n')
			continue;

		if (flag)
		{
			pile[i][top[i]].s = c;
			flag = false;
			i++;
		}
		else
		{
			int t = 0;
			if (c == 'A')
				t = 1;
			else if (c == 'T')
				t = 10;
			else if (c == 'J')
				t = 11;
			else if (c == 'Q')
				t = 12;
			else if (c == 'K')
				t = 13;

			pile[i][++top[i]].val = t ? t : c - '0';
			flag = true;
		}

		//�w�����@�տ�J
		if (i == 53)
		{
			for (i = 1; i < 53; i++)
			{
				int j = i;
				while (j <= i)
				{
					if (!top[j])
					{
						j++;
						continue;
					}

					int k, n = 1;
					int left1 = -1, left3 = -1;//�V��1��M�V���T�檺��m

					//���ʨ�ؼеP��(�`�N�Ū�)
					for (k = j - 1; k > 0; k--)
						if (top[k])
						{
						left1 = k;
						break;
						}

					//���ʨ�ؼеP��(�`�N�Ū�)
					for (k = left1 - 1; k > 0; k--)
					{
						if (top[k])
							n++;
						if (n == 3)
						{
							left3 = k;
							break;
						}
					}

					if (left3 != -1)
					{
						if (match(pile[j][top[j]], pile[left3][top[left3]]))
						{
							push(pile[left3], top[left3], pile[j][top[j]]);
							pop(pile[j], top[j]);
							j = left3;//��ʹL��A����᭱���A�ˬd�@��
							continue;
						}
					}

					if (left1 != -1)
					{
						if (match(pile[j][top[j]], pile[left1][top[left1]]))
						{
							push(pile[left1], top[left1], pile[j][top[j]]);
							pop(pile[j], top[j]);
							j = left1;//��ʹL��A����᭱���A�ˬd�@��
							continue;
						}

					}

					//�ѥ��V�k�@�Ӥ@���ˬd
					j++;
				}
			}

			int count = 0, ans[52] = {};
			for (i = 1; i < 53; i++)
				if (top[i])
				{
				ans[count++] = top[i];
				top[i] = 0;
				}

			printf("%d pile%sremaining:", count, count == 1 ? " " : "s ");
			for (i = 0; i < count; i++)
				printf(" %d", ans[i]);
			putchar('\n');

			i = 1;
		}
	
	}

	return 0;
}
bool match(card &a, card &b)
{
	return a.s == b.s || a.val == b.val;
}
void push(card *p, int &top, card tar)
{
	p[++top] = tar;
}
void pop(card *p, int &top)
{
	p[top--] = card();
}