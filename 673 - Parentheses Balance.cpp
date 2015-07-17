#include<cstdio>
#include<stack>
#define N 130

int main()
{
	std::stack<char> parentheses;
	int n;
	
	while (scanf("%d",&n)!=EOF)
	{
		getchar();//scanf("\r")
		while (n--)
		{
			char s[N]{NULL};
			
			gets(s);//¿é¤J¤£¥u()[] e.g. ()fsdfsdf[]
			
			for (int i = 0; s[i]; i++)
			{
				if (s[i] == '(' || s[i] == '[')
					parentheses.push(s[i]);
				else if (s[i] == ')')
				{
					if (!parentheses.empty())
					{
						if (parentheses.top() == '(')
							parentheses.pop();
					}
					else parentheses.push(')');
				}
				else if (s[i] == ']')
				{
					if (!parentheses.empty())
					{
						if (parentheses.top() == '[')
							parentheses.pop();
					}
					else parentheses.push(']');
				}
			}

			printf("%s\n", parentheses.empty() ? "Yes" : "No");
		
			while (!parentheses.empty())
				parentheses.pop();
		}

	}

	return 0;
}