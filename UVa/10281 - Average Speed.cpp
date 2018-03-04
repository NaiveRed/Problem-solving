#include <cstdio>

int main()
{ 
    char input[30];
    double kms, dis = 0;
    int now = 0;
    int h, m, s, kmh;
    while (fgets(input, 30, stdin))
    {
        int in = sscanf(input, "%d:%d:%d%d", &h, &m, &s, &kmh);
        int tmp = (h * 3600 + m * 60 + s);
        dis += (tmp - now) * kms;
        now = tmp;

        if (in == 4)        
            kms = (double)kmh / 3600; //km/sec                    
        else
            printf("%02d:%02d:%02d %.2lf km\n", h, m, s, dis);
    }
    return 0;
}