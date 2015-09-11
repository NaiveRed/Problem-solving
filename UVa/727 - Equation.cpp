/*
中序式轉後序式
*/

#include<cstdio>
#include<stack>

using std::stack;
inline int priority(char c);
int main()
{
	stack<char> Stack;

	int Case;
	scanf("%d", &Case);
	getchar();
	getchar();

	char c;
	for (int i = 0; i < Case; i++)
	{
		if (i)
			putchar('\n');

		while ((c = getchar()) != '\n'&&c!=EOF)
		{
			if (c == '(')
				Stack.push(c);
			else if (c == '*' || c == '/' || c == '+' || c == '-')
			{
				if (!Stack.empty())
				while ( priority(Stack.top()) >= priority(c)&&Stack.top()!='(')
				{
					putchar(Stack.top());
					Stack.pop();
					if (Stack.empty())
						break;
				}

				Stack.push(c);
			}
			else if (c == ')')
			{
				while (Stack.top() != '(')
				{
					putchar(Stack.top());
					Stack.pop();
				}

				Stack.pop();
			}
			else putchar(c);

			getchar();
		}

		while (!Stack.empty())
		{
			putchar(Stack.top());
			Stack.pop();
		}

		putchar('\n');
	}


	return 0;
}
int priority(char c)
{
	if (c == '*' || c == '/')
		return 2;

	return 1;
}