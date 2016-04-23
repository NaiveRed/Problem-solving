#include<cstdio>
typedef long long LL;
struct Matrix
{
    LL n[2][2];
    int mod;
    
    //邊做矩陣乘法邊 mod
    Matrix operator*(Matrix& a)
    {
        Matrix t;
        t.n[0][0] = (n[0][0] * a.n[0][0] + n[0][1] * a.n[1][0]) % mod;
        t.n[0][1] = (n[0][0] * a.n[1][0] + n[0][1] * a.n[1][1]) % mod;
        t.n[1][0] = (n[1][0] * a.n[0][0] + n[1][1] * a.n[1][0]) % mod;
        t.n[1][1] = (n[1][0] * a.n[0][1] + n[1][1] * a.n[1][1]) % mod;
        t.mod = mod;
        return t;
    }

    //快速冪
    Matrix operator^(int x)
    {
        Matrix M, A;
        M.n[0][1] = 0, M.n[1][0] = 0;
        M.n[0][0] = 1, M.n[1][1] = 1;
        M.mod = mod;
        if (!x)return M;
        if (x == 1) return *this*M;
        A = *this;
        for (; x; x >>= 1, A = A * A)
            if (x & 1)
                M = M * A;

        return M;
    }

    Matrix operator=(Matrix m)
    {
        mod = m.mod;
        n[0][0] = m.n[0][0];
        n[0][1] = m.n[0][1];
        n[1][0] = m.n[1][0];
        n[1][1] = m.n[1][1];
        return *this;
    }
};
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        Matrix M;
        M.n[0][0] = 1;
        M.n[0][1] = 1;
        M.n[1][0] = 1;
        M.n[1][1] = 0;
        M.mod = 1 << m;

        printf("%d\n", (M ^ (n)).n[0][1]);
    }

    return 0;
}
