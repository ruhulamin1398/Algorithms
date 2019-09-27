#include<stdio.h>
#include<string.h>
int main()
{
    char s[201];
    int Sum[201] = {0}, i, j, length;
    while(gets(s))
    {
        if(!strcmp(s, "0"))
            break;
        length = strlen(s);
        for(i = 0, j = length-1; i < length; i++, j--)
            Sum[i] += s[j] - '0';
    }
    for(i = 0; i < 200; i++)
    {
        Sum[i+1] += Sum[i]/10;
        Sum[i] %= 10;
    }
    i = 200;
    while(Sum[i] == 0 && i >= 0) i--;
    for(; i >= 0; i--)
        printf("%d", Sum[i]);
}
/**
input :
123456789012345678901234567890
123456789012345678901234567890
123456789012345678901234567890
0

output :
370370367037037036703703703670
**/
