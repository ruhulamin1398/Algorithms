#include<stdio.h>
int mark[1000000]= {0}, Prime[100000], Pt = 0;
void Sieve()
{
    int i, j;
    for(i = 3; i < 1000000; i += 2)
    {
        if(mark[i] == 0)
        {
            Prime[Pt++] = i;
            for(j = 3; i*j < 1000000; j += 2)
                mark[i*j] = 1;
        }
    }
}
int main()
{
    int n, i;
    Sieve();
    while(scanf("%d", &n) == 1 && n)
    {
        int x, y,cnt=0;
        for(i = 0; i < Pt; i++)
        {
            x = Prime[i], y = n-Prime[i];
            if(x > y)
                break;
            if(mark[x] == 0 && mark[y] == 0)
            cnt++;
        }
            printf("Way of Goldbach`s Conjecture for n: %d\n",cnt);
    }
    return 0;
}
/**
6
Way of Goldbach`s Conjecture for n: 1
42
Way of Goldbach`s Conjecture for n: 4
100000
Way of Goldbach`s Conjecture for n: 810
**/

