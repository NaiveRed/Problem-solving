#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int n, m, H[900], Case = 1;
    while (scanf("%d%d", &n, &m) && n)
    {
        int i;
        n *= m;
        for (i = 0; i < n; i++)
            scanf("%d", &H[i]);

        double h, sum = 0, V;
        scanf("%lf", &V);
        sort(H, H + n);

        H[n] = INT_MAX;
        
        //V = [ (h - H[0]) + (h - H[1]) + ... + (h - H[i]) ] * 10^2
        V /= 100;
        for (i = 0; i < n; i++)
        {
            sum += H[i];
            h = (V + sum) / (i + 1);
            if (h < H[i + 1])
                break;
        }

        printf("Region %d\n", Case++);
        printf("Water level is %.2lf meters.\n", h);
        printf("%.2lf percent of the region is under water.\n\n", (double)100 * (i + 1) / n);
    }

    return 0;
}