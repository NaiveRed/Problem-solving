#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        priority_queue<int, vector<int>, greater<int> > PQ;
        int n, i, num;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num);
            PQ.push(num);
        }

        //類似 huffman code，只是將權重改為 ( W + L )
        for (i = 1; i < n; i++)
        {
            int a = PQ.top();
            PQ.pop();
            int b = PQ.top();
            PQ.pop();

            PQ.push((a>b) ? a + 1 : b + 1);//表此節點下的最大 ( w + l )
        }

        printf("%d\n", PQ.top());
    }

    return 0;
}