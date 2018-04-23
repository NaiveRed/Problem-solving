#include <cstdio>
#include <unordered_map>
#include <string>
using std::string;

int main()
{
    /*
    C[i]: 第 i 維每單位位移時的 byte 差
    C[0] 跟題目公式不同

    e.g. [d1,d2,d3]
    [x,5,x] - [x,4,x] = C[i]
    [x,x,1] - [x,x,0] = element size of data(bytes)
        
    e.g.
    TWO 2000 4 3 1 4 0 5 5 10
    TWO base = 2000 size = 4 D = 3
    D0=(1, 4), D1=(0, 5), D2=(5, 10)
    Di = (Di_L, Di_U)
    
    C[2] = size = 4
    C[1] = C[2] * (10-5+1) = 24
    C[0] = C[1] * (5-0+1) = 144

    TWO[3, 3, 9] = base + (3-D0_L)*C[0] + (3-D1_L)*C[1] + (9-D2_L)*C[2]
    = 2000 + (3-1)*144 + (3-0)*24 + (9-5)*4 = 2376
    */
    struct data
    {
        int base, size, D;
        int L[10], R[10]; //(L[i], R[i]): lower_bound and upper bound

        int C[10];

        data() {}
        data(int _base, int _size, int _D) : base(_base), size(_size), D(_D)
        {
            for (int i = 0; i < D; ++i)
                scanf("%d%d", &L[i], &R[i]);

            C[D - 1] = size; //last dim.
            for (int i = D - 2; i >= 0; --i)
                C[i] = C[i + 1] * (R[i + 1] - L[i + 1] + 1);
        }
    };

    std::unordered_map<string, data> M;

    int N, R;
    char name[15];
    scanf("%d%d", &N, &R);
    for (int i = 0; i < N; ++i)
    {
        int base, size, d;
        getchar();
        scanf("%s%d%d%d", name, &base, &size, &d);
        M[string(name)] = (data){base, size, d};
    }

    for (int i = 0; i < R; ++i)
    {
        getchar();
        scanf("%s", name);
        printf("%s[", name);
        data &d = M[string(name)];

        int addr = d.base, tmp;
        for (int i = 0; i < d.D; ++i)
        {
            scanf("%d", &tmp);
            addr += (tmp - d.L[i]) * d.C[i];

            if (i)
                printf(", %d", tmp);
            else
                printf("%d", tmp);
        }

        printf("] = %d\n", addr);
    }

    return 0;
}
/*
1 14
ONE       1500 2 2 0 3 1 5
ONE       0 1
ONE       0 2
ONE       0 3
ONE       0 4
ONE       0 5
ONE       1 1
ONE       1 2
ONE       1 3
ONE       1 4
ONE       1 5
ONE       2 1
ONE       2 2
ONE       2 3
ONE       2 4

ONE[0, 1] = 1500
ONE[0, 2] = 1502
ONE[0, 3] = 1504
ONE[0, 4] = 1506
ONE[0, 5] = 1508
ONE[1, 1] = 1510
ONE[1, 2] = 1512
ONE[1, 3] = 1514
ONE[1, 4] = 1516
ONE[1, 5] = 1518
ONE[2, 1] = 1520
ONE[2, 2] = 1522
ONE[2, 3] = 1524
ONE[2, 4] = 1526
*/