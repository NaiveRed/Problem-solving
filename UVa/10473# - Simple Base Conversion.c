#include<stdio.h>
#include<stdlib.h>

int main(){

    char num[20];
    while (gets(num) && num[0] != '-')
    {
        if (num[0] == '0'&&num[1] == 'x')
            printf("%ld\n", strtol(num + 2, NULL, 16));
        else printf("0x%X\n", atoi(num));

    }
    return 0;
}
