#include<cstdio>
#include<set>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

map<set<int>, int> set_id;//得到set的id
vector<set<int> > v_set;//用id來存取set
int getId(set<int> s);//將不一樣的set編id
int main()
{
    stack<int> Stack;//存set的id
    int Case, n;
    scanf("%d", &Case);

    char str[10];
    while (Case--)
    {
        scanf("%d", &n);
        getchar();
        while (n--)
        {
            gets(str);
            if (str[0] == 'P')
                Stack.push(getId(set<int>()));
            else if (str[0] == 'D')
                Stack.push(Stack.top());
            else
            {
                set<int> a, b, result;
                a = v_set[Stack.top()];
                Stack.pop();
                b = v_set[Stack.top()];
                Stack.pop();

                if (str[0] == 'U')
                {
                    //union
                    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
                    Stack.push(getId(result));
                }
                else if (str[0] == 'I')
                {
                    //intersection;
                    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
                    Stack.push(getId(result));
                }
                else if (str[0] == 'A')
                {
                    //把先pop出去的加到後pop的
                    b.insert(set_id[a]);
                    Stack.push(getId(b));
                }
            }

            //輸出 stack.()top 的基數(set內的元素個素)
            printf("%d\n", v_set[Stack.top()].size());
        }

        puts("***");
    }

    return 0;
}
int getId(set<int> s)
{
    if (!set_id.count(s))
    {
        v_set.push_back(s);
        set_id[s] = v_set.size() - 1;
    }

    return set_id[s];
}