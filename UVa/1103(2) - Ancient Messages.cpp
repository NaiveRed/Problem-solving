#include <cstdio>
#include <cctype>
#include <cstring>
#include <stack>
#include <utility>
#define WHITE 0
#define BLACK 1
#define NONE -1
using namespace std;
typedef pair<int, int> node;

int H, W;
// 上下左右
const int dir_x[4] = {-1, 0, 0, 1}; //r
const int dir_y[4] = {0, -1, 1, 0}; //c
// 6 個圖形的空格: (A,1), (J,3), (D,5), (S,4), (W,0), (K,2)
const int white_to_type_idx[6] = {5, 0, 3, 2, 4, 1}; //有3個空格: white_to_type_idx[3] = 2 => type[2] = 'J'
const char type[6] = {'A', 'D', 'J', 'K', 'S', 'W'}; // alphabetic order
int image[201][50 * 4 + 1];                          // [1][1] 為左上角
bool visit[201][50 * 4 + 1];
int white_count;

bool in_border(int r, int c);
void init_image();
void dfs_init_image(int r, int c);
void dfs_scan_lang(int r, int c);
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    char *hex[16] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"};

    int Case = 0;
    while (scanf("%d%d", &H, &W) != EOF && H && W)
    {
        int i, j, k;
        getchar();
        char c;
        for (i = 1; i <= H; i++)
        {
            for (j = 1; j <= W; j++)
            {
                c = getchar();
                int num = isalpha(c) ? c - 'a' + 10 : c - '0';
                for (k = 0; k < 4; k++)
                {
                    image[i][4 * (j - 1) + k + 1] = (hex[num][k] == '0') ? WHITE : BLACK;                    
                    visit[i][4 * (j - 1) + k + 1] = false;
                }
            }

            getchar();
        }

        //init
        W *= 4;
        memset(visit, false, sizeof visit);
        init_image();
        int type_count[6] = {}; // 計算各種類有幾個

        /*for (i = 1; i <= H; i++)
        {
            for (j = 1; j <= W; j++)
                printf("%3d", image[i][j]);
            putchar('\n');
        }*/

        for (i = 1; i <= H; i++)
            for (j = 1; j <= W; j++)
                if (!visit[i][j] && image[i][j] == BLACK)
                {
                    white_count = 0;
                    dfs_scan_lang(i, j);
                    type_count[white_to_type_idx[white_count]]++;
                }

        printf("Case %d: ", ++Case);
        for (i = 0; i < 6; i++)
            for (j = 0; j < type_count[i]; j++)
                putchar(type[i]);
        putchar('\n');
    }

    return 0;
}
inline bool in_border(int r, int c)
{
    return (r && c && r <= H && c <= W);
}
void init_image()
{
    int i;
    // 將與古文字無關的 pixel 標記成 -1, 清掉背景
    // 檢查四個邊, 如都沒白的, 代表只有一個古文字
    // 有可能該處被黑包圍導致 dfs中斷, 必須檢查四個邊
    for (i = 1; i <= W; i++)
    {
        if (!image[1][i])
            dfs_init_image(1, i);
        if (!image[H][i])
            dfs_init_image(H, i);
    }

    for (i = 1; i <= H; i++)
    {
        if (!image[i][1])
            dfs_init_image(i, 1);
        if (!image[i][W])
            dfs_init_image(i, W);
    }
}
void dfs_init_image(int r, int c)
{
    stack<node> s;
    s.push(make_pair(r, c));

    while (!s.empty())
    {
        node next = s.top();
        s.pop();

        r = next.first;
        c = next.second;

        if (visit[r][c])
            continue;

        // (WHITE not in word) -> NONE
        image[r][c] = NONE; // 與古文字無關的pixel
        visit[r][c] = true;

        for (int i = 0; i < 4; i++)
        {
            int rr = r + dir_x[i], cc = c + dir_y[i];

            if (in_border(rr, cc) && !image[rr][cc])
                s.push(std::make_pair(rr, cc));
        }
    }
}
void dfs_scan_lang(int r, int c)
{

    bool white_flag = true;
    stack<node> s;
    s.push(make_pair(r, c));

    while (!s.empty())
    {
        node next = s.top();
        s.pop();

        r = next.first;
        c = next.second;

        if (visit[r][c])
            continue;

        visit[r][c] = true;

        if (image[r][c] == BLACK)
        {
            if (!white_flag)
                white_flag = true;

            for (int i = 0; i < 4; i++)
            {
                int rr = r + dir_x[i], cc = c + dir_y[i];
                if (in_border(rr, cc) && !visit[rr][cc])
                    s.push(std::make_pair(rr, cc));
            }
        }
        else if (image[r][c] == WHITE)
        {
            if (white_flag)
            {
                white_count++;
                white_flag = false;
            }

            for (int i = 0; i < 4; i++)
            {
                // 遇到白的就先把該封閉區都掃過一次
                int rr = r + dir_x[i], cc = c + dir_y[i];
                if (in_border(rr, cc) && image[rr][cc] == WHITE && !visit[rr][cc])
                    s.push(std::make_pair(rr, cc));
            }
        }
    }
}
