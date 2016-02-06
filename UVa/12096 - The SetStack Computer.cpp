#include<cstdio>
#include<set>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

map<set<int>, int> set_id;//�o��set��id
vector<set<int> > v_set;//��id�Ӧs��set
int getId(set<int> s);//�N���@�˪�set�sid
int main()
{
    stack<int> Stack;//�sset��id
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
                    //���pop�X�h���[���pop��
                    b.insert(set_id[a]);
                    Stack.push(getId(b));
                }
            }

            //��X stack.()top �����(set���������ӯ�)
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