#include <cstdio>
#include <stack>
#define N 26
using namespace std;

struct Matrix
{
    int r, c;
    Matrix() : r(0), c(0) {}
    Matrix(int rr, int cc) : r(rr), c(cc) {}
    int get_num(Matrix &a) //乘法數量
    {
        if (c != a.r) //error
            return 0;
        return r * c * a.c;
    }
    Matrix get_res(Matrix &a) //相乘結果
    {
        return Matrix(r, a.c);
    }
} m[N];

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        char name;
        int row, col;
        getchar();
        scanf("%c%d%d", &name, &row, &col);
        m[name - 'A'] = (Matrix){row, col};
    }

    getchar();
    char str[100];
    while (fgets(str, 100, stdin))
    {
        Matrix R, L;
        int sum = 0;
        bool err = false;
        stack<Matrix> s;
        for (int i = 0; str[i] != '\n' && !err; ++i)
        {
            if (str[i] == '(') //用 0*0 來表示 '('
                s.emplace(0, 0);
            else if (str[i] == ')')
            {
                R = s.top();
                s.pop();
                if (R.r)
                {
                    while (true)
                    {
                        L = s.top();
                        s.pop();
                        if (!L.r)
                            break;

                        int tmp = L.get_num(R);
                        if (tmp)
                        {
                            R = L.get_res(R); //L*R
                            sum += tmp;
                        }
                        else
                        {
                            err = true;
                            break;
                        }
                    }
                }
                s.push(R); //拆完一對括號，最後乘完的結果
            }
            else
                s.push(m[str[i] - 'A']);
        }

        while (!err && s.size() > 1) //剩下的矩陣
        {
            R = s.top();
            s.pop();
            L = s.top();
            s.pop();
            int tmp = L.get_num(R);
            if (tmp)
            {
                s.push(L.get_res(R)); //L*R
                sum += tmp;
            }
            else
            {
                err = true;
                break;
            }
        }
        if (err)
            puts("error");
        else
            printf("%d\n", sum);
    }

    return 0;
}