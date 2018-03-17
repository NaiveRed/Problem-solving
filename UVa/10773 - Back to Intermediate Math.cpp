#include <cstdio>
#include <cmath>

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        double d, v, u, vv, uu; //v: river, u:boat

        scanf("%lf%lf%lf", &d, &v, &u);
        vv = v * v;
        uu = u * u;
        //find different paths, v = 0 時，最快和最短是同一條        
        if (!vv || uu <= vv)
            printf("Case %d: can't determine\n", t);
        else
        {
            /*
            fastest: d/u
              u
              --->
            v ^
              |

            shortest: d/ sqrt(uu-vv)              
            v ^
              |
              --->
            sqrt(uu-vv)
            */
            double fastest = d / u, shortest = d / sqrt(uu - vv);
            printf("Case %d: %.3lf\n", t, shortest - fastest);
        }
    }

    return 0;
}