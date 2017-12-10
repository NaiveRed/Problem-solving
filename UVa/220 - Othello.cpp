#include <cstdio>
#define SIZE 8
#define UNK 0
#define BLACK 1
#define WHITE 2
#define OPPONENT(x) (3 - (x))

// 8 個方向，左上角開始順時針
const int DirX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int DirY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int board[SIZE][SIZE];
int legal_move_index[50][2];

void show_board();
void show_result();
bool in_board(int r, int c);
int find_legal_move(int turn);
bool check_cross(int r, int c, bool update);
bool check_straight_army(int r, int c, int d, bool update);
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);

    while (T--)
    {
        getchar();
        char c;
        int turn; // 1:black, 2:white

        //Board set
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
                if ((c = getchar()) == 'W')
                    board[i][j] = WHITE;
                else if (c == 'B')
                    board[i][j] = BLACK;
                else
                    board[i][j] = UNK;
            getchar();
        }
        turn = getchar() == 'W' ? WHITE : BLACK;
        getchar();

        //Command
        while ((c = getchar()) != 'Q')
        {
            if (c == 'L')
            {
                int count = find_legal_move(turn);
                if (!count)
                    puts("No legal move.");
                else
                {
                    for (int i = 1; i < count; i++)
                        printf("(%d,%d) ", legal_move_index[i][0] + 1, legal_move_index[i][1] + 1);
                    printf("(%d,%d)\n", legal_move_index[count][0] + 1, legal_move_index[count][1] + 1);
                }
            }
            else
            {
                int row = getchar() - '0' - 1;
                int col = getchar() - '0' - 1;
                //printf("%d %d\n", row, col);
                if (!find_legal_move(turn))
                    turn = OPPONENT(turn);
                board[row][col] = turn;

                //play a move
                check_cross(row, col, true);
                show_result();

                turn = OPPONENT(turn); //換下一玩家
            }
            getchar();
        }

        show_board();
        if (T)
            putchar('\n');
    }

    return 0;
}
inline void show_board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == WHITE)
                putchar('W');
            else if (board[i][j] == BLACK)
                putchar('B');
            else
                putchar('-');

        putchar('\n');
    }
}
inline void show_result()
{
    int w = 0, b = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == WHITE)
                w++;
            else if (board[i][j] == BLACK)
                b++;

    printf("Black - %2d White - %2d\n", b, w);
}
inline bool in_board(int r, int c)
{
    return (r >= 0 && r < 8 && c >= 0 && c < 8);
}
int find_legal_move(int turn)
{
    legal_move_index[0][0] = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (!board[i][j])
            {
                board[i][j] = turn;
                if (check_cross(i, j, false))
                {
                    legal_move_index[0][0]++;
                    legal_move_index[legal_move_index[0][0]][0] = i;
                    legal_move_index[legal_move_index[0][0]][1] = j;
                }
                board[i][j] = UNK;
            }

    return legal_move_index[0][0];
}
bool check_cross(int r, int c, bool update)
{
    // update: 是否立刻更新棋盤

    if (!in_board(r, c))
        return false;

    int army = OPPONENT(board[r][c]);
    bool have_army = false;

    for (int k = 0; k < 8; k++) //8 個方向
    {
        int dx = r + DirX[k];
        int dy = c + DirY[k];
        if (in_board(dx, dy) && board[dx][dy] == army)
            have_army |= check_straight_army(r, c, k, update);
    }

    return have_army;
}
bool check_straight_army(int r, int c, int d, bool update)
{
    int me = board[r][c];
    int army = OPPONENT(me);
    bool have_army = false;          //有敵方的
    bool have_me = false;            //對面有自己的
    bool flag[SIZE][SIZE] = {false}; //會被更動到的

    int tx = r + DirX[d], ty = c + DirY[d];

    while (in_board(tx, ty))
    {
        if (board[tx][ty] == army)
        {
            have_army = true;
            flag[tx][ty] = true;
        }
        else if (board[tx][ty] == me)
        {
            have_me = true;
            break;
        }
        else
            break;

        tx += DirX[d];
        ty += DirY[d];
    }

    if (have_me && have_army)
    {
        if (update)
        {
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    if (flag[i][j])
                        board[i][j] = me;
        }

        return true;
    }
    else
        return false;
}