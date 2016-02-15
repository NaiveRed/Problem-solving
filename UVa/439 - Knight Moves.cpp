#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> Pair;
int BFS(Pair& start, Pair& tar);
int main()
{
    Pair start, tar;
    char str[10];

    while (gets(str))
    {
        //1~8
        start.second = str[0] - 'a' + 1;
        start.first = str[1] - '0';

        tar.second = str[3] - 'a' + 1;
        tar.first = str[4] - '0';

        printf("To get from %c%c to %c%c takes %d knight moves.\n", str[0], str[1], str[3], str[4], BFS(start, tar));
    }

    return 0;
}
int BFS(Pair& start, Pair& tar)
{
    const int dir[8][2] = { { 1, 2 }, { -1, -2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, { -1, 2 }, { -2, 1 }, { -2, -1 } };
    int step[9][9] = { 0 };
    bool isVisit[9][9] = { false };
    queue < Pair > Q;

    Q.push(start);

    while (!Q.empty())
    {
        int now_x = Q.front().first, now_y = Q.front().second;
        Q.pop();

        if (now_x == tar.first&&now_y == tar.second)
            return step[now_x][now_y];

        
        isVisit[now_x][now_y] = true;

        for (int i = 0; i < 8; i++)
        {
            int temp_x = now_x + dir[i][0], temp_y = now_y + dir[i][1];
            if (temp_x >= 1 && temp_x <= 8 && temp_y >= 1 && temp_y <= 8)
                if (!isVisit[temp_x][temp_y])
                {
                isVisit[temp_x][temp_y] = true;
                step[temp_x][temp_y] += (step[now_x][now_y] + 1);//¨B¼Æ­pºâ
                Q.push(Pair(temp_x, temp_y));
                }
        }
    }

    return -1;
}