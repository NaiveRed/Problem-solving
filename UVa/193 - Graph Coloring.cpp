#include <cstdio>
#include <list>
#include <algorithm>

std::list<int> adjList[101];
std::list<int> black;
int vertex;      //the number of points
int max;         //the number of black points
int optima[100]; //the ans
bool color[101]; //false is white,true is black

void backtracking(int point);
int main()
{
    int Case;

    scanf("%d", &Case);

    while (Case--)
    {
        int e; //edge
        scanf("%d%d", &vertex, &e);

        while (e--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        backtracking(1);

        printf("%d\n", max);
        for (int i = 0; i < max - 1; i++)
            printf("%d ", optima[i]);
        printf("%d\n", optima[max - 1]);

        //init
        max = 0;
        for (int i = 1; i <= vertex; i++)
            adjList[i].clear();
    }

    return 0;
}
void backtracking(int point)
{

    if (point > vertex)
    {
        int temp = black.size();
        if (temp > max)
        {
            int i = 0;
            for (int n : black)
                optima[i++] = n;
            max = temp;
        }
    }
    else if (vertex - point + 1 + black.size() < max) 
    {
        //剩下的點全黑也沒辦法超過目前最佳的話就停止
        return;
    }
    else
    {
        bool isBlack = true;
        for (int n : adjList[point])
            if (color[n])
            {
                isBlack = false;
                break;
            }

        if (isBlack)
        {
            //此點為黑色的情況下繼續做遞迴
            color[point] = true;
            black.push_back(point);

            backtracking(point + 1);

            //換成此點為白色
            color[point] = false;
            black.pop_back();
        }

        //此點為白色的情況下做遞迴
        backtracking(point + 1);
    }
}